package com.as.bsc.demos;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Spinner;
import android.widget.Toast;


import androidx.appcompat.app.AppCompatActivity;

import com.as.bsc.R;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    MoviesView selectedMovieView;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        selectedMovieView = findViewById(R.id.selectedMovie);
        ArrayList<TestMovie> testMovies = new ArrayList<>();
        TestMovie testMovie = new TestMovie("Description","title",getDrawable(R.drawable.baseline_movie_24));
        testMovies.add(testMovie);

        Spinner spinner = findViewById(R.id.spMovie);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String mName = parent.getItemAtPosition(position).toString();
                Toast.makeText(MainActivity.this, mName, Toast.LENGTH_SHORT).show();
                selectedMovieView.setMovieName(mName);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
//
            }
        });

        /*Button btn = findViewById(R.id.buttonClick);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new AlertDialog.Builder(MainActivity.this)
                        .setTitle("Alert Dialog")
                        .setMessage("Welcome")
                        .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                            }
                        })
                        .setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                                Toast.makeText(MainActivity.this,"Clicked button",Toast.LENGTH_LONG).show();
                            }
                        })
                        .show();
            }
        });*/
    }
}
