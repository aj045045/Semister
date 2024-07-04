package com.example.sql_practice;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.sql_practice.fragment.DisplayFragment;
import com.example.sql_practice.fragment.StudentFormFragment;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new DisplayFragment()).commit();
    }
}