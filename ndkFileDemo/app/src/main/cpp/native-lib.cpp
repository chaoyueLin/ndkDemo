#include <jni.h>
#include <string>
#include "log.h"

const char *PASSWORD = "pw";

long getFileSize(char *filePath);

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkfiledemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_ndkfiledemo_FileUtils_fileEncrypt(JNIEnv *env, jclass clazz,
                                                   jstring normal_file_path,
                                                   jstring encrypt_file_path) {
    const char *normalFilePath = env->GetStringUTFChars(normal_file_path, 0);
    const char *encryptFilePath = env->GetStringUTFChars(encrypt_file_path, 0);

    int passwordLen = strlen(PASSWORD);
    LOGE("要加密的文件的路径 = %s , 加密后的文件的路径 = %s", normalFilePath, encryptFilePath);

    //读文件指针
    FILE *frp = fopen(normalFilePath, "rb");
    //写文件指针
    FILE *fwp = fopen(encryptFilePath, "wb");

    if (frp == NULL) {
        LOGE("文件不存在");
        return JNI_FALSE;
    }
    if (fwp == NULL) {
        LOGE("没有写权限");
        return JNI_FALSE;
    }

    //边读边写边加密
    int buffer;
    int index = 0;
    while ((buffer = fgetc(frp)) != EOF) {
        //write
        fputc(buffer ^ *(PASSWORD + (index % passwordLen)), fwp);
        index++;
    }
    // 关闭文件流
    fclose(fwp);
    fclose(frp);

    LOGE("文件加密成功");

    env->ReleaseStringUTFChars(normal_file_path, normalFilePath);
    env->ReleaseStringUTFChars(encrypt_file_path, encryptFilePath);

    return JNI_TRUE;
}


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_ndkfiledemo_FileUtils_fileDecode(JNIEnv *env, jclass clazz,
                                                  jstring encrypt_file_path,
                                                  jstring decode_file_path) {
    const char *encryptFilePath = env->GetStringUTFChars(encrypt_file_path, 0);
    const char *decodeFilePath = env->GetStringUTFChars(decode_file_path, 0);

    int passwordLen = strlen(PASSWORD);
    // 打开文件
    FILE *frp = fopen(encryptFilePath, "rb");
    FILE *fwp = fopen(decodeFilePath, "wb");
    if (frp == NULL) {
        LOGE("文件不存在");
        return JNI_FALSE;
    }
    if (fwp == NULL) {
        LOGE("没有写权限");
        return JNI_FALSE;
    }
    // 读取文件
    int buffer;
    int index = 0;
    while ((buffer = fgetc(frp)) != EOF) {
        // 写文件
        fputc(buffer ^ *(PASSWORD + (index % passwordLen)), fwp);
        index++;
    }
    LOGE("文件解密成功");
    // 关闭流
    fclose(fwp);
    fclose(frp);

    env->ReleaseStringUTFChars(encrypt_file_path, encryptFilePath);
    env->ReleaseStringUTFChars(decode_file_path, decodeFilePath);
    return JNI_TRUE;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_ndkfiledemo_FileUtils_fileSplit(JNIEnv *env, jclass clazz, jstring split_file_path,
                                                 jstring suffix, jint file_num) {
    // TODO: implement fileSplit()
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_ndkfiledemo_FileUtils_fileMerge(JNIEnv *env, jclass clazz, jstring split_file_path,
                                                 jstring split_suffix, jstring merge_suffix,
                                                 jint file_num) {
    // TODO: implement fileMerge()
}

/*获取文件的大小*/
long getFileSize(char* filePath) {
    FILE* fp = fopen(filePath, "rb");
    if(fp == NULL) {
        LOGE("文件不存在，可能没有读文件的权限");
    }
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}