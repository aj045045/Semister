package com.example.assignment_1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.util.ArrayList;

public class Screen_1 extends AppCompatActivity {

    EditText et_firstName, et_lastName, et_age, et_address, et_mail, et_mobile;
    Button bt_next;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_screen1);
        et_firstName = findViewById(R.id.sc1_first_name);
        et_lastName = findViewById(R.id.sc1_last_name);
        et_age = findViewById(R.id.sc1_age);
        et_address = findViewById(R.id.sc1_address);
        et_mail = findViewById(R.id.sc1_email);
        et_mobile = findViewById(R.id.sc1_mobile);
        bt_next = findViewById(R.id.sc1_next);
        bt_next.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (et_firstName.getText().toString().isEmpty()){
                    et_firstName.setError("Enter First Name");
                } else if (et_lastName.getText().toString().isEmpty()) {
                    et_lastName.setError("Enter Last Name");
                } else if (et_age.getText().toString().isEmpty()) {
                    et_age.setError("Enter  Age");
                } else if (et_address.getText().toString().isEmpty()) {
                    et_address.setError("Enter Address");
                } else if (et_mail.getText().toString().isEmpty()) {
                    et_mail.setError("Enter E-Mail");
                } else if (et_mobile.getText().toString().isEmpty()) {
                    et_mobile.setError("Enter Mobile Number");
                } else {
                    Employee employee = new Employee();
                    employee.setFirst_name(et_firstName.getText().toString());
                    employee.setLast_name(et_lastName.getText().toString());
                    employee.setAddress(et_address.getText().toString());
                    employee.setEmail(et_mail.getText().toString());
                    employee.setMobile(et_mobile.getText().toString());
                    employee.setAge(et_age.getText().toString());
                    Intent intent = new Intent(Screen_1.this,Screen_2.class);
                    if(getIntent().hasExtra("employee")){
                        ArrayList<Employee> employeeArrayList = (ArrayList<Employee>) getIntent().getSerializableExtra("employee");
                        assert employeeArrayList != null;
                        employeeArrayList.add(employee);
                        intent.putExtra("employee",employeeArrayList);
                    }
                    else {
                        ArrayList<Employee> employeeArrayList = new ArrayList<Employee>();
                        employeeArrayList.add(employee);
                        intent.putExtra("employee",employeeArrayList);
                    }
                    startActivity(intent);
                }
            }
        });
    }
}