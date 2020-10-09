package com.example.ndksodemo;

import android.app.Application;
import android.content.Context;

/*****************************************************************
 * * File: - APP
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/10/9
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/10/9    1.0         create
 ******************************************************************/
public class APP extends Application {
    public static Context mContext;

    @Override
    public void onCreate() {
        super.onCreate();
        mContext=this;
    }
}
