#include <jni.h>
#include <string>
#include <android/log.h>


#define HACKER_TAG            "crash_tag"
#define LOG(fmt, ...)  __android_log_print(ANDROID_LOG_INFO, HACKER_TAG, fmt, ##__VA_ARGS__)
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkcrashdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = nullptr;
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkcrashdemo_MainActivity_HeapBufferOverflow(JNIEnv *env, jclass clazz) {
    int *arr = new int[1024];
    arr[0] = 11;
    arr[1024] = 12;
    LOG("HeapBufferOverflow arr[0]=%d, arr[1024]", arr[0], arr[1024]);
}