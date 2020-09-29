package com.example.ndkfiledemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.File;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private Button btnEncrypt;
    private Button btnDecode;
    private Button btnSplit;
    private Button btnMerge;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        init();
    }

    private void init() {
        btnEncrypt = (Button) findViewById(R.id.btn_file_encrypt);
        btnDecode = (Button) findViewById(R.id.btn_file_decode);
        btnSplit = (Button) findViewById(R.id.btn_file_split);
        btnMerge = (Button) findViewById(R.id.btn_file_merge);

        btnEncrypt.setOnClickListener(this);
        btnDecode.setOnClickListener(this);
        btnSplit.setOnClickListener(this);
        btnMerge.setOnClickListener(this);
        File file = new File(FileUtils.FILE_PATH);
        if (!new File(file, "cats.jpg").exists()) {
            boolean isSuccess = FileUtils.copyAssetsFileToSDCard(this, "cats.jpg", "image.jpg");

            if (isSuccess) {
                ToastUtils.show("图片拷贝成功");
            } else {
                ToastUtils.show("图片拷贝失败");
            }
        }

    }

    @Override
    public void onClick(View v) {
        boolean isSuccess;
        switch (v.getId()) {
            case R.id.btn_file_encrypt:
                isSuccess = FileUtils.fileEncrypt();
                if (isSuccess) {
                    ToastUtils.show("文件加密成功");
                } else {
                    ToastUtils.show("文件加密失败");
                }
                break;
            case R.id.btn_file_decode:
                isSuccess = FileUtils.fileDecode();
                if (isSuccess) {
                    ToastUtils.show("文件解密成功");
                } else {
                    ToastUtils.show("文件解密失败");
                }
                break;
            case R.id.btn_file_split:
                isSuccess = FileUtils.fileSplit();
                if (isSuccess) {
                    ToastUtils.show("文件分割成功");
                } else {
                    ToastUtils.show("文件分割失败");
                }
                break;
            case R.id.btn_file_merge:
                isSuccess = FileUtils.fileMerge();
                if (isSuccess) {
                    ToastUtils.show("文件合并成功");
                } else {
                    ToastUtils.show("文件合并失败");
                }
                break;
            default:
                break;
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
