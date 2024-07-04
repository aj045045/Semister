package com.example.assignment_1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.ArrayList;

public class Screen_2 extends AppCompatActivity {

    EditText et_salary, et_experience, et_last_company, et_last_company_ref;
    Button bt_submit;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_screen2);
        et_salary = findViewById(R.id.sc2_salary);
        et_experience = findViewById(R.id.sc2_experience);
        et_last_company = findViewById(R.id.sc2_last_company_name);
        et_last_company_ref = findViewById(R.id.sc2_last_company_ref);
        bt_submit = findViewById(R.id.sc2_submit);
        bt_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (et_salary.getText().toString().isEmpty()){
                    et_salary.setError("Enter Salary");
                } else if (et_experience.getText().toString().isEmpty()) {
                    et_experience.setError("Enter Experience");
                } else if (et_last_company.getText().toString().isEmpty()) {
                    et_last_company.setError("Enter Last Company Name");
                }else if (et_last_company_ref.getText().toString().isEmpty()){
                    et_last_company_ref.setError("Enter last company Reference");
                }else {
                    ArrayList<Employee> employeeArrayList = (ArrayList<Employee>) getIntent().getSerializableExtra("employee");
                    if (employeeArrayList != null) {
                    Employee employee = employeeArrayList.get(employeeArrayList.size() - 1);
                    assert employee != null;
                    employee.setSalary(et_salary.getText().toString());
                    employee.setExperience(et_experience.getText().toString());
                    employee.setLast_company(et_last_company.getText().toString());
                    employee.setLast_company_ref(et_last_company_ref.getText().toString());
                    Intent intent1 = new Intent(Screen_2.this, MainActivity.class);
                    employeeArrayList.set(employeeArrayList.size()-1,employee);
                    intent1.putExtra("employee",employeeArrayList);
                    startActivity(intent1);
                    }
                }
            }
        });
    }
}