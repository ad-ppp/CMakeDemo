//
// Created by 杨剑飞 on 2019-06-12.
//

#include <jni.h>
#include "json/json.h"
#include <android/log.h>    // log

#define  LOG_TAG    "userCode"
#define  VLOG(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  ILOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  ELOG(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

void testJson(JNIEnv *env);

extern "C" JNIEXPORT
jstring JNICALL
Java_com_jacky_jsoncppdemo_jni_NativeJsonSoLib_outputJsonCode(JNIEnv *env, jclass thiz,
                                                              jstring jname, jint jage, jstring jgender,
                                                              jstring jschool) {
    Json::Value root;

    VLOG("test %s", env->GetStringUTFChars(env->NewStringUTF("nantong"), NULL));
    // test
    testJson(env);

    const char *name = env->GetStringUTFChars(jname, NULL);
    const char *gender = env->GetStringUTFChars(jgender, NULL);
    const char *school = env->GetStringUTFChars(jschool, NULL);
    root["name"] = name;
    root["age"] = jage;
    root["gender"] = gender;
    root["school"] = school;
    return env->NewStringUTF(root.toStyledString().c_str());
}

void testJson(JNIEnv *env) {
    Json::Value value;
    value["school"] = env->GetStringUTFChars(env->NewStringUTF("nantong"), NULL);
    value["name"] = env->GetStringUTFChars(env->NewStringUTF("jacky"), NULL);
    ILOG("value content: %s", value.toStyledString().c_str());
}

extern "C" JNIEXPORT
jobject JNICALL
Java_com_jacky_jsoncppdemo_jni_NativeJsonSoLib_parseJsonCode(JNIEnv *env, jclass thiz, jstring jjson) {
    const char *json_str = env->GetStringUTFChars(jjson, NULL);
    std::string out_str;

    Json::CharReaderBuilder b;
    Json::CharReader *reader(b.newCharReader());
    Json::Value root;
    JSONCPP_STRING errs;
    bool ok = reader->parse(json_str, json_str + std::strlen(json_str), &root, &errs);

    // find java class
    jclass const pJclass = env->FindClass("com/jacky/jsoncppdemo/module/People");
    jobject const people = env->NewObject(pJclass, env->GetMethodID(pJclass, "<init>", "()V"));
    jstring toStr = static_cast<jstring>(env->CallObjectMethod(people,
                                                               env->GetMethodID(pJclass, "toString",
                                                                                "()Ljava/lang/String;")));
    ILOG("people toString: %s", env->GetStringUTFChars(toStr, NULL));

    if (ok && errs.size() == 0) {
        jstring const name = env->NewStringUTF(root["name"].asCString());
        jint const age = root["age"].asInt();
        jstring const gender = env->NewStringUTF(root["gender"].asCString());
        jstring const school = env->NewStringUTF(root["school"].asCString());
        env->CallVoidMethod(people, env->GetMethodID(pJclass, "setName", "(Ljava/lang/String;)V"), name);
        env->CallVoidMethod(people, env->GetMethodID(pJclass, "setAge", "(I)V"), age);
        env->CallVoidMethod(people, env->GetMethodID(pJclass, "setGender", "(Ljava/lang/String;)V"), gender);
        env->CallVoidMethod(people, env->GetMethodID(pJclass, "setSchool", "(Ljava/lang/String;)V"), school);
    }
    return people;
}