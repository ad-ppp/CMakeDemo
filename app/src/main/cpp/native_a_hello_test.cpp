//
// Created by 杨剑飞 on 2019-06-21.
//

#include <jni.h>
#include "ahello.h"

extern "C" JNIEXPORT
jint JNICALL
Java_com_jacky_jsoncppdemo_jni_NativeHelloALib_intFromHelloA(JNIEnv *env, jclass type,
                                                             jint i) {
    return ahello(i);
}