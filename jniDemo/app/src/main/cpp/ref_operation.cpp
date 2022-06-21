#include <jni.h>
#include "logutil.h"
#include <string>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_RefOperaton_getStrings(JNIEnv *env, jobject thiz) {
    char data[] = "daffdasf";
    int i = 0;
    for (i = 0; i < 500; i++) {
        LOGD("before:%d", i);
        jstring content = env->NewStringUTF(data);
        env->DeleteLocalRef(content);
        LOGD("after:%d", i);
    }
}
