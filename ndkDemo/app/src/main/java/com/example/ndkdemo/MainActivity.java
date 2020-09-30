package com.example.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        Button button = findViewById(R.id.b_excep);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                exceptionTest();
            }
        });
        Button bnc = findViewById(R.id.b_excep_not_catch);
        bnc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG, "exception=" + exceptionNotCatchTest());
            }
        });
        Button bs=findViewById(R.id.b_s);
        bs.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new StringTypeOps().invoke();
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void exceptionTest();

    public native int exceptionNotCatchTest();

}
