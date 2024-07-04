package com.example.sql_fragment.Classess;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.sql_fragment.R;

import java.util.ArrayList;

public class DisplayAdapter extends RecyclerView.Adapter<DisplayViewHolder> {
    private ArrayList<Student> studentArrayList = new ArrayList<>();
    OnItemClickListner itemClickListener;

    @NonNull
    @Override
    public DisplayViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_student,parent,false);
        return new DisplayViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull DisplayViewHolder holder, int position) {
        Student student = studentArrayList.get(position);
        holder.tv_firstName.setText(String.format("First name :%s", student.getFirstName()));
        holder.tv_secondName.setText(String.format("Last name :%s", student.getLastName()));
        holder.tv_contactNo.setText(String.format("Contact No :%s", student.getContactNo()));
        holder.tv_rollNo.setText(String.format("Roll No :%s", student.getRollNo()));
        holder.tv_address.setText(String.format("Address :%s", student.getAddress()));
        holder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            }
        });
        holder.btn_delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                itemClickListener.studentItemClickListener(student,position);
            }
        });
    }

    public void updateList(ArrayList<Student> students){
        studentArrayList.clear();
        studentArrayList.addAll(students);
        notifyDataSetChanged();
    }
    public void setOnItemClickListener(OnItemClickListner onItemClickListner){
        this.itemClickListener = onItemClickListner;
    }
    @Override
    public int getItemCount() {
        return studentArrayList.size();
    }
}
