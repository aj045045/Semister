package com.as.bsc.students;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.as.bsc.R;

import java.util.ArrayList;

public class DisplayAdapter extends RecyclerView.Adapter<DisplayViewHolder> {
    private ArrayList<Student> studentsList = new ArrayList<>();
    OnItemClickListener itemClickListener;

    @NonNull
    @Override
    public DisplayViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_student, parent, false);
        return new DisplayViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull DisplayViewHolder holder, int position) {
        Student student = studentsList.get(position);
        holder.tvName.setText("Name: " + student.getName());
        holder.tvAge.setText("Age: " + student.getAge());
        holder.tvAddress.setText("Address: " + student.getAddress());
        holder.tvMobile.setText("Mobile: " + student.getMobile());
        holder.tvEmail.setText("Email: " + student.getEmail());
        holder.btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                itemClickListener.studentItemClickListener(student, position);
            }
        });
        holder.btnEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                itemClickListener.updateStudent(student, position);
            }
        });
    }

    @Override
    public int getItemCount() {
        return studentsList.size();
    }

    public void updateList(ArrayList<Student> students) {
        studentsList.clear();
        studentsList.addAll(students);
        notifyDataSetChanged();
    }

    public void setItemClickListener(OnItemClickListener itemClickListener) {
        this.itemClickListener = itemClickListener;
    }
}
