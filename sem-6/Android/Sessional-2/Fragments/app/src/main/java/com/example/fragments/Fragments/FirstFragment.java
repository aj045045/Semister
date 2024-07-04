package com.example.fragments.Fragments;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.example.fragments.R;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link FirstFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class FirstFragment extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private Button btn_submit;
    private TextView tv_text;
    public FirstFragment(Bundle bundle) {
        this.mParam1 = bundle.getString(String.valueOf(1));
        this.mParam2 = bundle.getString(String.valueOf(2));
        // Required empty public constructor
    }
    public  FirstFragment(){

    }
    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment FirstFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static FirstFragment newInstance(String param1, String param2) {
        FirstFragment fragment = new FirstFragment();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view;
        Bundle bundle = getArguments();
        mParam1 = bundle.getString(String.valueOf(1)).toString();
        mParam2 = bundle.getString(String.valueOf(2)).toString();
        view = inflater.inflate(R.layout.fragment_first, container, false);
        tv_text = view.findViewById(R.id.frag_1_edit);
        btn_submit  = view.findViewById(R.id.frag_first_button);
        btn_submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString(String.valueOf(1),"Ansh");
                bundle.putString(String.valueOf(2),"Yadav 2");
                SecondFragment secondFragment = new SecondFragment();
                secondFragment.setArguments(bundle);
                getParentFragmentManager()
                        .beginTransaction()
                                .replace(R.id.empty_frame,secondFragment)
                                        .commit();
            }
        });
        String data = "Hello " + mParam1 + " "+mParam2;
        tv_text.setText(data);
        return  view;
    }
}