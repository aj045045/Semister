package com.example.sql_fragment.Fragment;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.example.sql_fragment.Classess.DBManager;
import com.example.sql_fragment.Classess.DisplayAdapter;
import com.example.sql_fragment.Classess.OnItemClickListner;
import com.example.sql_fragment.Classess.Student;
import com.example.sql_fragment.R;

import java.util.ArrayList;

public class DisplayFragment extends Fragment {
    private Button btn_submit;
    private RecyclerView recyclerView;
    private DBManager dbManager;
    public DisplayFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view;
        view = inflater.inflate(R.layout.fragment_display, container, false);
        btn_submit = view.findViewById(R.id.btnDisplay);
        recyclerView = view.findViewById(R.id.rvStudent);
        dbManager = new DBManager(requireContext());
        dbManager.openDB();
        ArrayList<Student> students = dbManager.fetchAllQuery();
        DisplayAdapter displayAdapter = new DisplayAdapter();
        displayAdapter.updateList(students);
        displayAdapter.setOnItemClickListener(new OnItemClickListner() {
            @Override
            public void studentItemClickListener(Student student, int position) {
                                    int pos = dbManager.deleteQuery(String.valueOf(position));
                                    if(pos >0){
                                        Toast.makeText(requireActivity(),"Delete successful",Toast.LENGTH_SHORT).show();
                                    }else{
                                        Toast.makeText(requireActivity(),"Unsuccessful delete",Toast.LENGTH_SHORT).show();
                                        }
//
//                new AlertDialog.Builder(requireContext())
//                        .setTitle(student.getFirstName())
//                        .setMessage("Do you want to delete the data ?")
//                        .setCancelable(false)
//                        .setNegativeButton("Yes", new DialogInterface.OnClickListener() {
//                            @Override
//                            public void onClick(DialogInterface dialog, int which) {
//                                Log.d("Positon",String.valueOf(position));
////                                    int pos = dbManager.deleteQuery(String.valueOf(position));
////                                    if(pos >0){
////                                        Toast.makeText(requireActivity(),"Delete successful",Toast.LENGTH_SHORT).show();
////                                    }else{
////                                        Toast.makeText(requireActivity(),"Unsuccessful delete",Toast.LENGTH_SHORT).show();
////                                    }
//                            }
//                        })
//                        .setPositiveButton("Cancel", new DialogInterface.OnClickListener() {
//                            @Override
//                            public void onClick(DialogInterface dialog, int which) {
//                                Log.d("Positon",String.valueOf(position));
//                            }
//                        })
//                        .show();
            }
            @Override
            public void updateStudent(Student student, int position) {

            }
        });
        recyclerView.setAdapter(displayAdapter);
        displayAdapter.updateList(students);
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page, new StudentFragment()).commit();
            }
        });
        return  view;
    }
    @Override
    public void onDestroyView() {
        super.onDestroyView();
        // Close the database when the Fragment's view is destroyed
        if (dbManager != null) {
            dbManager.closeDB();
        }
    }
}