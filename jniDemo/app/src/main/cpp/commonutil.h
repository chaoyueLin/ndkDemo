//
// Created by  on 2020/10/26.
//
#include <jni.h>
#ifndef NDKDEMO_COMMONUTIL_H
#define NDKDEMO_COMMONUTIL_H

static const char *IOException = "java/io/IOException";
static const char *RuntimeException = "java/io/RuntimeException";

void throwByName(JNIEnv *env, const char *name, const char *msg);
#endif //NDKDEMO_COMMONUTIL_H
