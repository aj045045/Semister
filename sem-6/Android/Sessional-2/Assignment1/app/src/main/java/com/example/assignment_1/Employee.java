package com.example.assignment_1;

import android.location.Address;

import java.io.Serializable;

public class Employee implements Serializable {
    String first_name, last_name, address, email, mobile, salary, last_company, last_company_ref,experience,age;

    public String getExperience() {
        return experience;
    }

    public void setExperience(String experience) {
        this.experience = experience;
    }

    public String getFirst_name() {
        return first_name;
    }

    public void setFirst_name(String first_name) {
        this.first_name = first_name;
    }

    public String getLast_name() {
        return last_name;
    }

    public void setLast_name(String last_name) {
        this.last_name = last_name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getMobile() {
        return mobile;
    }

    public void setMobile(String mobile) {
        this.mobile = mobile;
    }

    public String getSalary() {
        return salary;
    }

    public void setSalary(String salary) {
        this.salary = salary;
    }

    public String getLast_company() {
        return last_company;
    }

    public void setLast_company(String last_company) {
        this.last_company = last_company;
    }

    public String getLast_company_ref() {
        return last_company_ref;
    }

    public void setLast_company_ref(String last_company_ref) {
        this.last_company_ref = last_company_ref;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }
}
