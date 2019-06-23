package com.jacky.jsoncppdemo

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import com.jacky.jsoncppdemo.jni.NativeHelloALib
import com.jacky.jsoncppdemo.jni.NativeHelloSoLib
import com.jacky.jsoncppdemo.jni.NativeJsonSoLib
import com.jacky.jsoncppdemo.jni.NativeLib
import kotlinx.android.synthetic.main.activity_main.*
import org.json.JSONObject

class MainActivity : AppCompatActivity() {
    companion object {
        const val TAG = "MainActivity"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // new project
        tvNativeContent.text = getContent()
    }

    private fun getContent(): String {
        // simply to get message from native
        val stringFromNativeLib = NativeLib.stringFromNativeLib()

        // JsonCpp-Lib. Return java Class from native [People]
        val jsonObject = JSONObject()
        jsonObject.put("name", "jacky")
        jsonObject.put("age", 18)
        jsonObject.put("gender", "male")
        jsonObject.put("school", "NT UNIVERSITY")
        val json = jsonObject.toString()

        val people = NativeJsonSoLib.parseJsonCode(json)
        val outputJsonCode = NativeJsonSoLib.outputJsonCode("jack", 10, "male", "ND")

        // link simple a method
        val intFromHelloA = NativeHelloALib.intFromHelloA(1)
        val intFromHelloSo = NativeHelloSoLib.intFromHelloSo(1)

        return """
            [nativeLib:$stringFromNativeLib]
            {
                jsoncppSo,
                [people:$people]
                [json:$outputJsonCode]
            }
            {helloA:[i: 1,o: $intFromHelloA]}
            {helloSo:[i: 1,o: $intFromHelloSo]}
        """
    }
}
