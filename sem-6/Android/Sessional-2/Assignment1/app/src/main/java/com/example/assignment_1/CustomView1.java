package com.example.assignment_1;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.LinearLayout;

public class CustomView1  extends  LinearLayout{
    TextView tv_title,tv_first_name,tv_last_name,tv_age,tv_address,tv_email,tv_mobile;
    public CustomView1(Context context, AttributeSet attrs){
        super(context,attrs);
        init(context,attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view_custom1 = inflater.inflate(R.layout.activity_custom_view_1,this,true);
        tv_title = view_custom1.findViewById(R.id.cv1_title);
        tv_first_name = view_custom1.findViewById(R.id.cv1_first_name);
        tv_last_name = view_custom1.findViewById(R.id.cv1_last_name);
        tv_age = view_custom1.findViewById(R.id.cv1_age);
        tv_address = view_custom1.findViewById(R.id.cv1_address);
        tv_email = view_custom1.findViewById(R.id.cv1_email);
        tv_mobile = view_custom1.findViewById(R.id.cv1_mobile);
    }
    public void setFirstName(String title){
        String text = "Welcome "+title;
        tv_title.setText(text);
        tv_first_name.setText(title);
    }
    public void setLastName(String title){
        tv_last_name.setText(title);
    }
    public void setAge(String title){
        tv_age.setText(title);
    }
    public void setAddress(String title){
        tv_address.setText(title);
    }
    public void setEmail(String title){
        tv_email.setText(title);
    }
    public void setMobile(String title){
        tv_mobile.setText(title);
    }
}
