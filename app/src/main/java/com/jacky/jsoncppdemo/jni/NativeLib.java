package com.jacky.jsoncppdemo.jni;

public class NativeLib {
    static {
        System.loadLibrary("native_test");
    }

    public static native String stringFromNativeLib();
}
