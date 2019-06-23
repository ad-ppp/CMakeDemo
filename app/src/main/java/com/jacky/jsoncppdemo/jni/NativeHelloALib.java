package com.jacky.jsoncppdemo.jni;

public class NativeHelloALib {
    static {
        System.loadLibrary("native_test");
    }

    public static native int intFromHelloA(int i);
}
