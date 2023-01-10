CREATE DATABASE Il;
USE Il;

CREATE TABLE CAT(
CATEGORYID numeric(6,3) primary key,
CNAME VARCHAR(25) NOT NULL
);
INSERT INTO CAT VALUE(
'2',
'Refrigerator'
);

INSERT INTO CAT VALUE(
'2',
'Refrigerator'
);

INSERT INTO CAT VALUE(
'4',
'Washing Machine'
);

INSERT INTO CAT VALUE(
'4',
'Washing Machine'
);

 
 INSERT INTO CAT  VALUE(
'8',
'Air Conditioner'
);

INSERT INTO CAT VALUE(
'1',
'Digital Cameras'
);

INSERT INTO CAT VALUE(
'5',
'Telivision'
);

select*from CAT;