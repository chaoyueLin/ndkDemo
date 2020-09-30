#include <jni.h>
#include "logutil.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ArrayTypeOps_primitiveTypeArray(JNIEnv
                                                         *env,
                                                         jobject thiz, jintArray
                                                         int_array,
                                                         jfloatArray float_array, jdoubleArray
                                                         double_array,
                                                         jshortArray short_array, jlongArray
                                                         long_array,
                                                         jbooleanArray bool_array, jcharArray
                                                         char_array,
                                                         jbyteArray byte_array
) {
// TODO: implement primitiveTypeArray()
}

extern "C"
JNIEXPORT jint
JNICALL
Java_com_example_ndkdemo_ArrayTypeOps_intArraySum(JNIEnv *env, jobject thiz, jintArray intArray_,
                                                  jint num) {
    jint *intArray;
    int sum = 0;
    // 操作方法一：
    // 如同 getUTFString 一样，会申请 native 内存
    intArray = env->GetIntArrayElements(intArray_, NULL);

    if (intArray == NULL) {
        return 0;
    }

    // 得到数组的长度
    int length = env->GetArrayLength(intArray_);
    LOGD("array length is %d", length);

    for (int i = 0; i < length; ++i) {
        sum += intArray[i];
    }

    LOGD("sum is %d", sum);

    // 操作方法二：

    jint buf[num];

    env->GetIntArrayRegion(intArray_, 0, num, buf);

    sum = 0;
    for (int i = 0; i < num; ++i) {
        sum += buf[i];
    }

    LOGD("sum is %d", sum);

    // 使用完了别忘了释放内存
    env->ReleaseIntArrayElements(intArray_, intArray, 0);

    return sum;
}

extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_example_ndkdemo_ArrayTypeOps_getIntArray(JNIEnv *env, jobject thiz, jint num) {
// TODO: implement getIntArray()
}

extern "C"
JNIEXPORT jobjectArray
JNICALL
Java_com_example_ndkdemo_ArrayTypeOps_getTwoDimensionalArray(JNIEnv *env, jobject
thiz,
                                                             jint size
) {
// TODO: implement getTwoDimensionalArray()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_ArrayTypeOps_printAnimalsName(JNIEnv
                                                       *env,
                                                       jobject thiz, jobjectArray
                                                       animal) {
// TODO: implement printAnimalsName()
}