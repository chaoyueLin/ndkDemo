package com.example.ndkfiledemo;

import android.app.Application;

/*****************************************************************
 * * File: - App
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/9/29
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/9/29    1.0         create
 ******************************************************************/
public class App extends Application {
    private static Application mContext;

    @Override
    public void onCreate() {
        super.onCreate();
        mContext=this;
    }

    public static Application getContext() {
        return mContext;
    }
}
