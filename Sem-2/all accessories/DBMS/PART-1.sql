SELECT c.CNAME,c.CITY,d.ACTNO,b.AMOUNT,d.ADATE,b.LOANNO,d.AMOUNT 
FROM customer c
INNER JOIN deposit d 
ON c.CNAME=d.CNAME 
INNER JOIN borrow b
ON d.CNAME=b.CNAME 
WHERE c.CNAME='ANIL';

select customer.CNAME 
FROM customer 
INNER JOIN branch 
ON customer.CNAME=branch.BNAME
WHERE customer.CITY='BOMBAY';


