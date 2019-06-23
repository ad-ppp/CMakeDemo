package com.jacky.jsoncppdemo.jni;

import com.jacky.jsoncppdemo.module.People;

public class NativeJsonSoLib {
    static {
        System.loadLibrary("native_test");
    }

    public static native String outputJsonCode(String name, int age, String gender, String school);

    public static native People parseJsonCode(String json_str);
}
