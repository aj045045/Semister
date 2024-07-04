package com.as.bsc.demos;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.as.bsc.R;
import com.as.bsc.fragments.FirstFragment;
import com.as.bsc.fragments.SecondFragment;

public class FragmentDemoActivity extends AppCompatActivity {
EditText etFirstParam, etSecondParam;
    private Button btnFirst, btnSecond;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fragment_demo);

        etFirstParam = findViewById(R.id.etParam1);
        etSecondParam = findViewById(R.id.etParam2);
        btnFirst = findViewById(R.id.btnFirstFragment);
        btnSecond = findViewById(R.id.btnSecondFragment);

        btnFirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FirstFragment fragment = FirstFragment.newInstance("ABC","XYZ");
                loadFragment(fragment);
            }
        });

        btnSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String Param1 = etFirstParam.getText().toString();
                String Param2 = etSecondParam.getText().toString();

                Bundle bundle= new Bundle();
                bundle.putString(SecondFragment.ARG_PARAM1 , Param1);
                bundle.putString(SecondFragment.ARG_PARAM2 , Param2);

                SecondFragment secondFragment = new SecondFragment();
                secondFragment.setArguments(bundle);
                loadFragment(secondFragment);
            }
        });
    }

    private void loadFragment(Fragment fragment) {
        FragmentManager manager = getSupportFragmentManager();
        FragmentTransaction transaction = manager.beginTransaction();
        transaction.replace(R.id.fragmentLayout,fragment);
        transaction.commit();
    }
}