package com.example.ndkcrashdemo;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.ndkcrashdemo.databinding.ActivityMainBinding;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private ActivityMainBinding binding;

    private File externalReportPath;

    private EditText mEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //测试XCrash捕获
        xcrash.XCrash.init(this);
        //测试BreakPad捕获
//        initBreakPad();

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setOnClickListener(v -> new Thread(() -> stringFromJNI()).start());
        mEditText = binding.strCount;
        binding.button.setOnClickListener(v -> onTestLocalRefOverflow());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    /**
     * 一般来说，crash捕获初始化都会放到Application中，这里主要是为了大家有机会可以把崩溃文件输出到sdcard中
     * 做进一步的分析
     */
    private void initBreakPad() {
//        if (externalReportPath == null) {
//            externalReportPath = new File(getExternalCacheDir(), "crashDump");
//            if (!externalReportPath.exists()) {
//                externalReportPath.mkdirs();
//            }
//        }
//        BreakpadInit.initBreakpad(externalReportPath.getAbsolutePath());
    }

    /**
     * 测试sanitize
     */
    public static native void HeapBufferOverflow();

    /**
     * 测试Jni错误
     *
     * @param count
     * @param sample
     * @return
     */
    public native String[] getStrings(int count, String sample);

    public void onTestLocalRefOverflow() {
        String[] strings = getStrings(Integer.parseInt(mEditText.getText().toString()), "I Love You %d Year！！！");
        for (String string : strings) {
            System.out.println(string);
        }
    }

}