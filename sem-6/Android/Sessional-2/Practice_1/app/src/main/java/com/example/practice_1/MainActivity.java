package com.example.practice_1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.practice_1.fragment.DisplayFragment;
import com.example.practice_1.fragment.StudentFragment;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportFragmentManager().beginTransaction().replace(R.id.main_frameLayout, new DisplayFragment()).commit();
    }
}