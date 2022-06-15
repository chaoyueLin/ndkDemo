package com.example.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.sql.Array;

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
        Button arrayB = findViewById(R.id.array);
        Button bs = findViewById(R.id.b_s);
        Button refB = findViewById(R.id.ref);
        bs.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new StringTypeOperation().invoke();
            }
        });
        arrayB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new ArrayTypeOperation().invoke();
            }
        });
        refB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        new RefOperaton().invoke();
                    }
                }).start();
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


}
