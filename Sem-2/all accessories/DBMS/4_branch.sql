create database BR;
use BR;

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

