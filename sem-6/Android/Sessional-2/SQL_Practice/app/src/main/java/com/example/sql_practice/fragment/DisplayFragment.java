package com.example.sql_practice.fragment;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.example.sql_practice.R;
import com.example.sql_practice.classes.DisplayAdapter;
import com.example.sql_practice.classes.DisplayViewHolder;
import com.example.sql_practice.classes.OnItemClickListener;
import com.example.sql_practice.classes.StudentDetail;
import com.example.sql_practice.database.DBManager;

import java.util.ArrayList;


public class DisplayFragment extends Fragment {

    private Button btn_submit;
    private RecyclerView recyclerView;

    public DisplayFragment() {
        // Required empty public constructor
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

        DisplayAdapter displayAdapter = new DisplayAdapter();
        recyclerView.setAdapter(displayAdapter);

        DBManager dbManager = new DBManager(requireContext());
        dbManager.openDB();

        ArrayList<StudentDetail> details = dbManager.fetchAllQuery();
        displayAdapter.updateList(details);
        displayAdapter.setOnItemClickListener(new OnItemClickListener() {
            @Override
            public void studentItemClickListener(StudentDetail studentDetail, int pos) {
                new AlertDialog.Builder(requireContext())
                        .setTitle(studentDetail.getName())
                        .setMessage("Are you sure you want to delete entry?")
                        .setCancelable(false)
                        .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dbManager.deleteQuery(Long.parseLong(studentDetail.getId()));
                                details.clear();
                                details.addAll(dbManager.fetchAllQuery());
                                displayAdapter.updateList(details);
                            }
                        })
                        .setNegativeButton("Cancel", null)
                        .show();
            }

            @Override
            public void updateStudent(StudentDetail studentDetail, int pos) {
                dbManager.closeDB();
                StudentFormFragment studentDetailFragment = new StudentFormFragment();
                Bundle bundle = new Bundle();
                bundle.putSerializable("student", studentDetail);
                studentDetailFragment.setArguments(bundle);
                getParentFragmentManager()
                        .beginTransaction()
                        .replace(R.id.main_fragment_page, studentDetailFragment)
                        .commit();
            }
        });
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dbManager.closeDB();
                getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new StudentFormFragment()).commit();
            }
        });
        dbManager.closeDB();
        return view;
    }
}