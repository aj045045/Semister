package com.as.bsc.students;

import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import com.as.bsc.R;

public class DisplayViewHolder extends RecyclerView.ViewHolder {
    TextView tvName, tvAge, tvAddress, tvMobile, tvEmail;
    CardView cvItem;
    Button btnEdit, btnDelete;

    public DisplayViewHolder(@NonNull View itemView) {
        super(itemView);
        tvName = itemView.findViewById(R.id.tvName);
        tvAge = itemView.findViewById(R.id.tvAge);
        tvAddress = itemView.findViewById(R.id.tvAddress);
        tvMobile = itemView.findViewById(R.id.tvMobile);
        tvEmail = itemView.findViewById(R.id.tvEmail);
        cvItem = itemView.findViewById(R.id.cvItem);
        btnEdit = itemView.findViewById(R.id.btnEdit);
        btnDelete = itemView.findViewById(R.id.btnDelete);
    }
}
