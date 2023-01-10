create database CS;
use CS;

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
'BOMBAY'
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
