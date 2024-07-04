package com.example.practice_1.classes;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;

public class DBManager{
    private  final Context context;
    private DatabaseHelper databaseHelper;
    private SQLiteDatabase sqLiteDatabase;
    public DBManager(Context context){
        this.context = context;

    }

    public void openDB() throws SQLException {
        databaseHelper = new  DatabaseHelper(context);
        sqLiteDatabase = databaseHelper.getWritableDatabase();
    }

    public void closeDB(){
        databaseHelper.close();
    }

    public  long insertStudent(StudentModel studentModel){
        ContentValues values = new ContentValues();
        values.put(StudentEntity.name,studentModel.name);
        values.put(StudentEntity.age,studentModel.age);
        values.put(StudentEntity.address,studentModel.address);
        values.put(StudentEntity.email,studentModel.email);
        values.put(StudentEntity.mobile,studentModel.mobile);
        return sqLiteDatabase.insert(StudentEntity.TABLE_NAME,null,values);
    }

    public ArrayList<StudentModel> fetchAllStudent(){
        ArrayList<StudentModel> list = new ArrayList<>();
        Cursor cursor = sqLiteDatabase.rawQuery("SELECT * FROM " + StudentEntity.TABLE_NAME,null);
        while(cursor.moveToNext()) {
            StudentModel model = new StudentModel();
            model.setId(cursor.getLong(0));
            model.setName(cursor.getString(1));
            model.setAge(cursor.getInt(2));
            model.setAddress(cursor.getString(3));
            model.setEmail(cursor.getString(5));
            model.setMobile(cursor.getString(4));
            list.add(model);
        }
        return  list;
    }

    public int updateStudent(long _id,StudentModel studentModel ){
        ContentValues values = new ContentValues();
        values.put(StudentEntity.name,studentModel.name);
        values.put(StudentEntity.age,studentModel.age);
        values.put(StudentEntity.address,studentModel.address);
        values.put(StudentEntity.email,studentModel.email);
        values.put(StudentEntity.mobile,studentModel.mobile);
        return sqLiteDatabase.update(StudentEntity.TABLE_NAME,values,StudentEntity._ID + "=" + _id,null);
    }

    public void deleteStudent(long _id){
        sqLiteDatabase.delete(StudentEntity.TABLE_NAME,StudentEntity._ID + "=" + _id,null);
    }
}
