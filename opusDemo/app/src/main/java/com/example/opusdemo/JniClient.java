package com.example.opusdemo;

public class JniClient {
    private static JniClient sInstance;

    private JniClient(){}

    public static JniClient getInstance() {
        if (sInstance == null) {
            sInstance = new JniClient();
        }
        return sInstance;
    }


    /**
     * 创建编码器
     *
     * @param sampleRate    音频的采样率
     * @param channelConfig 音频的声道数
     * @return 编码器的句柄
     */
    public long createEncoder(int sampleRate, int channelConfig) {
        return nativeCreateEncoder(sampleRate, channelConfig);
    }

    /**
     * 编码音频数据
     *
     * @param opusEncoder 编码器句柄
     * @param in          输入的PCM音频，按照OPUS的要求，音频的数据量应为2.5ms，5ms，10ms，20ms，40ms或者60ms。
     * @param out         输出的OPUS音频
     * @return 输出的数据量
     */
    public int encode(long opusEncoder, byte[] in, byte[] out) {
        return nativeEncode(opusEncoder, in, out);
    }

    /**
     * 销毁编码器
     *
     * @param opusEncoder 编码器句柄
     */
    public void destroyEncoder(long opusEncoder) {
        nativeDestroyEncoder(opusEncoder);
    }

    private native long nativeCreateEncoder(int sampleRate, int channelConfig);

    private native int nativeEncode(long opusEncoder, byte[] in, byte[] out);

    private native void nativeDestroyEncoder(long opusEncoder);
}
