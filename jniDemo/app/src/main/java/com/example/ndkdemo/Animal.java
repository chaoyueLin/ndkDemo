package com.example.ndkdemo;

import android.util.Log;

/*****************************************************************
 * * File: - Animal
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/9/30
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/9/30    1.0         create
 ******************************************************************/
public class Animal {

    private static final String TAG = "Animal";
    protected String name;

    public static int num = 0;

    public Animal(String name) {
        this.name = name;
    }


    public String getName() {
        Log.d(TAG, "call getName method");
        return this.name;
    }

    public int getNum() {
        return num;
    }

    // C++ 调用 Java 的实例方法
    public void callInstanceMethod(int num) {
        Log.d(TAG, "call instance method and num is " + num);
    }

    // C++ 调用 Java 的类方法
    public static String callStaticMethod(String str) {

        if (str != null) {
            Log.d(TAG, "call static method with " + str);
        } else {
            Log.d(TAG, "call static method str is null");
        }
        return "";
    }

    public static String callStaticMethod(String[] strs, int num) {
        Log.d(TAG, "call static method with string array");
        if (strs != null) {
            for (String str : strs) {
                Log.d(TAG, "str in array is " + str);
            }
        }
        return "";
    }

    public static void callStaticVoidMethod() {
        Log.d(TAG, "call static void method");
    }
}
