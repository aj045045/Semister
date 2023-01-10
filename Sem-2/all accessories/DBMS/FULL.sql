CREATE DATABASE assignment;
USE assignment;

CREATE TABLE deposit(
ACTNO VARCHAR(5)PRIMARY KEY,
CNAME VARCHAR(18),
BNAME VARCHAR(18),
AMOUNT numeric(8,2),
ADATE DATE,
foreign key (CNAME) REFERENCES customer(CNAME),
foreign key (BNAME) REFERENCES branch(BNAME)
);

insert into deposit value(
'100',
'ANIL',
'VRCE',
'1000',
'1995-03-01'
);

insert into deposit value(
'101',
'SUNIL',
'AJNI',
'5000',
'1998-01-04'
);

insert into deposit value(
'102',
'MEHUL',
'KAROLBAGH',
'3500',
'1995-11-17'
);

insert into deposit value(
'104',
'MADHURI',
'CHANDINI',
'1200',
'1995-12-17'
);

insert into deposit value(
'105',
'PRAMOD',
'MGROAD',
'3000',
'1996-03-27'
);

insert into deposit value(
'106',
'SANDIP',
'ANDHERI',
'2000',
'1996-03-31'
);

insert into deposit value(
'107',
'SHIVANI',
'VIRAR',
'1000',
'1995-09-05'
);

insert into deposit value(
'108',
'KRANTI',
'NEHRUPARK',
'5000',
'1995-07-02'
);

insert into deposit value(
'109',
'NAREN',
'POWAI',
'7000',
'1995-08-10'
);

DESC deposit;
select * from deposit;

create table customer(
CNAME VARCHAR(18) primary key,
CITY VARCHAR(18)
);

insert into customer value(
'ANIL',
'CALCUTTA'
);

insert into customer value(
'SUNIL',
'DELHI'
);

insert into customer value(
'MEHUL',
'BARODA'
);

insert into customer value(
'MANDAR',
'PATNA'
);

insert into customer value(
'MADHURI',
'NAGPUR'
);

insert into customer value(
'PRAMOD',
'NAGPUR'
);

insert into customer value(
'SANDIP',
'SURAT'
);

insert into customer value(
'SHIVANI',
'BOMABY'
);

insert into customer value(
'KRANTI',
'BOMBAY'
);

insert into customer value(
'NAREN',
'BOMBAY'
);

desc customer;
select* from customer;

create table borrow(
LOANNO VARCHAR(5) primary key,
CNAME VARCHAR(18),
BNAME VARCHAR(18),
AMOUNT numeric(8,2)
);

INSERT INTO borrow value(
'201',
'ANIL',
'VRCE',
'1000'
);

INSERT INTO borrow value(
'206',
'MEHUL',
'AJNI',
'5000'
);

INSERT INTO borrow value(
'311',
'SUNIL',
'DHARAMPETH',
'3000'
);

INSERT INTO borrow value(
'321',
'MADHURI',
'ANDHERI',
'2000'
);

INSERT INTO borrow value(
'375',
'PRAMOD',
'VIRAR',
'8000'
);

INSERT INTO borrow value(
'481',
'KRANTI',
'NEHRUNAGR',
'3000'
);

DESC borrow;
select * from borrow;

create table branch(
BNAME VARCHAR(18) primary key,
CITY VARCHAR(18)
);

INSERT INTO branch value(
'VRCE',
'NAGPUR'
);

INSERT INTO branch value(
'AJNI',
'NAGPUR'
);

INSERT INTO branch value(
'KAROLBAGH',
'DELHI'
);

INSERT INTO branch value(
'CHANDNI',
'DELHI'
);

INSERT INTO branch value(
'DHARAMPETH',
'NAGPUR'
);

INSERT INTO branch value(
'MGROAD',
'BANGLORE'
);

INSERT INTO branch value(
'ANDHERI',
'BOMABY'
);

INSERT INTO branch value(
'VIRAR',
'BOMBAY'
);

INSERT INTO branch value(
'NEHRUNAGAR',
'DELHI'
);

INSERT INTO branch value(
'POWAI',
'BOMBAY'
);

DESC branch;
select * from branch;

SELECT c.CNAME,c.CITY,d.ACTNO,b.AMOUNT,d.ADATE,b.LOANNO,d.AMOUNT 
FROM customer c
INNER JOIN deposit d 
ON c.CNAME=d.CNAME 
INNER JOIN borrow b
ON d.CNAME=b.CNAME 
WHERE c.CNAME='ANIL';
select* from CUSTOMER;

select c.CNAME
from customer c
WHERE c.CITY='BOMBAY';

