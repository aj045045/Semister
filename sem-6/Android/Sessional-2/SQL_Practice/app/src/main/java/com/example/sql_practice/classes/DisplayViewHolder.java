package com.example.sql_practice.classes;

import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import com.example.sql_practice.R;

public class DisplayViewHolder extends RecyclerView.ViewHolder {
    TextView tv_name,tv_age,tv_course,tv_mail,tv_phoneNo;
    CardView cardView;
    Button btnEdit,btnDelete;
    public DisplayViewHolder(@NonNull View itemView) {
        super(itemView);
        tv_name = itemView.findViewById(R.id.display_name);
        tv_age = itemView.findViewById(R.id.display_age);
        tv_course = itemView.findViewById(R.id.display_course);
        tv_mail = itemView.findViewById(R.id.display_mail);
        tv_phoneNo = itemView.findViewById(R.id.display_phoneNo);
        cardView = itemView.findViewById(R.id.item_cardView);
        btnDelete = itemView.findViewById(R.id.display_btnDelete);
        btnEdit = itemView.findViewById(R.id.display_btnEdit);
    }
}
