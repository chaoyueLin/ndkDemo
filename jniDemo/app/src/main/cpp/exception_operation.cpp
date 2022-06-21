#include <jni.h>
#include "logutil.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ExceptionOperation_errorInNative(JNIEnv *env, jobject thiz) {

    jclass j_class = env->GetObjectClass(thiz);
    //这行代码会报错!!!
    jfieldID j_id = env->GetFieldID(j_class, "name", "Ljava/lang/String;");
    //判断是否发生过异常
    jthrowable j_thr = env->ExceptionOccurred();
    if (j_thr) {
        LOGE("检测到异常");
//        env->ExceptionDescribe();
        //清除异常
        env->ExceptionClear();
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ExceptionOperation_errorInJava(JNIEnv *env, jobject thiz) {
    jthrowable exc = NULL;
    jclass cls = env->GetObjectClass(thiz);
    jmethodID mid = env->GetStaticMethodID(cls, "exceptionCallback", "()V");
    if (mid != NULL) {
        env->CallStaticVoidMethod(cls, mid);
    }
    //判断是否发生过异常
    jthrowable j_thr = env->ExceptionOccurred();
    if (j_thr) {
//        env->ExceptionDescribe();
        env->ExceptionClear();// 清除引发的异常，在Java层不会打印异常的堆栈信息
        env->ThrowNew(env->FindClass("java/lang/Exception"), "JNI抛出的异常！");
    }

}