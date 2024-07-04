package com.as.bsc.students;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    static final String DB_NAME = "StudentDemo.db";

    // database version
    static final int DB_VERSION = 1;

    public DatabaseHelper(Context context) {
        super(context, DB_NAME, null, DB_VERSION);
    }

    private static final String SQL_CREATE_ENTITY =
            "CREATE TABLE " + StudentEntity.TABLE_NAME + " (" +
                    StudentEntity._ID + " INTEGER PRIMARY KEY," +
                    StudentEntity.name + " TEXT," +
                    StudentEntity.age + " INTEGER," +
                    StudentEntity.address + " TEXT," +
                    StudentEntity.mobile + " TEXT," +
                    StudentEntity.email + " TEXT)";

    private static final String SQL_DELETE_ENTITY =
            "DROP TABLE IF EXISTS " + StudentEntity.TABLE_NAME;

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(SQL_CREATE_ENTITY);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(SQL_DELETE_ENTITY);
        onCreate(db);
    }

    @Override
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }
}
