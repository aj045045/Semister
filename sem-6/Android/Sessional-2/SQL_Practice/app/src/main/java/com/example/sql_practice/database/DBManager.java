package com.example.sql_practice.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.sql_practice.classes.StudentDetail;

import java.util.ArrayList;

public class DBManager {
    private final Context context;
    private DatabaseHelper databaseHelper;
    private SQLiteDatabase sqLiteDatabase;
    public DBManager(Context context) {
        this.context = context;
    }

    public void openDB() throws SQLException {
            databaseHelper = new DatabaseHelper(context);
            sqLiteDatabase = databaseHelper.getWritableDatabase();
    }

    public  long insertQuery(StudentDetail studentDetail){
        ContentValues contentValues = new ContentValues();
        contentValues.put(StudentEntity.firstName,studentDetail.getName());
        contentValues.put(StudentEntity.age,studentDetail.getAge());
        contentValues.put(StudentEntity.course,studentDetail.getCourse());
        contentValues.put(StudentEntity.mail,studentDetail.getMail());
        contentValues.put(StudentEntity.phoneNo,studentDetail.getPhoneNo());
        return sqLiteDatabase.insert(StudentEntity.TABLE_NAME,null,contentValues);
    }

    public int updateQuery(long _id,StudentDetail studentDetail){
        ContentValues contentValues = new ContentValues();
        contentValues.put(StudentEntity.firstName,studentDetail.getName());
        contentValues.put(StudentEntity.age,studentDetail.getAge());
        contentValues.put(StudentEntity.course,studentDetail.getCourse());
        contentValues.put(StudentEntity.mail,studentDetail.getMail());
        contentValues.put(StudentEntity.phoneNo,studentDetail.getPhoneNo());
        return sqLiteDatabase.update(StudentEntity.TABLE_NAME,contentValues,StudentEntity._ID + "="+_id,null);
    }

    public void deleteQuery(long _id){
        sqLiteDatabase.delete(StudentEntity.TABLE_NAME,StudentEntity._ID+"="+_id,null);
    }
    public ArrayList<StudentDetail> fetchAllQuery(){
        ArrayList<StudentDetail> studentDetails = new ArrayList<>();
        try (Cursor cursor = sqLiteDatabase.rawQuery("SELECT * FROM " + StudentEntity.TABLE_NAME, null)) {
            while (cursor.moveToNext()){
                    StudentDetail studentDetail = new StudentDetail();
                studentDetail.setId(cursor.getString(0));
                studentDetail.setName(cursor.getString(1));
                studentDetail.setAge(cursor.getString(2));
                studentDetail.setCourse(cursor.getString(3));
                studentDetail.setMail(cursor.getString(4));
                studentDetail.setPhoneNo(cursor.getString(5));
                studentDetails.add(studentDetail);
            }
        }
        return studentDetails;
    }
    public void closeDB(){
        databaseHelper.close();
    }
}
