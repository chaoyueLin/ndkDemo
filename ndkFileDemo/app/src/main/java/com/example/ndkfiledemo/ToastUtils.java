package com.example.ndkfiledemo;

import android.widget.Toast;

/*****************************************************************
 * * File: - ToastUtils
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/9/29
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/9/29    1.0         create
 ******************************************************************/
public class ToastUtils {
    public static void show(String text) {
        Toast.makeText(App.getContext(), text, Toast.LENGTH_SHORT).show();
    }

    public static void showLong(String text) {
        Toast.makeText(App.getContext(), text, Toast.LENGTH_LONG).show();
    }
}
