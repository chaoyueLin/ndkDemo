//
// Created by 80289193 on 2020/10/26.
//
#include <jni.h>
#include "logutil.h"
#include <pthread.h>


#ifndef NDKDEMO_THREAD_OPERATION_H
#define NDKDEMO_THREAD_OPERATION_H

struct ThreadRunArgs {
    jint id;
    jint result;
};

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ThreadOps_nativeInit(JNIEnv
* env,
jobject thiz
);

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ThreadOps_nativeFree(JNIEnv
* env,
jobject thiz
);

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ThreadOps_createNativeThread(JNIEnv
* env,
jobject thiz
);

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ThreadOps_posixThreads(JNIEnv
* env,
jobject thiz, jint
threads,
jint iterations
);
#endif //NDKDEMO_THREAD_OPERATION_H
