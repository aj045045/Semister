use pra_assi_ii;

-- CURSORS

-- 1) Create a cursor for the emp table. Produce the output in following format:
-- {empname} employee working in department {deptno} earns Rs. {salary}. EMP(empno, empname, salary, deptno);

create table emp01(
empno varchar(10) not null primary key,
empname varchar(15),
salary int, 
deptno varchar(10)
);

insert into emp01 values
("emp01","Ansh",10000,"dep01"),
("emp02","Ankit",12000,"dep01"),
("emp03","Harsh",14000,"dep02"),
("emp04","Devansh",16000,"dep02"),
("emp05","Tej",20000,"dep03"),
("emp08","Ekta",24000,"dep02"),
("emp09","Nidhi",22000,"dep03"),
("emp10","Janvi",21000,"dep03"),
("emp06","Aryan",15000,"dep04"),
("emp07","Trupal",10000,"dep04");

truncate table emp01;
select * from emp01;
delimiter //
create procedure cur_format()
begin
	declare eid varchar(6) default "";
    declare ename varchar(15) Default "";
    declare sal int default 0;
    declare chk bool default false;
    declare dep varchar(6) default "";
    declare record varchar(5000) default "";
    Declare empData cursor for select * from emp01;
    declare continue handler for not found set chk = true;
    open empData;
    myemp: loop
		if chk = true then
        leave myemp;
        end if;
    fetch empData into eid,ename,sal,dep;
    set record= concat(record,"\n",ename," is working in department ",dep," earns Rs. ",sal);
    end loop myemp;
    select record;
    close empData;
end //
delimiter ;
drop procedure cur_format;
call cur_format();

-- 2) Create a cursor for updating the salary of emp working in deptno dep02 by 20%.
-- If any rows are affected than display the no of rows affected. Use implicit cursor.
delimiter //
create procedure q2(in v_id varchar(10))
begin 
	declare count int;		
		update emp01
        set salary = salary+(salary*20/100) 
        where deptno=v_id; 
        select * from emp01;
end //
delimiter ;
call q2('dep02');

-- 3) Create a cursor for updating the salary of emp working in deptno 10 by 20%. Use explicit cursor. EMP(empno, empname, salary, deptno);

    delimiter //
    create procedure q3(in v_id varchar(10), out var int)
    begin
		declare flag int default 0;
        declare emp_no varchar(10) default '';
        declare count int default -1;
        declare cur cursor for select empno from emp01 where deptno = v_id;
        declare continue handler  for not found set flag =1;
        open cur;
        aj:loop
        if flag =1 then 
        leave aj;
        end if;
          fetch cur into emp_no;
        update emp01
        set salary = salary+(salary*20/100)
        where deptno=v_id;
        set count=count+1;
        end loop aj;
        select count into var;
        close cur;
    end //
    delimiter ;

drop procedure q3;
call q3("dep04",@q3_diemployeesplay);
select @q3_display as No_of_rows_updated;

-- 4) WAP that will display the name, department and salary of the first 5 employees getting the highest salary.
	
    delimiter //
    create procedure q4()
    begin
		declare v_name varchar(6);
        declare v_dep varchar(15);
        declare v_salary int;
        declare v_city varchar(20);
		declare record varchar(255) default "";
        declare flag int default 0;
        declare cur cursor for select * from employee order by(e_salary) desc limit 5;
        declare continue handler for not found set flag =1;
        open cur;
        var:loop
        fetch cur into v_name,v_dep,v_salary,v_city;
			if flag =1 then
            leave var;
            end if;
        set record = concat(record,v_name,",",v_dep,",",v_salary,"/");
        end loop var;
        close cur;
        select record;
    end //
    delimiter ;
    drop procedure q4;
    call q4();
    
-- 5) Write a procedure using parameterized cursor to display all the information of employee living in specified city. Ask the city from user.
    
	desc employee;
    delimiter //
    create procedure q5( e_ct varchar(20))
    begin
    declare flag bool default false;
	declare v_no int(3);
	declare v_name,v_city varchar(20);
    declare v_salary varchar(50);
	declare record varchar(1000) default '';
	declare cur cursor 
    for select * from employee 
    where e_city = e_ct;
	declare continue handler for not found set flag = true;
        open cur;
        aj:loop
            fetch cur into v_no,v_name,v_salary,v_city;
        if flag then
        leave aj;
        end if;
        set record=concat(record,v_no,' ',v_name,' ',v_salary,' ',v_city,'/ ');
       end loop aj;
       select record;
        close cur;
    end //
    delimiter ;
drop procedure if exists q5;
    call q5("ahmedabad");
    
-- 6) WAP which display the sum of salary department wise

delimiter //
create procedure q6()
begin
	declare isfound int default 0;
	declare dname varchar(20);
	declare record varchar(2000) default ' ';
	declare sal int;
	
    declare dptSal cursor for 
    select  deptno,sum(salary) 
    from emp01 
	group by deptno;
	declare continue handler for not found set isfound = 1;
    
	open dptSal;
	lup:loop
		fetch dptSal into dname, sal;
		if isfound then
			leave lup;
		end if;
		set record = concat(record,'Department name ',dname,' total salary ',sal,'/ ');
	end loop;
	SELECT record;
	close dptSal;
end //
delimiter ;
drop procedure if exists q6;
call q6();

-- 7) Create a cursor to generate different two tables from one master table.
-- Student(Rno, Name, Std, B_date, Sex);
-- Girl_Table(Rno, Name, Std, B_date);
-- Boy_Table(Rno, Name, Std, B_date);
-- First fetch the row from Student table. If sex is ‘M’ then insert that row in Boy_Table
-- and if ‘F’ then insert that row in Girl_Table. In both table Rollno entry must be in Sequence(Using create sequence command).

create table q7_student(rollno int,name varchar(20),std int,dob date,sex char);
create table q7_boy(rollno int,name varchar(20),std int,dob date);
create table  q7_girl(rollno int,name varchar(20),std int,dob date);
insert into q7_student values
(01,"EKTA",07,'2004-04-07','F'),
(03,"JANVI",08,'2004-05-18','F'),
(04,"NIDHI",09,'2004-05-29','F'),
(06,"HARSH",10,'2004-05-10','M'),
(08,"TEJ",06,'2004-03-26','M'),
(11,"ARYAN",05,'2004-05-13','M'),
(14,"TRUPAL",04,'2004-06-18','M'),
(15,"DEVANSH",03,'2004-07-17','M'),
(35,"ANKIT",07,'2004-05-22','M'),
(36,"ANSH",08,'2004-05-18','M');

delimiter //
create procedure q7()
begin
	declare v_roll,v_std int default 0;
    declare v_name,v_dob,v_sex varchar(20);
	declare flag bool default true;
    declare cur cursor for select * from q7_student;
    declare continue handler for not found set flag = false;
    open cur;
    lp:loop
    	fetch cur into v_roll,v_name,v_std,v_dob,v_sex;
    if flag = false then
		leave lp;
    end if;
        case v_sex
			when 'F' then
            insert  into q7_girl values(v_roll,v_name,v_std,v_dob);
            when 'M' then
            insert into q7_boy values(v_roll,v_name,v_std,v_dob);
            end case;
    end loop lp;
end //
delimiter ;
drop procedure q7;
call q7();
select * from q7_boy;
select * from q7_girl;
select * from q7_student;
truncate table q7_girl;
truncate table q7_boy;
