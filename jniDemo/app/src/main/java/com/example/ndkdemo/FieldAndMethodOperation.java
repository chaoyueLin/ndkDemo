package com.example.ndkdemo;

/*****************************************************************
 * * File: - FieldAndMethodOps
 * * Description: 
 * * Version: 1.0
 * * Date : 2020/10/9
 * * Author: linchaoyue
 * *
 * * ---------------------- Revision History:----------------------
 * * <author>   <date>     <version>     <desc>
 * * linchaoyue 2020/10/9    1.0         create
 ******************************************************************/
public class FieldAndMethodOperation {
    public void invoke() {

    }

    private native void accessInstanceFiled(Animal animal);

    private native void accessStaticField(Animal animal);


    private native void callInstanceMethod(Animal animal);

    private native void callStaticMethod(Animal animal);
}
