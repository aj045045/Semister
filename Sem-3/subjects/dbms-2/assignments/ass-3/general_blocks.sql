use pra_assi_ii;

-- GENERAL PL/SQL BLOCKS:

-- 1) WAP to input two numbers and find out what is the output of all arithmetic operations.
-- (Addition, Subtraction, Multiplication, Division etc.)

delimiter //
 create procedure pro_arithmetic(a int, b int)
begin
	select a+b as Addition ,a-b as Subtraction ,a*b as Multipication, round(a/b) as Division;
end //
delimiter ;
drop procedure pro_arithmetic;
call pro_arithmetic(5,6);

-- 2) WAP to input rollno and three subject marks. Find out total, percentage, result and
-- grade for the student from the entered data.

delimiter //
create procedure stu_grades(in v_rollno int ,in m1 int,in m2 int,in m3 int,out total int, out percent int, out grade char)
begin
	set total = m1+m2+m3;
    set percent = total/3;
    if percent >= 80 then
		set grade = 'A';
	elseif percent >= 75 then
		set grade = 'B';
	elseif percent >= 40 then
		set grade = 'C';
	else
		set grade = 'F';
	end if;
end //
delimiter ;
drop procedure stu_grades;
call stu_grades(36,50,50,50,@total,@percent,@grade);
select @total as Total,@percent as Percentage,@grade as Grade;

-- 3) WAP to print first 10 odd numbers using for loop.

delimiter //
create procedure odd_num()
begin
declare j  int default 1;
declare num varchar(80) default "";
declare i  int default 1;
	odd:
    loop
			if j > 10 then leave odd; end if;
        if i%2 != 0 
        then
        set num = concat(num,i,", ");
        set j=j+1;
        end if;
		set i=i+1;
    end loop odd;
    select num as ODD_NUMBER;
end //
delimiter ;
drop procedure odd_num;
call odd_num();

-- 4) WAP to print prime numbers upto 10 using while loop.
delimiter //
create procedure prime_num()
begin
declare prime varchar(50) default "";
declare num int default 1;
		while num<10
        do
        if(num%2)=1 then
        set prime = concat(prime,num,", ");
        end if;
        set num = num+1;
        end while;
        select prime;
end //
delimiter ;
drop procedure prime_num;
call prime_num();

-- 5) WAP to input three nos and find out maximum and minimum from it.

delimiter //
create procedure max_min(in a int, in b int,in c int, out max int, out min int)
begin
--    MAXIMUM
	 if a>b and a>c then
     set max = a;
     elseif b>a and b>c then
     set max = b;
     else 
     set max = c;
     end if;

-- MINIMUM
	if a<b and a<c then
     set min = a;
     elseif b<a and b<c then
     set min = b;
     else 
     set min = c;
     end if;
end //
delimiter ;
call max_min(50,40,10,@max,@min);
select @max as MAXIMUM, @min as MINIMUM;

-- 6) WAP to input empno from keybord. Check whether inputed empno exist in emp table
-- or not. If not give error message otherwise display name and salary of that employee.

create table employee(
e_no varchar(6) primary key,
e_name varchar(15) NOT NULL,
e_salary int(6),
e_city varchar(20)
);

drop table employee;
insert into employee values
("001","Ansh",150000,"ahmedabad"),
("002","Aj",130000,"ahmedabad"),
("003","Ekta",200000,"surat"),
("004","Nidhi",130000,"surat"),
("005","Ankit",100000,"surat"),
("006","Janvi",160000,"ahmedabad"),
("007","Tej",130000,"nagpur"),
("008","Devansh",140000,"nagpur"),
("009","Aryan",130000,"nagpur"),
("010","Harsh",100000,"ahmedabad");
    
delimiter //
create procedure emp_exists(in v_empno int, out v_name varchar(10), out v_salary int(6))
begin
	declare d_find bool default true;
    declare continue handler for not found set d_find = false;
	select e_name,e_salary into v_name,v_salary from  employee where e_no = v_empno ;
    if d_find = false then
	select "NOT FOUND EMPLOYEE" ;
    end if;
end //
delimiter ;
drop procedure emp_exists;
call emp_exists(01,@ename,@esalary);
select @ename as Name,@esalary as Salary;

-- 7) WAP to insert record in Customer table. Customer(cust_id,cust_name,address,city);
create table customer(
cust_id varchar(5),
cust_name varchar(10),
address varchar(30),
city varchar(20)
);
 
 delimiter //
 create procedure pro_insertCustomer(v_id varchar(5),v_name varchar(10),v_address varchar(30),v_city varchar(20))
 begin
	insert into customer values(v_id,v_name,v_address,v_city);
 end //
 delimiter ;
 call pro_insertCustomer(01,"Harsh","7/34 krishna palace,nikol","Ahmedabad");
 select * from customer;