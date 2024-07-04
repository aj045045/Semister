package com.example.practice_1.fragment;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import com.example.practice_1.R;
import com.example.practice_1.classes.DBManager;
import com.example.practice_1.classes.DisplayAdapter;
import com.example.practice_1.classes.StudentModel;
import com.example.practice_1.classes.onItemClickListener;

import java.util.ArrayList;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link DisplayFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class DisplayFragment extends Fragment {

    private RecyclerView recyclerView;
    private Button button;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view;
        view = inflater.inflate(R.layout.fragment_display, container, false);
        recyclerView = view.findViewById(R.id.rvStudent);
        button = view.findViewById(R.id.dis_add_student);

        DisplayAdapter displayAdapter = new DisplayAdapter();
        recyclerView.setAdapter(displayAdapter);
        DBManager manager = new DBManager(requireContext());
        manager.openDB();
        ArrayList<StudentModel>  list = manager.fetchAllStudent();
        displayAdapter.updateList(list);
        displayAdapter.setItemClickListener(new onItemClickListener() {
            @Override
            public void itemClick(StudentModel studentModel, int id) {
                new AlertDialog.Builder(requireContext())
                        .setTitle(studentModel.getName())
                        .setMessage("Are you sure you want to delete record ?")
                        .setCancelable(false)
                        .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                manager.deleteStudent(studentModel.getId());
                                list.clear();
                                list.addAll(manager.fetchAllStudent());
                                displayAdapter.updateList(list);
                            }
                        })
                        .setNegativeButton("Cancel",null)
                        .show();
            }

            @Override
            public void updateClick(StudentModel studentModel, int id) {
                    manager.closeDB();
                    Toast.makeText(requireContext(),"Update Click",Toast.LENGTH_LONG).show();
                    StudentFragment studentFragment = new StudentFragment();
                    Bundle bundle = new Bundle();
                    bundle.putSerializable("student",studentModel);
                    studentFragment.setArguments(bundle);
                    getParentFragmentManager()
                            .beginTransaction()
                            .replace(R.id.main_frameLayout,studentFragment)
                            .commit();
            }
        });
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getParentFragmentManager().beginTransaction().replace(R.id.main_frameLayout,new StudentFragment()).commit();
            }
        });
        return  view;
    }
}