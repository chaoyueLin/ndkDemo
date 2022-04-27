package com.example.ndkdemo;

import android.graphics.Bitmap;

/*****************************************************************
 * * File: - BitmapOps
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/10/9
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/10/9    1.0         create
 ******************************************************************/
public class BitmapOps {
    // 顺时针旋转 90° 的操作
    public native Bitmap rotateBitmap(Bitmap bitmap);

    public native Bitmap convertBitmap(Bitmap bitmap);

    public native Bitmap mirrorBitmap(Bitmap bitmap);


    public void invoke() {
    }
}
