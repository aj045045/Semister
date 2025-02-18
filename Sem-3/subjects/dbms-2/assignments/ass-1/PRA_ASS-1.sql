create database ass;
use ass;

-- 1 Print the absolute value of –15.35
select abs(-15.20);

-- 2 Calculate 3.25 raised to 2.25
select pow(3.25,2.25);

-- 3 Display the rounded value of 3.1417 upto 3 decimal places.
SELECT round(3.1417,3);

-- 4 Display the truncated value of 3.1417 upto 3 decimal places.
SELECT  truncate(3.1417,3);

-- 5 Find the square root of 17 and –13 if possible.
SELECT  sqrt(17);

-- 6 Print the value of e to the 5th power
 SELECT  exp(5);
 
-- 7 Print the ceil value and floor value of 15.72
 SELECT  ceil(15.72);
 
-- 8 Find the value of 13 mod 5
 SELECT  mod(13,5);
 
-- 9 Add 275 months to your date of birth and display it.
 SELECT  adddate("2004-05-18",INTERVAL 275 DAY);
 
 -- 10 Find the value sin of 100, and log 100 to the base 10 
SELECT  sin(100),LOG10(100);
 
-- -> Create a database of books :- (no, title, author, publication, price, edition)

CREATE TABLE BOOKS (
ID INT auto_increment ,
TITLE VARCHAR(100),
AUTHOR VARCHAR(20),
PUBLICATION VARCHAR(20),
PRICE VARCHAR(20),
EDITION VARCHAR(20)
);

DESC BOOKS;

ALTER TABLE BOOKS
MODIFY TITLE VARCHAR(100);

INSERT INTO BOOKS VALUES
("","BOOK1","ALEX","VLC","20,000","ED-4"),
("","BOOK4","VIJAY","KKR","1500","ED-2"),
("","C++","JAMES","RRR","3000","ED-3"),
("","FUNDAMENTALS OF PROG.","ADHEERA","PHI","4000","ED-4"),
("","BOOK5","priya","ers","4000","ed-7");

-- 11 List the names of author starting with capital letter.
SELECT distinct author from BOOkS where ASCII(left(author, 1)) between ASCII('A') and ASCII('Z');

-- 12 Display the name of book in both lower and upper case using a single query.
SELECT distinct upper(title)as upper,lower(title)as lower from books ;
 
 -- 13 Display the output : ‘BAD’ using CHR function.
/////////////////////////////////////////////////////////////
 
 -- 14 Display the price of books in the following format : ****450
 
 -- 15 Display the price of books in the following format : 450*/*/
SELECT  ;
 
 -- 16 Display the publication of PHI as Pearson (Use replace…)
SELECT  distinct replace('PHI','PHI','pearson') from books where publication like 'PHI' ;
 
 -- 17 Display the title of books and trim the ending part if it ends with prog.
SELECT title from books where title like '%prog.' ;
 
 -- 18 Display the titles of books which contains ‘++’ in it.
SELECT title from books where title like '%c++%';
 
 -- 19 Modify the column size of author.
desc books;
alter table books 
modify author varchar(100);
 
 -- 20 Add a new column author2 to the table.
alter table books
add column author2 varchar(20);
desc books;

-- Create a table stud_marks which contains (no, fname, lname, m1, m2, m3, dob)

create table marks (
ID Int auto_increment PRIMARY KEY,
FNAME VARCHAR(20),
LNAME VARCHAR(20),
M1 VARCHAR(20),
M2 VARCHAR(30),
M3 VARCHAR(50),
DOB DATE
);


-- 1 m1,m2,m3 :- marks of 3 subjects, Enter atleast 10 values in this table

insert into marks(FNAME,LNAME,M1,M2,M3,DOB) VALUES 
("VIJAY","DEVRAKONDA","80","40","50","2008-06-04"),
("ALEX","PRATAP","60","84","73","2005-09-11"),
("HARSH","DEDAKIYA","88","45","72","2003-11-12"),
("NIDHI","CHAVDA","72","66","78","2004-07-28"),
("EKTA","AGJA","89","67","88","2004-09-24"),
("ANKIT","YADAV","45","50","70","2004-11-30"),
("TEJ","DOSHI","77","59","44","2004-03-26"),
("PRADIP","SING","77","45","66","2003-06-22"),
("JETHALAL","GADA","55","89","67","2004-11-30"),
("ALBERT","SAAHO","56","89","34","2004-11-23");
 
 -- 2 Display the details in following order :- RollNo. Lname, Fname
SELECT  ID,LNAME,FNAME FROM MARKS ORDER by FNAME ASC ;
 
 -- 3 Find the current age of each student.
SELECT TIMESTAMPDIFF(YEAR, dob, CURDATE()) AS age FROM MARKS; 
 
 -- 4 Display the total marks of each student along with the rollno
SELECT FName,lname,M1+M2+M3 AS TOTAL FROM MARKS;
 
 -- 5 Display the percentage of each student
SELECT  FNAME,LNAME ,(M1+M2+M3*100)/300 AS PERCENTAGE FROM MARKS ORDER BY FNAME ASC;
 
 -- 6 Display the students scoring highest marks in each subject.
SELECT distinct FNAME,Lname FROM MARKS where m1+m2+m3  In (select max(m1+m2+m3) from marks);
 
 -- 7 Display the students scoring highest total marks
 SELECT distinct FNAME,Lname,m1+m2+m3 as total FROM MARKS where m1+m2+m3  In (select max(m1+m2+m3) from marks);

 
 -- 8 Display the students whose name starts with ‘S’.
SELECT FNAME FROM MARKS WHERE FNAME LIKE 'S%';
 
-- 9 Display the students whose surname ends with ‘kar’
SELECT FNAME,LNAME FROM MARKS WHERE LNAME LIKE '%KAR';
 
-- 10 List all the students who fails in any one of the subjects.
SELECT DISTINCT FNAME,M1 AS FAIL_M1,M2 AS FAIL_M2 ,M3 AS FAIL_M3  FROM MARKS WHERE M1 < 40 OR M2 <40 OR M3 < 40 ;
 
 -- 11 List all the students who are passing in all subjects but the percentage < 60
SELECT DISTINCT FNAME, (M1+M2+M3*100)/300 AS PERCENTAGE FROM MARKS WHERE (M1+M2+M3*100)/300 < 60 ;
 
 -- 12 List the students whose total marks are between 50 and 60
SELECT DISTINCT FNAME, (M1+M2+M3*100)/300 AS PERCENTAGE FROM MARKS WHERE (M1+M2+M3*100)/300 between 50  and 60 ;
 
 -- 13 List all the students whose name does not start with ‘S’
SELECT distinct FNAME FROM MARKS WHERE FNAME not LIKE 'S%';
 
 -- 14 Update the table, set marks m1=40 for those students who scored a total of atleast 100 marks in m2 and m5

 
 -- 15 Display the students whose marks are either 50, 60 or 70.
 
 -- 16 List all the students born in the month of January.
SELECT distinct fname  as jan from marks where month(dob)=6;
 -- 17 List all the students whose date of birth is even no.
SELECT distinct fname  as jan from marks where day(dob)=%2; 
SELECT distinct fname,dob FROM marks WHERE dob IN(SELECT dob FROM marks WHERE dob%2 = 0) ;
 
 -- 18 Find the age of students in terms of months passed

 
 -- 19 Display the students whose date of birth falls in the first quarter of the year
SELECT distinct fname,dob from marks where dob in (select dob from marks where quarter(dob)=1);
 
 -- 20 Find the date, 15 days after today’s date.
SELECT distinct Fname,date_add(current_date(),Interval 15 day)  as Days from marks;

 -- 21 List the students whose name contains vowels (small)

 -- 22 List the students whose name does not contain vowels

 
 -- 23 Count the no. of students whose name starts with ‘S’
SELECT  count(Fname) As S from marks where fname like 'e%';
 
 -- 24 Count the no. of students whose name ends with ‘kar’
 -- problem on code
SELECT  distinct fname,count(Fname) As S from marks where fname like '%sh';
 
 -- 25 Display the names of student in following format Eg. If name is ‘hardik’ & surname is ‘joshi’ then display ‘harshi’
SELECT  ;
 
 -- 26 Display the rows which contains null values in m1, m2 or m3
SELECT  * from marks where null like m1 and m2 and m3;
 
 -- 27 Display the rows which does not contain null values in name
SELECT  ;
 
 -- 28 Display the rows where name sounds like ‘sachin’ (use soundex function)
SELECT  ;
 
 -- 29 Generate a random no. using date
SELECT  rand(curdate()) ;
 
 -- 30 Display the output in following form :- <Name was born on Day> Eg. Hardik was born on Thursday
 SELECT  format(fname , '<############## was born on thurshday>') from marks;
 
 