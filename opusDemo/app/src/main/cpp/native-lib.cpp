#include <jni.h>
#include <string>
#include "opus/include/opus.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_opusdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_opusdemo_JniClient_nativeCreateEncoder(JNIEnv *env, jobject thiz, jint sample_rate,
                                                        jint channel_config) {
    int err;
    opus_int32 skip = 0;
    OpusEncoder *pOpusEnc = opus_encoder_create(sample_rate, channel_config,
                                                OPUS_APPLICATION_RESTRICTED_LOWDELAY, &err);
    if (pOpusEnc) {
        opus_encoder_ctl(pOpusEnc, OPUS_SET_BITRATE(OPUS_AUTO));
        opus_encoder_ctl(pOpusEnc, OPUS_SET_COMPLEXITY(10));//8    0~10
        opus_encoder_ctl(pOpusEnc, OPUS_SET_SIGNAL(OPUS_SIGNAL_VOICE));
    }
    return (jlong) pOpusEnc;

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_opusdemo_JniClient_nativeEncode(JNIEnv *env, jobject thiz, jlong opus_encoder,
                                                 jbyteArray in, jbyteArray out) {
    OpusEncoder *pEnc = (OpusEncoder *) opus_encoder;
    if (!pEnc || !in || !out) {
        return 0;
    }
    jbyte *pIn = env->GetByteArrayElements(in, 0);
    jsize pInSize = env->GetArrayLength(in);
    jbyte *pOut = env->GetByteArrayElements(out, 0);
    jsize pOutSize = env->GetArrayLength(out);

    opus_int16 *pcm =(opus_int16 *)pIn;
    int frame_size = pInSize >> 1;
    unsigned char *data = (unsigned char *)pOut;
    opus_int32 max_data_bytes = pOutSize;
    int nRet = opus_encode(pEnc, pcm, frame_size, data, max_data_bytes);
    env->ReleaseByteArrayElements(in, pIn, 0);
    env->ReleaseByteArrayElements(out, pOut, 0);
    return nRet;

}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_opusdemo_JniClient_nativeDestroyEncoder(JNIEnv *env, jobject thiz,
                                                         jlong opus_encoder) {
    OpusEncoder *pEnc = (OpusEncoder *) opus_encoder;
    if (!pEnc)
        return;
    opus_encoder_destroy(pEnc);
}