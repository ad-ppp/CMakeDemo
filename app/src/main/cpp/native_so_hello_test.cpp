//
// Created by 杨剑飞 on 2019-06-23.
//


//
// Created by 杨剑飞 on 2019-06-21.
//

#include <jni.h>
#include "sohello.h"

extern "C" JNIEXPORT
jint JNICALL
Java_com_jacky_jsoncppdemo_jni_NativeHelloSoLib_intFromHelloSo(JNIEnv *env, jclass type,
                                                             jint i) {
    return sohello(i);
}
