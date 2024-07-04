package com.example.practice_1.classes;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.practice_1.R;

import java.util.ArrayList;

public class DisplayAdapter extends RecyclerView.Adapter<DisplayViewHolder> {
    private ArrayList<StudentModel> list = new ArrayList<>();
    onItemClickListener itemClickListener;
    @NonNull
    @Override
    public DisplayViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_student,parent,false);
        return new DisplayViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull DisplayViewHolder holder, int position) {
        StudentModel model=list.get(position);
        holder.name.setText(String.format("Name :%s", model.getName()));
        holder.age.setText(String.format("Age :%s", model.getAge()));
        holder.address.setText(String.format("Address :%s", model.getAddress()));
        holder.email.setText(String.format("Email :%s", model.getEmail()));
        holder.mobile.setText(String.format("Mobile :%s", model.getMobile()));
        holder.edit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                itemClickListener.updateClick(model,position);
            }
        });
        holder.delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                itemClickListener.itemClick(model,position);
            }
        });
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public void updateList(ArrayList<StudentModel> list1){
        list.clear();
        list.addAll(list1);
        notifyDataSetChanged();
    }
    public void setItemClickListener(onItemClickListener itemClickListener) {
        this.itemClickListener = itemClickListener;
    }

}
