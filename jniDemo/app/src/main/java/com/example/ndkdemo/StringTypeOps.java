package com.example.ndkdemo;

import android.util.Log;

/*****************************************************************
 * * File: - StringTypeOps
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/9/30
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/9/30    1.0         create
 ******************************************************************/
public class StringTypeOps {
    private static final String TAG = "StringTypeOps";

    static {
        System.loadLibrary("native-lib");
    }

    public void invoke() {
        String str = "hello";
        Log.d(TAG, getAndReleaseString(str));
        Log.d(TAG, reverseString(str));
        Log.d(TAG, getHalfString(str));
    }

    // Java 和 Native 字符串的相互转化
    private native String getAndReleaseString(String str);

    // 反转字符串操作
    private native String reverseString(String str);

    // 获得字符串一半内容
    private native String getHalfString(String str);
}
