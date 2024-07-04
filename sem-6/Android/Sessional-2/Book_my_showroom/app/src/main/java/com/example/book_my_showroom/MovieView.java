package com.example.book_my_showroom;

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

public class MovieView extends LinearLayout {

    TextView tvMovieName;
    ImageView ivMoviePoster;
    public MovieView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        init(context,attrs);
    }

    private void init(Context context, AttributeSet attrs) {
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View v =  inflater.inflate(R.layout.actvity_item,this,true);
         ivMoviePoster = v.findViewById(R.id.item_image);
        tvMovieName = v.findViewById(R.id.item_name);
        TypedArray attributes = context.obtainStyledAttributes(attrs,R.styleable.movie_view,0,0);
        Drawable image = attributes.getDrawable(R.styleable.movie_view_image);
        String name = attributes.getString(R.styleable.movie_view_name);
        ivMoviePoster.setImageDrawable(image);
        tvMovieName.setText(name);
        attributes.recycle();
    }
    public void setMovieName(String movieName){
        tvMovieName.setText(movieName);
    }
    public  void  setMoviePoster(Drawable moviePoster){
        ivMoviePoster.setImageDrawable(moviePoster);
    }
}
