package com.example.practice_1.fragment;

import android.os.Bundle;

import androidx.activity.OnBackPressedCallback;
import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import com.example.practice_1.R;
import com.example.practice_1.classes.DBManager;
import com.example.practice_1.classes.StudentModel;


/**
 * A simple {@link Fragment} subclass.
 * Use the {@link StudentFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class StudentFragment extends Fragment {
    private  boolean isUpdate = false;
    StudentModel student = new StudentModel();

    public StudentFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
                isUpdate = true;
                student = (StudentModel) getArguments().getSerializable("student");
        }
            requireActivity().getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
                @Override
                public void handleOnBackPressed() {
                    getParentFragmentManager()
                            .beginTransaction()
                            .replace(R.id.main_frameLayout, new DisplayFragment())
                            .commit();
                }
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view ;
        view = inflater.inflate(R.layout.fragment_student, container, false);

        EditText et_name = view.findViewById(R.id.stu_name);
        EditText et_address = view.findViewById(R.id.stu_address);
        EditText et_age = view.findViewById(R.id.stu_age);
        EditText et_mobile = view.findViewById(R.id.stu_mobile);
        Spinner et_email = view.findViewById(R.id.stu_email);
//        EditText et_email = view.findViewById(R.id.stu_email);
        Button btn_submit = view.findViewById(R.id.stu_submit);
        final String[] email = new String[1];

        if(isUpdate){
            String[] spinnerItems = getResources().getStringArray(R.array.email_values);
            et_name.setText(student.getName());
            et_address.setText(student.getAddress());
            et_age.setText(String.valueOf(student.getAge()));
            et_mobile.setText(student.getMobile());
//            et_email.setText(student.getEmail());
            for (int i = 0; i < spinnerItems.length; i++) {
                if (spinnerItems[i].equals(student.getEmail())) {
                    et_email.setSelection(i);
                    break;
                }
            }
        }
        et_email.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                email[0] = parent.getItemAtPosition(position).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(et_name.getText().toString().isEmpty()){
                    et_name.setError("Enter Text");
                }else if(et_age.getText().toString().isEmpty()){
                    et_age.setError("Enter Text");
                }else if(et_address.getText().toString().isEmpty()){
                    et_address.setError("Enter Text");
//                }else if(et_email.getText().toString().isEmpty()){
//                    et_email.setError("Enter Text");
                }else if(et_mobile.getText().toString().isEmpty()){
                    et_mobile.setError("Enter Text");
                }else{
                    student.setName(et_name.getText().toString());
                    student.setMobile(et_mobile.getText().toString());
//                    student.setEmail(et_email.getText().toString());
                    student.setEmail(email[0]);
                    student.setAge(Integer.parseInt(et_age.getText().toString()));
                    student.setAddress(et_address.getText().toString());

                    DBManager manager = new DBManager(requireContext());
                    manager.openDB();
                    long id;
                    if(isUpdate){
                        id = manager.updateStudent(student.getId(),student);
                    }else {
                        id = manager.insertStudent(student);
                    }

                    if(id !=-1){
                        manager.closeDB();
                        Toast.makeText(requireContext(),"Record Saved!",Toast.LENGTH_LONG).show();
                        getParentFragmentManager()
                                .beginTransaction()
                                .replace(R.id.main_frameLayout, new DisplayFragment())
                                .commit();
                    }else{
                        Toast.makeText(requireContext(),"Try Again",Toast.LENGTH_LONG).show();
                    }
                }
            }
        });

        return view;
    }
}