package com.as.bsc.students;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;

import androidx.activity.OnBackPressedCallback;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.as.bsc.R;

import java.util.ArrayList;
import java.util.Objects;

/**
 * A simple {@link Fragment} subclass.
 * create an instance of this fragment.
 */
public class DisplayFragment extends Fragment {

    private RecyclerView displayView;
    private Button btnAddStudent;

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
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_display, container, false);
        displayView = view.findViewById(R.id.rvStudents);
        btnAddStudent = view.findViewById(R.id.btnAddStudent);
        DisplayAdapter displayAdapter = new DisplayAdapter();
        displayView.setAdapter(displayAdapter);

        DBManager dbManager = new DBManager(requireContext());
        dbManager.openDB();
        ArrayList<Student> students = dbManager.fetchAll();
        displayAdapter.updateList(students);
        displayAdapter.setItemClickListener(new OnItemClickListener() {
            @Override
            public void studentItemClickListener(Student student, int pos) {
                new AlertDialog.Builder(requireContext())
                        .setTitle(student.getName())
                        .setMessage("Are you sure you want to delete entry?")
                        .setCancelable(false)
                        .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dbManager.deleteStudent(student.getId());
                                students.clear();
                                students.addAll(dbManager.fetchAll());
                                displayAdapter.updateList(students);
                            }
                        })
                        .setNegativeButton("Cancel", null)
                        .show();
            }

            @Override
            public void updateStudent(Student student, int pos) {
                dbManager.closeDB();
                StudentDetailFragment studentDetailFragment = new StudentDetailFragment();
                Bundle bundle = new Bundle();
                bundle.putSerializable("student", student);
                studentDetailFragment.setArguments(bundle);
                getParentFragmentManager()
                        .beginTransaction()
                        .replace(R.id.containerStudentReg, studentDetailFragment)
                        .commit();
            }
        });


        btnAddStudent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dbManager.closeDB();
                getParentFragmentManager()
                        .beginTransaction()
                        .replace(R.id.containerStudentReg, new StudentDetailFragment())
                        .commit();
            }
        });
        return view;
    }
}