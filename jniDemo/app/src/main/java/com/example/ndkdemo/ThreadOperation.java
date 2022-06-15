package com.example.ndkdemo;

import android.util.Log;

/*****************************************************************
 * * File: - ThreadOps
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/10/26
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/10/26    1.0         create
 ******************************************************************/
public class ThreadOperation {
    private static final String TAG = "ThreadOps";

    public void invoke() {

        createNativeThread();
        nativeInit();
        posixThreads(3, 3);
    }

    private native void createNativeThread();

    private native void nativeInit();

    private native void nativeFree();

    private native void posixThreads(int threads, int iterations);

    /**
     * 打印线程名称，并且模拟耗时任务
     */
    private void printThreadName() {
        Log.d(TAG, "print thread name current thread name is " + Thread.currentThread().getName());
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    /**
     * Native 回到到 Java 的方法，打印当前线程名字
     *
     * @param msg
     */
    private void printNativeMsg(String msg) {
        Log.d(TAG, "native msg is " + msg);
        Log.d(TAG, "print native msg current thread name is " + Thread.currentThread().getName());
    }
}
