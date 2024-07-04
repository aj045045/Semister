package com.as.bsc.students;

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

    public void openDB() throws SQLException {
        databaseHelper = new DatabaseHelper(context);
        sqLiteDatabase = databaseHelper.getWritableDatabase();
    }

    public void closeDB() {
        databaseHelper.close();
    }

    public long insert(Student student) {
        ContentValues contentValue = new ContentValues();
        contentValue.put(StudentEntity.name, student.name);
        contentValue.put(StudentEntity.age, student.age);
        contentValue.put(StudentEntity.address, student.address);
        contentValue.put(StudentEntity.mobile, student.mobile);
        contentValue.put(StudentEntity.email, student.email);
        return sqLiteDatabase.insert(StudentEntity.TABLE_NAME, null, contentValue);
    }

    public ArrayList<Student> fetchAll() {
        ArrayList<Student> students = new ArrayList<>();
        Cursor c = sqLiteDatabase
                .rawQuery("SELECT * FROM " + StudentEntity.TABLE_NAME, null);
        while (c.moveToNext()) {
            Student s = new Student();
            s.setId(c.getLong(0));
            s.setName(c.getString(1));
            s.setAge(c.getInt(2));
            s.setAddress(c.getString(3));
            s.setMobile(c.getString(4));
            s.setEmail(c.getString(5));
            students.add(s);
        }
        return students;
    }

    public int updateStudent(long _id, Student student) {
        ContentValues contentValue = new ContentValues();
        contentValue.put(StudentEntity.name, student.name);
        contentValue.put(StudentEntity.age, student.age);
        contentValue.put(StudentEntity.address, student.address);
        contentValue.put(StudentEntity.mobile, student.mobile);
        contentValue.put(StudentEntity.email, student.email);
        return sqLiteDatabase.update(StudentEntity.TABLE_NAME, contentValue, StudentEntity._ID + " = " + _id, null);
    }

    public void deleteStudent(long _id) {
        sqLiteDatabase.delete(StudentEntity.TABLE_NAME, StudentEntity._ID + "=" + _id, null);
    }
}
