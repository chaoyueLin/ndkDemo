package com.example.ndkdemo;

public class ExceptionOperation {
    private static final String TAG = "ExceptionOperation";

    public void invoke() {
        errorInNative();
        try {
            errorInJava();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private native void errorInNative();

    private native void errorInJava();

    public static void exceptionCallback() {
        int a = 20 / 0;
        System.out.println("--->" + a);
    }

}
