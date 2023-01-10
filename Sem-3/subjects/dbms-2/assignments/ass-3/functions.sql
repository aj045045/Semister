use pra_assi_ii;
-- FUNCTIONS

-- 1) WAF which accepts the name from user and returns the length of that name.

delimiter //
create function fun_name(v_name varchar(20))
returns int(3) deterministic
begin 
declare d_len int default 0;
select length(v_name) into d_len;
return (d_len);
end 
//
delimiter ;
select fun_name("Ansh_j_yadav") AS LENGTH;
 
-- 2) WAF which accepts one number and return TRUE if no is prime and return FALSE if No. is not prime.

drop function fun_prime_notprime;
delimiter //
create function fun_prime_notprime(v_num int)
returns varchar(10) deterministic
begin 
	Declare i int default 2;
    
		if i < v_num and mod(v_num,i) = 0 
        THEN
			return 'NOT PRIME';
        end if;
		SET i = i + 1;
    return ' PRIME';

end //
delimiter ;
select fun_prime_notprime(10) as Find_Prime;


-- 3) Write a function which accepts the department no and returns maximum salary of that
-- 	  Department. Handle the error if deptno does not exist or select statement return more than
--    one row. EMP(Empno, deptno, salary).

create table empo(
empno int(4) primary key,
deptno int(4),
salary int(6)
);
insert into empo values
(01,001,45000),
(02,002,30000),
(03,004,67000),
(05,008,35000),
(08,008,56000),
(09,002,8000);

drop function fun_emp;
delimiter //
create function fun_emp(v_deptno int(6))
returns varchar(10) deterministic
begin 
declare d_val int(6) default 0000; 
declare d_inp varchar(10);
    if  (select exists ( select deptno from empo where deptno like v_deptno))
    then 
	select max(salary) into d_val from empo where Exists (select  * from emp where deptno like v_deptno);
		return (d_val);
    else 
    select "Not found" into d_inp;
    return (d_inp);
    end if;
end //
delimiter ;
select fun_emp(008);

-- 4) Write a function to display whether the entered (User Input) employee no exists or not.

drop function fun_input;
delimiter //
create function fun_input(v_empno int(4))
returns varchar(20) deterministic
begin 
declare d_var varchar(20);
		if (select exists(select empno from empo where empno like v_empno))
        then
			select "Record Exists" into d_var;
		else
			select "Record Not Exists" into d_var;
        end if;
        return (d_var);
end //
delimiter ;
select fun_input(09) as Find_emp;

-- 5) WAF which accepts one no and returns that no+100. Use INOUT mode.

delimiter //
create function fun_return( v_num  int(5) )
returns int(5) deterministic
begin 
	return v_num+100;
end //
delimiter ;
select fun_return(100);

-- 6) WAF which accepts the empno.
-- If salary<10000 than give raise by 30%.
-- If salary<20000 and salary>=10000 than give raise by 20%.
-- If salary>20000 than give raise by 10%. Handle the error if any.

delimiter //
create function fun_raise(v_empno int(4))
returns varchar(50) deterministic
begin
	declare d_salary int(5) default 0;
	declare d_return int(5) default 100; 
    select salary into d_salary from empo where  empno = v_empno;
	if d_salary > 0 then
						if d_salary < 10000 then 
								set d_return = d_salary*0.3; 
						elseif d_salary>=10000 and d_salary<20000  then 
							set d_return = d_salary*0.2;
						elseif d_salary>=20000	then 
							set d_return = d_salary*0.1;
                        end if;
		update empo
		set salary = d_salary + d_return
		where empno=v_empno;
    return concat("Salary raise by ",d_return,"\n New salary will be ",d_salary+d_return);
        else
            return concat("NOT EXISTS ",d_salary, d_return);       
	end if;   
 end//
 delimiter ;
drop function fun_raise; 
 select fun_raise(08);

-- 7) WAF which accepts the empno and returns the experience in years. Handle the error if
-- empno does not exist.

delimiter //
create function fun_exp(v_empno int)
returns varchar(40) deterministic
begin 
	declare d_int date ;
    select doj into d_int from emps where empno= v_empno;
    if d_int != 0 then
         return  concat(round(DATEDIFF(now(),d_int )/365)," years");
    else
    return "Employee does not exists";
    end if;
end //
delimiter ;
drop function fun_exp;
select fun_exp(01)as Experience;
