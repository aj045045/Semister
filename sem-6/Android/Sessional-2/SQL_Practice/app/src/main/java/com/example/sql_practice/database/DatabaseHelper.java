package com.example.sql_practice.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    static  final String DB_NAME = "studentManager.db";
    static  final int DB_VERSION = 1;

    public DatabaseHelper(Context context) {
        super(context,DB_NAME,null,DB_VERSION);
    }
    private static final String SQL_CREATE_QUERY = String.format("CREATE TABLE %s(%s INTEGER PRIMARY KEY,%s TEXT,%s TEXT ,%s TEXT ,%s TEXT,%s TEXT);",StudentEntity.TABLE_NAME,StudentEntity._ID,StudentEntity.firstName,StudentEntity.age,StudentEntity.course,StudentEntity.mail,StudentEntity.phoneNo);
    private static final String SQL_DROP_QUERY = String.format("DROP TABLE IF EXISTS %s;",StudentEntity.TABLE_NAME);

    @Override
    public void onCreate(SQLiteDatabase db) {
    db.execSQL(SQL_CREATE_QUERY);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(SQL_DROP_QUERY);
        onCreate(db);
    }

    @Override
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }
}
