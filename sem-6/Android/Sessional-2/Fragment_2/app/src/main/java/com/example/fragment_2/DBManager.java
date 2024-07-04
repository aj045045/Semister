package com.example.fragment_2;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

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

    public long insert(InputData inputData){
        ContentValues contentValues = new ContentValues();
        contentValues.put(StudentEntity.firstName,inputData.firstName);
        contentValues.put(StudentEntity.lastName,inputData.lastName);
        contentValues.put(StudentEntity.email,inputData.email);
        contentValues.put(StudentEntity.phoneNo,inputData.phoneNo);
        contentValues.put(StudentEntity.address,inputData.address);
        return sqLiteDatabase.insert(StudentEntity.TABLE_NAME,null,contentValues);
    }

    public ArrayList<InputData> fetchAll(){
        ArrayList<InputData>  inputData= new ArrayList<>();
        try (Cursor cursor = sqLiteDatabase.rawQuery("SELECT * FROM " + StudentEntity.TABLE_NAME, null)) {
            while (cursor.moveToNext()) {
                InputData data = new InputData();
                data.setFirstName(cursor.getString(1));
                data.setLastName(cursor.getString(2));
                data.setEmail(cursor.getString(3));
                data.setPhoneNo(cursor.getString(4));
                data.setAddress(cursor.getString(5));
                inputData.add(data);
            }
        }
        return inputData;
    }
    public  void closeDB() {databaseHelper.close();}
}
