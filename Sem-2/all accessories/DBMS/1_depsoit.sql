create database D;
use D;
create table deposit(
ACTNO VARCHAR(5)primary key,
CNAME VARCHAR(18),
BNAME VARCHAR(18),
AMOUNT numeric(8,2),
ADATE DATE,
FOREIGN KEY (BNAME) REFERENCES branch(BNAME),
FOREIGN KEY(CNAME) REFERENCES customer(CNAME)
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
