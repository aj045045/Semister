package com.example.fragments;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.fragments.Fragments.FirstFragment;
import com.example.fragments.Fragments.SecondFragment;

public class EmptyActivity extends AppCompatActivity {

    private Button btnFirst, btnSecond;
    EditText et_first, et_second;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_empty);
        btnFirst = findViewById(R.id.empty_button_1);
        btnSecond = findViewById(R.id.empty_button_2);
        et_first = findViewById(R.id.main_text_1);
        et_second = findViewById(R.id.main_text_2);

//        TODO : First Button Click Listener
        btnFirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString(String.valueOf(1),et_first.getText().toString());
                bundle.putString(String.valueOf(2),et_second.getText().toString());
                FirstFragment f = new FirstFragment();
                f.setArguments(bundle);
                loadFragment(f);
            }
        });

//        TODO : Second Button Click Listener
        btnSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                loadFragment(new SecondFragment());
            }
        });
    }
        private void loadFragment(Fragment fragment){
            FragmentManager fragmentManager = getSupportFragmentManager();
            FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
            fragmentTransaction.replace(R.id.empty_frame,fragment);
            fragmentTransaction.commit();
        }
}