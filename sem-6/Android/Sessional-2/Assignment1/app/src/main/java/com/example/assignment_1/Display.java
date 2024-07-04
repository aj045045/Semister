package com.example.assignment_1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.LinearLayout;
import java.util.ArrayList;
public class Display extends AppCompatActivity {

    LinearLayout linearLayout;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);
        linearLayout = findViewById(R.id.display_root_tag);
        ArrayList<Employee> employeeArrayList = (ArrayList<Employee>) getIntent().getSerializableExtra("employee");
        assert employeeArrayList != null;
        employeeArrayList.forEach(employee -> {
        CustomView1 customView1 = new CustomView1(this,null);
        customView1.setFirstName(employee.getFirst_name());
        customView1.setLastName(employee.getLast_name());
        customView1.setAge(employee.getAge());
        customView1.setAddress(employee.getAddress());
        customView1.setMobile(employee.getMobile());
        customView1.setEmail(employee.getEmail());
        CustomView2 customView2 = new CustomView2(this,null);
        customView2.setSalary(employee.getSalary());
        customView2.setExperience(employee.getExperience());
        customView2.setLastCompany(employee.getLast_company());
        customView2.setLastCompanyRef(employee.getLast_company_ref());
        linearLayout.addView(customView1);
        linearLayout.addView(customView2);
        });
    }
}