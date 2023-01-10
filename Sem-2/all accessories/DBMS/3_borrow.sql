create database BO;
use BO; 

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
