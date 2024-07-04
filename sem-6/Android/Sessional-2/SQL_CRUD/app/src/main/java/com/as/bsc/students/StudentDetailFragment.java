package com.as.bsc.students;

import android.os.Bundle;

import androidx.activity.OnBackPressedCallback;
import androidx.fragment.app.Fragment;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import com.as.bsc.R;
import com.as.bsc.students.Student;
import com.google.android.material.textfield.TextInputLayout;

import java.util.Objects;

/**
 * A simple {@link Fragment} subclass.
 * create an instance of this fragment.
 */
public class StudentDetailFragment extends Fragment {

    private boolean isUpdate = false;
    Student student = new Student();

    public StudentDetailFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            isUpdate = true;
            student = (Student) getArguments().getSerializable("student");
        }
        requireActivity().getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {
                getParentFragmentManager()
                        .beginTransaction()
                        .replace(R.id.containerStudentReg, new DisplayFragment())
                        .commit();
            }
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_student_detail, container, false);

        TextInputLayout mEtName = view.findViewById(R.id.etName);
        TextInputLayout mEtAge = view.findViewById(R.id.etAge);
        TextInputLayout mEtAddress = view.findViewById(R.id.etAddress);
        TextInputLayout mEtMobile = view.findViewById(R.id.etMobile);
        TextInputLayout mEtEmail = view.findViewById(R.id.etEmail);
        Button mbtSubmit = view.findViewById(R.id.btnSubmit);

        setTextChangeListener(mEtName);
        setTextChangeListener(mEtAge);
        setTextChangeListener(mEtAddress);
        setTextChangeListener(mEtMobile);
        setTextChangeListener(mEtEmail);

        if (isUpdate) {
            mEtName.getEditText().setText(student.getName());
            mEtAge.getEditText().setText("" + student.getAge());
            mEtAddress.getEditText().setText(student.getAddress());
            mEtMobile.getEditText().setText(student.getMobile());
            mEtEmail.getEditText().setText(student.getEmail());
        }

        mbtSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String name = Objects.requireNonNull(mEtName.getEditText()).getText().toString();
                String age = Objects.requireNonNull(mEtAge.getEditText()).getText().toString();
                String address = Objects.requireNonNull(mEtAddress.getEditText()).getText().toString();
                String mobile = Objects.requireNonNull(mEtMobile.getEditText()).getText().toString();
                String email = Objects.requireNonNull(mEtEmail.getEditText()).getText().toString();

                if (name.isEmpty()) {
                    mEtName.setError("Please enter name");
                } else if (age.isEmpty()) {
                    mEtAge.setError("Please enter age");
                } else if (address.isEmpty()) {
                    mEtAddress.setError("Please enter address");
                } else if (mobile.isEmpty()) {
                    mEtMobile.setError("Please enter mobile");
                } else if (email.isEmpty()) {
                    mEtEmail.setError("Please enter email");
                } else {
                    student.setName(name);
                    student.setAge(Integer.parseInt(age));
                    student.setAddress(address);
                    student.setMobile(mobile);
                    student.setEmail(email);
                    DBManager dbManager = new DBManager(requireContext());
                    dbManager.openDB();
                    long id;
                    if (isUpdate) {
                        id = dbManager.updateStudent(student.getId(), student);
                    } else {
                        id = dbManager.insert(student);
                    }


                    if (id != -1) {
                        dbManager.closeDB();
                        showToast("Record saved!");
                        getParentFragmentManager()
                                .beginTransaction()
                                .replace(R.id.containerStudentReg, new DisplayFragment())
                                .commit();
                    } else {
                        showToast("Error");
                    }
                }
            }
        });

        return view;
    }


    private void setTextChangeListener(TextInputLayout inputLayout) {
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

    private void showToast(String message) {
        Toast.makeText(requireContext(), message, Toast.LENGTH_LONG).show();
    }
}