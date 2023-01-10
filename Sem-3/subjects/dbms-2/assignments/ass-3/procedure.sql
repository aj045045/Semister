use pra_assi_II;

-- PROCEDURE

-- 1) WAP which accepts the empno and returns the associated empname. If empno does not exist than give proper error message. EMP(Empno, Empname).
create table emp(
emp_id int,
emp_name varchar(20)
);
insert into emp values
(01,'Ayansh'),
(02,'Meet'),
(03,'Samir');

delimiter //
create procedure pro_check_emp(IN v_emp_id int)
begin
DECLARE d_if int DEFAULT 0 ;
 SELECT count(*) INTO d_if FROM emp WHERE EXISTS (SELECT * FROM emp WHERE emp.emp_id = v_emp_id);
	if d_if>0
    THEN
		SELECT * FROM emp WHERE emp_id=v_emp_id;
    else
		SELECT 'We don\'t have that employe';
    END IF;
end //
delimiter ;
call pro_check_emp(3);

-- 2) WAP which accepts the student rollno and returns the name and marks of all the subjects of that student. STUDENT (Stud_ID, Stud_name, m1, m2, m3).
create table student(
stud_id int(2),
stud_name varchar(10),
stud_m1 int(2),
stud_m2 int(2), 
stud_m3 int(2)
);
insert into student values
(01,'Ayan',67,78,89),
(02,'Jame',89,67,56),
(03,'Alex',56,87,98);
delimiter //
create procedure  pro_studentdisplay(IN v_stud_id int(2))
begin
		select * from student where stud_id = v_stud_id;
end //
delimiter ;
call pro_studentdisplay(02);

-- 3) WAP which accepts the name from the user. Return UPPER if name is in uppercase, LOWER if name is in lowercase, MIXCASE if name is entered using both the case.
drop procedure pro_namecase;
delimiter //
create procedure pro_namecase(in v_name varchar(20))
begin
	if v_name = binary upper(v_name)
    then 
    select 'UPPER CASE';
    elseif v_name = binary lower(v_name)
	then 
    select 'LOWER CASE';
    else 
    select "MIXED CASE";
    end if;    
end //
delimiter ;
call pro_namecase('Ansh');

-- 4) WAP which accepts the student rollno and returns the highest percent and name of that student to the calling block. studnets(Stud_ID,Stud_name,percent);
create table students
( 
	stud_id int auto_increment,
    stud_name varchar(20),
    stud_percent int(5),
    primary key(stud_id)
);
insert into students(stud_name,stud_percent) values
('Ankit',40),
('Alfred',60),
('Bravo',45),
('Dom',55);
drop procedure pro_percet;
delimiter //
create procedure pro_percet()
begin 
	select stud_id,stud_name,stud_percent from students where stud_percent=(select max(stud_percent) from students);
end //
delimiter ;
call pro_percet();

-- 5) WAP which accepts the date of joining for specific employee and returns the years of experience along with its name. Accept the Employee no from user.

drop table emps;
create table emps(
empno int, 
empname varchar(15),
doj date,
primary key(empno)
);
insert into emps values(01,'Aryan','2004-04-16'),(02,'Aman','2008-03-12'),(03,'Hetanshu','2016-05-12'),(04,'Shiv','2011-01-01'),(05,'Het','2010-05-11');
drop procedure pro_empexp;
delimiter //
create procedure pro_empexp(in v_id int)
begin 
SELECT empno,empname,doj, concat(round(DATEDIFF(now(),doj )/365)," years") as Experience  FROM emps where empno like v_id;
end //
delimiter ;
call pro_empexp(03);

-- 6) WAP which accepts the student roll no and returns the result (in the form of class: first class, second class, third class or fail). STUDENT (Stud_ID, Stud_name,m1, m2, m3).
create table stud(
stud_id int(2) primary key,
stud_name varchar(10),
m1 int(2),
m2 int(2), 
m3 int(2)
);
insert into stud values
(01,"Ansh",90,95,97),
(02,"Ajay",90,89,89),
(03,"Alex",78,89,89),
(04,"Priya",87,89,67),
(05,"Aman",67,87,89);

drop procedure pro_result;
delimiter //
create procedure pro_result(in v_id int(2))
begin
declare d_total int default 0;
select sum((m1+m2+m3)/3) into d_total from stud where stud_id = v_id;
select "Percentage is: "as txt,d_total as percentage;
end //
delimiter ;
call pro_result(01);