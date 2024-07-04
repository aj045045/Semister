package com.example.sql_fragment.Classess;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    static final String DB_NAME = "studentAndroid.db";
    static  final  int DB_VERSION = 2;

    public DatabaseHelper(Context context){
        super(context,DB_NAME,null,DB_VERSION);
    }

    private static final String SQL_CREATE_ENTITY =
            String.format("CREATE TABLE %s(%s INTEGER PRIMARY KEY,%s TEXT,%s TEXT,%s TEXT,%s TEXT,%s TEXT)", StudentEntity.TABLE_NAME, StudentEntity._ID, StudentEntity.firstName, StudentEntity.lastName, StudentEntity.rollNo, StudentEntity.contactNo, StudentEntity.address);

    private static final String SQL_DELETE_ENTITY =
            String.format("DROP TABLE IF EXISTS %s", StudentEntity.TABLE_NAME);

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
            onUpgrade(db,oldVersion,newVersion);
    }
}
