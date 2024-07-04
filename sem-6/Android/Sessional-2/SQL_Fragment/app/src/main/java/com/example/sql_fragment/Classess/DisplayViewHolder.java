package com.example.sql_fragment.Classess;

import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import com.example.sql_fragment.R;

public class DisplayViewHolder extends RecyclerView.ViewHolder {

     TextView tv_firstName,tv_secondName,tv_rollNo,tv_contactNo,tv_address;
     CardView cardView;
    Button btn_delete;
    public DisplayViewHolder(@NonNull View itemView) {
        super(itemView);
        tv_firstName = itemView.findViewById(R.id.display_firstname);
        tv_secondName = itemView.findViewById(R.id.display_secondname);
        tv_rollNo = itemView.findViewById(R.id.display_rollNo);
        tv_address = itemView.findViewById(R.id.display_address);
        tv_contactNo = itemView.findViewById(R.id.display_contactNo);
        btn_delete = itemView.findViewById(R.id.display_btnDelete);
        cardView = itemView.findViewById(R.id.item_cardView);
    }
}
