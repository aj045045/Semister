package com.example.sql_fragment;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.sql_fragment.Fragment.DisplayFragment;
import com.example.sql_fragment.Fragment.StudentFragment;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    getSupportFragmentManager().beginTransaction().replace(R.id.main_fragment_page, new DisplayFragment()).commit();
    }

}