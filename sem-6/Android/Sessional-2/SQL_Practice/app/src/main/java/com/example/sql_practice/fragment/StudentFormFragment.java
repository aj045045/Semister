package com.example.sql_practice.fragment;

import android.os.Bundle;

import androidx.activity.OnBackPressedCallback;
import androidx.fragment.app.Fragment;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sql_practice.R;
import com.example.sql_practice.classes.StudentDetail;
import com.example.sql_practice.database.DBManager;
import com.google.android.material.textfield.TextInputLayout;

import java.util.Objects;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link StudentFormFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class StudentFormFragment extends Fragment {

    private boolean isUpdate = false;

    StudentDetail studentDetail = new StudentDetail();

    public StudentFormFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if(getArguments()!=null){
            isUpdate = true;
            studentDetail = (StudentDetail) getArguments().getSerializable("student");
        }
        requireActivity().getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {
                getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new DisplayFragment()).commit();
            }
        });
    }

    private void showToast(String text){
        Toast.makeText(getActivity(),text,Toast.LENGTH_LONG).show();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view;
        view = inflater.inflate(R.layout.fragment_student_form, container, false);
        TextInputLayout et_name = view.findViewById(R.id.student_name);
        TextInputLayout et_age = view.findViewById(R.id.student_age);
        TextInputLayout et_course = view.findViewById(R.id.student_course);
        TextInputLayout et_mail = view.findViewById(R.id.student_mail);
        TextInputLayout et_phoneNo = view.findViewById(R.id.student_phoneNo);
        Button btn_add_student = view.findViewById(R.id.student_add_student);

//        setTextChangeListener(et_name);
//        setTextChangeListener(et_age);
//        setTextChangeListener(et_course);
//        setTextChangeListener(et_mail);
//        setTextChangeListener(et_phoneNo);

        if(isUpdate){
            et_name.getEditText().setText(studentDetail.getName());
            et_age.getEditText().setText(studentDetail.getAge());
            et_course.getEditText().setText(studentDetail.getCourse());
            et_mail.getEditText().setText(studentDetail.getMail());
            et_phoneNo.getEditText().setText(studentDetail.getPhoneNo());
        }

        btn_add_student.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String st_name,st_age,st_course,st_mail,st_phoneNo;
                st_name = Objects.requireNonNull(et_name.getEditText()).getText().toString();
                st_age = Objects.requireNonNull(et_age.getEditText()).getText().toString();
                st_course = Objects.requireNonNull(et_course.getEditText()).getText().toString();
                st_mail = Objects.requireNonNull(et_mail.getEditText()).getText().toString();
                st_phoneNo = Objects.requireNonNull(et_phoneNo.getEditText()).getText().toString();

                if (st_name.isEmpty()){
                    et_name.setError("Enter the name");
                }else if (st_age.isEmpty()){
                    et_age.setError("Enter the age");
                }else if (st_course.isEmpty()){
                    et_course.setError("Enter the course");
                }else if (st_mail.isEmpty()){
                    et_mail.setError("Enter the email");
                }else if (st_phoneNo.isEmpty()){
                    et_phoneNo.setError("Enter the phone no");
                }else {
                    studentDetail.setName(st_name);
                    studentDetail.setAge(st_age);
                    studentDetail.setCourse(st_course);
                    studentDetail.setMail(st_mail);
                    studentDetail.setPhoneNo(st_phoneNo);
                    DBManager dbManager = new DBManager(requireContext());
                    dbManager.openDB();
                    long id;
                    if(isUpdate){
                        id = dbManager.updateQuery(Long.parseLong(studentDetail.getId()),studentDetail);
                    }else {
                        id = dbManager.insertQuery(studentDetail);
                    }
                    if(id !=-1){
                        dbManager.closeDB();
                        showToast("Record Saved");
                        getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new DisplayFragment()).commit();
                    }else {
                     showToast("Error in saving record");
                    }
                }
            }
        });
        return view;
    }

    private void setTextChangeListener(TextInputLayout inputLayout){
        Objects.requireNonNull(inputLayout.getEditText()).addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                inputLayout.setError("");
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
    }

}