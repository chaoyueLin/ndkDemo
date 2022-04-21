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


extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_ndkcrashdemo_MainActivity_getStrings(JNIEnv *env, jobject thiz, jint count,
                                                      jstring sample) {
    jobjectArray str_array = NULL;
    jclass cls_string = NULL;
    jmethodID mid_string_init;
    jobject obj_str = NULL;
    const char *c_str_sample = NULL;
    char buff[256];
    int i;

    //保证至少可以穿件3个局部引用（str_array,class_string,obj_str）
    if (env->EnsureLocalCapacity(3) != JNI_OK) {
        return NULL;
    }
    c_str_sample = env->GetStringUTFChars(sample, NULL);
    if (c_str_sample == NULL) {
        return NULL;
    }
    cls_string = env->FindClass("java/lang/String");
    if (cls_string == NULL) {
        return NULL;
    }

    mid_string_init = env->GetMethodID(cls_string, "<init>", "()V");
    if (mid_string_init == NULL) {
        env->DeleteLocalRef(cls_string);
        return NULL;
    }

    obj_str = env->NewObject(cls_string, mid_string_init);
    if (obj_str == NULL) {
        env->DeleteLocalRef(cls_string);
        return NULL;
    }

    str_array = env->NewObjectArray(count, cls_string, obj_str);
    if (str_array == NULL) {
        env->DeleteLocalRef(cls_string);
        env->DeleteLocalRef(obj_str);
        return NULL;
    }

    for (i = 0; i < count; ++i) {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, c_str_sample, i);
        jstring newStr = env->NewStringUTF(buff);
        env->SetObjectArrayElement(str_array, i, newStr);
        env->DeleteLocalRef(newStr);   // Warning: 这里如果不手动释放局部引用，很有可能造成局部引用表溢出
    }

    env->ReleaseStringUTFChars(sample, c_str_sample);

    env->DeleteLocalRef(cls_string);
    env->DeleteLocalRef(obj_str);
    return str_array;
}