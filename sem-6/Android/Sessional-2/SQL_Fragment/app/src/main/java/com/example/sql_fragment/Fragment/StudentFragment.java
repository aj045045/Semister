package com.example.sql_fragment.Fragment;

import android.os.Bundle;

import androidx.activity.OnBackPressedCallback;
import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.sql_fragment.Classess.DBManager;
import com.example.sql_fragment.Classess.Student;
import com.example.sql_fragment.R;

import java.util.ArrayList;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link StudentFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class StudentFragment extends Fragment {

    private String firstName,lastName,rollNo,contactNo,address;
    public StudentFragment() {
     }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requireActivity().getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {
            getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new DisplayFragment()).commit();
            }
        });
    }
    private void showToast(String toastData){
        Toast.makeText(getActivity(),toastData,Toast.LENGTH_LONG).show();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        EditText et_firstName,et_lastName,et_rollNo,et_contactNo,et_address;
        Button btn_submit;
        View view;
        view = inflater.inflate(R.layout.fragment_student, container, false);
        et_firstName = view.findViewById(R.id.firstName);
        et_lastName = view.findViewById(R.id.secondName);
        et_rollNo = view.findViewById(R.id.rollNo);
        et_contactNo = view.findViewById(R.id.contactNo);
        et_address= view.findViewById(R.id.address);
        btn_submit = view.findViewById(R.id.registerStudentBtn);
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if(et_firstName.getText().toString().isEmpty()){
                    et_firstName.setError("Enter the first name");
                }else if(et_lastName.getText().toString().isEmpty()){
                    et_lastName.setError("Enter the last name");
                }else if(et_rollNo.getText().toString().isEmpty()){
                    et_rollNo.setError("Enter the roll No");
                }else if(et_contactNo.getText().toString().isEmpty()){
                    et_contactNo.setError("Enter the contact no.");
                }else if(et_address.getText().toString().isEmpty()){
                    et_address.setError("Enter the address");
                }else {
                    firstName = et_firstName.getText().toString();
                    lastName = et_lastName.getText().toString();
                    rollNo = et_rollNo.getText().toString();
                    contactNo = et_contactNo.getText().toString();
                    address = et_address.getText().toString();
                    Student student = new Student();
                    student.setFirstName(firstName);
                    student.setLastName(lastName);
                    student.setRollNo(rollNo);
                    student.setContactNo(contactNo);
                    student.setAddress(address);
                    DBManager dbManager = new DBManager(requireContext());
                    dbManager.openDB();
                    long id = dbManager.insertQuery(student);
                    if(id !=-1){
                        dbManager.closeDB();
                        showToast("Record Saved");
                        getParentFragmentManager().beginTransaction().replace(R.id.main_fragment_page,new DisplayFragment()).commit();
                    }else{
                        showToast("Error data");
                    }
                }
            }
        });
        return view;
    }
}