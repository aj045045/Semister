package com.example.practice_1.classes;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    static  final String DB_NAME = "student.db";
    static  final int VERSION = 1;

    public DatabaseHelper(@Nullable Context context) {
        super(context, DB_NAME, null, VERSION);
    }

    private static final String CREATE = String.format("CREATE TABLE %s ( %s INTEGER PRIMARY KEY, %s TEXT, %s INTEGER, %s TEXT, %s TEXT, %s TEXT ) ",StudentEntity.TABLE_NAME,StudentEntity._ID,StudentEntity.name,StudentEntity.age,StudentEntity.address,StudentEntity.mobile,StudentEntity.email);

    private  static  final String DELETE = String.format("DROP TABLE IF EXISTS %s",StudentEntity.TABLE_NAME);
    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(DELETE);
        onCreate(db);
    }

    @Override
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }
}
