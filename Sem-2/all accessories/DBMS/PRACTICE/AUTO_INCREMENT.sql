CREATE DATABASE IK;
USE IK;

CREATE TABLE CAT(
CATEGORYID INT(2) AUTO_INCREMENT,
CNAME VARCHAR(25) NOT NULL,
PRIMARY KEY(CATEGORYID)
);
INSERT INTO CAT(CNAME) VALUE(
'Refrigerator'
);

INSERT INTO CAT(CNAME) VALUE(
'Washing Machine'
);
 
 INSERT INTO CAT(CNAME) VALUE(
'Air Conditioner'
);

INSERT INTO CAT(CNAME) VALUE(
'Digital Cameras'
);

INSERT INTO CAT(CNAME) VALUE(
'Telivision'
);

select*from CAT;