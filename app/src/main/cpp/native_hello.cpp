//
// Created by 杨剑飞 on 2019-06-11.
//

#include <jni.h>
#include <string>

# define JACKYFUNC(name)Java_com_jacky_jsoncppdemo_jni##name

extern "C" JNIEXPORT
jstring JNICALL
Java_com_jacky_jsoncppdemo_jni_NativeLib_stringFromNativeLib(JNIEnv *env, jclass type) {
    std::string str = "hello from native_lib";
    // 思考下：
    // 为啥不是构建一个string然后调用env->NewStringUTF(str.c_str())
    // 而是直接env->NewStringUTF("hello from native_lib")
    // Android Studio 创建C++项目时是上面那种方式，然后…我就被上个老大教育了一下…
    return env->NewStringUTF("hello from native_lib");
//    return env->NewStringUTF(str.c_str());
}