package com.example.assignment_1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    Button bt_add_employee,bt_display_employee;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bt_add_employee = findViewById(R.id.main_add_employee);
        bt_display_employee = findViewById(R.id.main_display_employee);

//        TODO : Add employee
        bt_add_employee.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = getIntent();
                if(intent.hasExtra("employee")){
                    ArrayList<Employee> employeeArrayList = (ArrayList<Employee>) intent.getSerializableExtra("employee");
                    Intent intent1 = new Intent(MainActivity.this,Screen_1.class);
                    intent1.putExtra("employee",employeeArrayList);
                    startActivity(intent1);
                }else {
                    Intent intent1 = new Intent(MainActivity.this,Screen_1.class);
                    startActivity(intent1);
                }
            }
        });

//        TODO : Display employee
        bt_display_employee.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = getIntent();
                if(intent.hasExtra("employee")){
                    ArrayList<Employee> employeeArrayList = (ArrayList<Employee>) intent.getSerializableExtra("employee");
                    Intent intent1 = new Intent(MainActivity.this,Display.class);
                    intent1.putExtra("employee",employeeArrayList);
                    startActivity(intent1);
                }else {
                    Toast.makeText(MainActivity.this,"Enter Employee Detail",Toast.LENGTH_LONG).show();
                }
            }
        });
    }
}