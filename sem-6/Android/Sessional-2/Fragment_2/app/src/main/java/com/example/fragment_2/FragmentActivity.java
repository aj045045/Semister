package com.example.fragment_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class FragmentActivity extends AppCompatActivity {

    EditText et_first,et_second,et_third,et_fourth,et_fifth;
    Button btn_submit;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fragment);
        et_first = findViewById(R.id.first_text_box);
        et_second = findViewById(R.id.second_text_box);
        et_third = findViewById(R.id.third_text_box);
        et_fourth = findViewById(R.id.fourth_text_box);
        et_fifth = findViewById(R.id.fifth_text_box);
        btn_submit = findViewById(R.id.submit_button);
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(et_first.getText().toString().isEmpty()){
                    et_first.setError("Enter the First Name");
                }else if(et_second.getText().toString().isEmpty()){
                    et_second.setError("Enter the Second Name");
                }else if(et_third.getText().toString().isEmpty()){
                    et_third.setError("Enter the E-mail");
                }else if(et_fourth.getText().toString().isEmpty()){
                    et_fourth.setError("Enter the Phone No ");
                }else if(et_fifth.getText().toString().isEmpty()){
                    et_fifth.setError("Enter the Address");
                }else {
                    Bundle args = new Bundle();
                    InputData inputData = new InputData();
                    inputData.setFirstName(et_first.getText().toString());
                    inputData.setLastName(et_second.getText().toString());
                    inputData.setEmail(et_third.getText().toString());
                    inputData.setPhoneNo(et_fourth.getText().toString());
                    inputData.setAddress(et_fifth.getText().toString());
                    args.putSerializable(String.valueOf(1), inputData);
                    InputFragment inputFragment = new InputFragment();
                    inputFragment.setArguments(args);
                    getSupportFragmentManager().beginTransaction().replace(R.id.frame_layout, inputFragment).commit();
                }
            }
        });
    }
}