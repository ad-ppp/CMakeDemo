package com.jacky.jsoncppdemo.jni;

public class NativeHelloSoLib {
    static {
        System.loadLibrary("native_test");
    }

    public static native int intFromHelloSo(int i);
}
