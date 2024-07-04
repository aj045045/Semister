package com.example.sql_practice.classes;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.sql_practice.R;

import java.util.ArrayList;

public class DisplayAdapter extends RecyclerView.Adapter<DisplayViewHolder> {

    private final ArrayList<StudentDetail> studentDetails = new ArrayList<>();
    OnItemClickListener onItemClickListener;
    @NonNull
    @Override
    public DisplayViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_student,parent,false);
        return new DisplayViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull DisplayViewHolder holder, int position) {
        StudentDetail studentDetail = studentDetails.get(position);
        holder.tv_name.setText(String.format("Name : %s",studentDetail.getName()));
        holder.tv_age.setText(String.format("Age : %s",studentDetail.getAge()));
        holder.tv_course.setText(String.format("Course : %s",studentDetail.getCourse()));
        holder.tv_mail.setText(String.format("Mail : %s",studentDetail.getMail()));
        holder.tv_phoneNo.setText(String.format("PhoneNo : %s",studentDetail.getPhoneNo()));
        holder.btnEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onItemClickListener.updateStudent(studentDetail,position);
            }
        });
        holder.btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onItemClickListener.studentItemClickListener(studentDetail,position);
            }
        });
    }

    public void updateList(ArrayList<StudentDetail> details){
        studentDetails.clear();
        studentDetails.addAll(details);
        notifyDataSetChanged();
    }

    public void setOnItemClickListener(OnItemClickListener itemClickListener){
        this.onItemClickListener = itemClickListener;
    }
    @Override
    public int getItemCount() {
        return studentDetails.size();
    }
}
