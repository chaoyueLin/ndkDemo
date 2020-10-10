#include <jni.h>
#include <string>
#include <android/log.h>

void move();

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" void
Java_com_example_ndkdemo_MainActivity_exceptionTest(
        JNIEnv
        *env,
        jobject /* this */) {
    __android_log_print(ANDROID_LOG_INFO,
                        "JNITag", "start jni func exceptionTest");
    jclass newExcCls;
    newExcCls = env->FindClass("java/lang/IllegalArgumentException");
    if (newExcCls == NULL) {
        /* Unable to find the exception class, give up. */
        __android_log_print(ANDROID_LOG_INFO,
                            "JNITag", "jni return");
        return;
    }
    env->
            ThrowNew(newExcCls,
                     "***** thrown new exception from C code *****");

    return;

}

void add() {
    move();
}

void move() {
    int *p = 0;
    *p = 1;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_ndkdemo_MainActivity_exceptionNotCatchTest(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_INFO,
                        "JNITag", "start jni func exceptionNotCatchTest");
    add();

    __android_log_print(ANDROID_LOG_INFO,
                        "JNITag", "start jni func exceptionNotCatchTest2");
    return JNI_VERSION_1_6;
}