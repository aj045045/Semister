package com.example.sql_fragment.Classess;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;

public class DBManager {
    private final Context context;
    private DatabaseHelper databaseHelper;
    private SQLiteDatabase sqLiteDatabase;

    public DBManager(Context context) {
        this.context = context;
    }

    public void openDB() throws SQLException{
        databaseHelper = new DatabaseHelper(context);
        sqLiteDatabase = databaseHelper.getWritableDatabase();
    }

    public void closeDB(){
        databaseHelper.close();
    }

    public long insertQuery(Student student){
        ContentValues contentValues = new ContentValues();
        contentValues.put(StudentEntity.firstName,student.firstName);
        contentValues.put(StudentEntity.lastName,student.lastName);
        contentValues.put(StudentEntity.rollNo,student.rollNo);
        contentValues.put(StudentEntity.contactNo,student.contactNo);
        contentValues.put(StudentEntity.address,student.address);
        return sqLiteDatabase.insert(StudentEntity.TABLE_NAME,null,contentValues);
    }

    public int deleteQuery(String id){
        return sqLiteDatabase.delete(StudentEntity.TABLE_NAME, "_id=?",new String[]{id});
      }

    public int updateQuery(Student student, String id){
        ContentValues contentValues = new ContentValues();
        contentValues.put(StudentEntity.firstName,student.firstName);
        contentValues.put(StudentEntity.lastName,student.lastName);
        contentValues.put(StudentEntity.rollNo,student.rollNo);
        contentValues.put(StudentEntity.contactNo,student.contactNo);
        contentValues.put(StudentEntity.address,student.address);
        return sqLiteDatabase.update(StudentEntity.TABLE_NAME,contentValues,"id=?",new String[]{id});
    }
    public ArrayList<Student> fetchAllQuery(){
        ArrayList<Student> studentArrayList = new ArrayList<>();
        try (Cursor cursor = sqLiteDatabase.rawQuery("SELECT * FROM " + StudentEntity.TABLE_NAME, null)) {
            while (cursor.moveToNext()) {
                Student student = new Student();
                student.setFirstName(cursor.getString(1));
                student.setLastName(cursor.getString(2));
                student.setRollNo(cursor.getString(3));
                student.setContactNo(cursor.getString(4));
                student.setAddress(cursor.getString(5));
                studentArrayList.add(student);
            }
        }
        return studentArrayList;
    }
}
