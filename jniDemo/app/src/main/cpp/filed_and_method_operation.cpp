#include <jni.h>
#include "logutil.h"

//
// Created by  on 2020/10/9.
//

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_FieldAndMethodOperation_accessInstanceFiled(JNIEnv
* env,
                                                                     jobject thiz, jobject
animal) {
    jfieldID fid; // 想要获取的字段 id
    jstring jstr; // 字段对应的具体的值
    const char *str; // 将 Java 的字符串转换为 Native 的字符串
    jclass cls = env->GetObjectClass(animal); // 获取 Java 对象的类
    fid = env->GetFieldID(cls, "name", "Ljava/lang/String;"); // 获取对应字段的 id
    if (fid == NULL) { // 如果字段为 NULL ，直接退出，查找失败
        return;
    }
    jstr = (jstring) env->GetObjectField(animal, fid); // 获取字段对应的值
    str = env->GetStringUTFChars(jstr, NULL);
    if (str == NULL) {
        return;
    }
    LOGD("name is %s", str);
    env->ReleaseStringUTFChars(jstr, str);
    jstr = env->NewStringUTF("replaced name");
    if (jstr == NULL) {
        return;
    }
    env->SetObjectField(animal, fid, jstr); // 修改字段对应的值
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_FieldAndMethodOperation_accessStaticField(JNIEnv
* env,
                                                                   jobject thiz, jobject
animal) {
    jfieldID fid;
    jint num;
    jclass cls = env->GetObjectClass(animal);
    fid = env->GetStaticFieldID(cls, "num", "I");
    if (fid == NULL) {
        return;
    }
    num = env->GetStaticIntField(cls, fid);
    LOGD("get static field num is %d", num);
    env->SetStaticIntField(cls, fid, ++num);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_FieldAndMethodOperation_callInstanceMethod(JNIEnv
* env,
                                                                    jobject thiz, jobject
animal) {
    jclass cls = env->GetObjectClass(animal); // 获得具体的类
    jmethodID mid = env->GetMethodID(cls, "callInstanceMethod", "(I)V"); // 获得具体的方法 id
    if (mid == NULL) {
        return;
    }
    env->CallVoidMethod(animal, mid, 2); // 调用方法
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_FieldAndMethodOperation_callStaticMethod(JNIEnv
* env,
                                                                  jobject thiz, jobject
animal) {
    jclass cls = env->GetObjectClass(animal);
    jmethodID argsmid = env->GetStaticMethodID(cls, "callStaticMethod",
                                               "(Ljava/lang/String;)Ljava/lang/String;");
    if (argsmid == NULL) {
        return;
    }
    jstring jstr = env->NewStringUTF("jstring");
    env->CallStaticObjectMethod(cls, argsmid, jstr);
}