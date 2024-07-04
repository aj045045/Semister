package com.as.bsc.demos;

import android.graphics.drawable.Drawable;

public class TestMovie {
    String title,description;
    Drawable poster;

    public TestMovie(String description, String title, Drawable poster) {
        this.title = title;
        this.description = description;
        this.poster = poster;
    }

    public Drawable getPoster() {
        return poster;
    }

    public void setPoster(Drawable poster) {
        this.poster = poster;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
