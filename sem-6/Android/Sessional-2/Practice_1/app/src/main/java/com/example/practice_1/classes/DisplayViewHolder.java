package com.example.practice_1.classes;

import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import com.example.practice_1.R;

public class DisplayViewHolder extends RecyclerView.ViewHolder  {

    TextView name,age,address,email,mobile;
    Button edit, delete;
    CardView cardView;
    public DisplayViewHolder(@NonNull View itemView) {
        super(itemView);
        name = itemView.findViewById(R.id.cv_name);
        age = itemView.findViewById(R.id.cv_age);
        address = itemView.findViewById(R.id.cv_address);
        email = itemView.findViewById(R.id.cv_email);
        mobile = itemView.findViewById(R.id.cv_mobile);
        edit = itemView.findViewById(R.id.cv_edit);
        delete = itemView.findViewById(R.id.cv_delete);
        cardView = itemView.findViewById(R.id.cv_view);
    }
}
