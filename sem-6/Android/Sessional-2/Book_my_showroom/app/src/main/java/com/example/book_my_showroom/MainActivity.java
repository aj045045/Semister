package com.example.book_my_showroom;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Spinner spinner;
    MovieView selectedMovieView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        selectedMovieView = findViewById(R.id.main_custom_movie);
        spinner = findViewById(R.id.main_movie);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String mName = parent.getItemAtPosition(position).toString();
                Toast.makeText(MainActivity.this,mName,Toast.LENGTH_SHORT).show();
                selectedMovieView.setMovieName(mName);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }

}