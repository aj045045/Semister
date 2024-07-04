package com.example.assignment_1;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.LinearLayout;

public class CustomView2 extends LinearLayout{
    TextView tv_salary,tv_experience,tv_last_company,tv_last_company_ref;
    public CustomView2(Context context, AttributeSet attrs){
        super(context,attrs);
        init(context,attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view_custom2 = inflater.inflate(R.layout.activity_custom_view_2,this,true);
        tv_salary = view_custom2.findViewById(R.id.cv2_salary);
        tv_experience = view_custom2.findViewById(R.id.cv2_experience);
        tv_last_company = view_custom2.findViewById(R.id.cv2_last_company);
        tv_last_company_ref = view_custom2.findViewById(R.id.cv2_last_company_ref);
    }
    public void setSalary(String title){
        tv_salary.setText(title);
    }
    public void setExperience(String title){
        tv_experience.setText(title);
    }
    public void setLastCompany(String title){
        tv_last_company.setText(title);
    }
    public void setLastCompanyRef(String title){
        tv_last_company_ref.setText(title);
    }

}
