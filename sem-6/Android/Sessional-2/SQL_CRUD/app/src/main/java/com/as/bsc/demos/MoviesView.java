package com.as.bsc.demos;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.Nullable;

import com.as.bsc.R;

public class MoviesView extends LinearLayout {

    TextView tvMovieName;
    ImageView ivMoviePoster;
    public MoviesView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        init(context, attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        LayoutInflater inflater = (LayoutInflater)
                context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View v = inflater.inflate(R.layout.movies_item, this,true);
        tvMovieName = v.findViewById(R.id.movieView);
        ivMoviePoster = v.findViewById(R.id.movieImage);
        TypedArray attributes = context.obtainStyledAttributes(attrs, R.styleable.moviewview,0,0);
        Drawable image = attributes.getDrawable(R.styleable.moviewview_image);
        String name = attributes.getString(R.styleable.moviewview_name);
        ivMoviePoster.setImageDrawable(image);
        tvMovieName.setText(name);
        attributes.recycle();
    }

    public void setMovieName(String movieName) {
        tvMovieName.setText(movieName);
    }

    public void setMoviePoster(Drawable moviePoster) {
        ivMoviePoster.setImageDrawable(moviePoster);
    }
}
