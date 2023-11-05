PROMPT 1:
INPUT:
+--------+------------------------------+-----------------------------+------------------+
| bookid | title                        | author                      | subject          |
+--------+------------------------------+-----------------------------+------------------+
|     21 | THE SIGN OF FOUR             | SIR ARTHUR CONAN DOYLE      | FICTION          |
|    100 | PANINI GRAMMAR               | MAHARSHI PANINI             | SANSKRIT         |
|   1921 | LINEAR ALGEBRA               | GILBERT STRANG              | MATHEMATICS      |
|  13243 | COMPILER DESIGN              | LAM,SETHI,ULLMAN            | COMPUTER SCIENCE |
|  22351 | COMPUTER SYSTEM ARCHITECTURE | MORRIS MANO                 | COMPUTER SCIENCE |
|  31232 | MICROPROCESSOR 8085          | RAMESH S GAONKAR            | COMPUTER SCIENCE |
|  54981 | DATABASE SYSTEM CONCEPTS     | SILBERCHATZ,KORTH,SUDARSHAN | COMPUTER SCIENCE |
|  55412 | GENERAL RELATIVITY           | ALBERT EINSTEIN             | PHYSICS          |
|  88192 | ORGANIC CHEMISTRY CONCEPTS   | DAVID SHINE                 | CHEMISTRY        |
|  99812 | RAMCHARITMANAS               | GOSWAMI TULSIDAS            | SPIRITUALITY     |
+--------+------------------------------+-----------------------------+------------------+
QUERY:
mysql> SELECT title,subject  FROM BOOK WHERE subject="COMPUTER SCIENCE" OR subject="PHYSICS";
OUTPUT:
+------------------------------+------------------+
| title                        | subject          |
+------------------------------+------------------+
| COMPILER DESIGN              | COMPUTER SCIENCE |
| COMPUTER SYSTEM ARCHITECTURE | COMPUTER SCIENCE |
| MICROPROCESSOR 8085          | COMPUTER SCIENCE |
| DATABASE SYSTEM CONCEPTS     | COMPUTER SCIENCE |
| GENERAL RELATIVITY           | PHYSICS          |
+------------------------------+------------------+
PROMPT 2:
INPUT:
+------+--------------------+
| bid  | bname              |
+------+--------------------+
|   15 | DEV MANDAL         |
|  921 | LAKSHYA PANDEY     |
| 1082 | PRITAM DEY         |
| 1089 | AYUSH KUMAR SHUKLA |
| 1145 | RAHUL SHUKLA       |
| 5143 | ARYAN SHUKLA       |
+------+--------------------+
6 rows in set (0.00 sec)

+--------+------+---------------+----------------+
| bookid | bid  | date_of_issue | date_of_return |
+--------+------+---------------+----------------+
|     21 |   15 | 2023-10-10    | 2023-10-17     |
|    100 |  921 | 2023-11-01    | 2023-11-08     |
|  13243 |   15 | 2023-11-05    | 2023-11-20     |
|  22351 |   15 | 2023-11-05    | 2023-11-20     |
|  31232 | 5143 | 2023-11-08    | 2023-11-15     |
|  99812 | 1089 | 2023-11-03    | 2023-11-07     |
+--------+------+---------------+----------------+
6 rows in set (0.00 sec)

+--------+------------------------------+-----------------------------+------------------+
| bookid | title                        | author                      | subject          |
+--------+------------------------------+-----------------------------+------------------+
|     21 | THE SIGN OF FOUR             | SIR ARTHUR CONAN DOYLE      | FICTION          |
|    100 | PANINI GRAMMAR               | MAHARSHI PANINI             | SANSKRIT         |
|   1921 | LINEAR ALGEBRA               | GILBERT STRANG              | MATHEMATICS      |
|  13243 | COMPILER DESIGN              | LAM,SETHI,ULLMAN            | COMPUTER SCIENCE |
|  22351 | COMPUTER SYSTEM ARCHITECTURE | MORRIS MANO                 | COMPUTER SCIENCE |
|  31232 | MICROPROCESSOR 8085          | RAMESH S GAONKAR            | COMPUTER SCIENCE |
|  54981 | DATABASE SYSTEM CONCEPTS     | SILBERCHATZ,KORTH,SUDARSHAN | COMPUTER SCIENCE |
|  55412 | GENERAL RELATIVITY           | ALBERT EINSTEIN             | PHYSICS          |
|  88192 | ORGANIC CHEMISTRY CONCEPTS   | DAVID SHINE                 | CHEMISTRY        |
|  99812 | RAMCHARITMANAS               | GOSWAMI TULSIDAS            | SPIRITUALITY     |
+--------+------------------------------+-----------------------------+------------------+
10 rows in set (0.00 sec)
PROBLEM:6
QUERY:
mysql> SELECT bname,COUNT(bookid) FROM BORROWER NATURAL JOIN BORROWS NATURAL JOIN BOOK GROUP BY bname,subject HAVING subject="COMPUTER SCIENCE" AND COUNT(bookid)>1;
OUTPUT:
+------------+---------------+
| bname      | COUNT(bookid) |
+------------+---------------+
| DEV MANDAL |             2 |
+------------+---------------+
PROBLEM 7:
INPUT:UNCHANGED
mysql> SELECT bid,bname FROM BORROWER
    -> EXCEPT
    -> SELECT DISTINCT bid,bname FROM BORROWER NATURAL JOIN BORROWS;
+------+--------------+
| bid  | bname        |
+------+--------------+
| 1082 | PRITAM DEY   |
| 1145 | RAHUL SHUKLA |
+------+--------------+
2 rows in set (0.00 sec)
PROBLEM 8:
mysql> SELECT title FROM BOOK EXCEPT SELECT title FROM BOOK NATURAL JOIN BORROWS;
+----------------------------+
| title                      |
+----------------------------+
| LINEAR ALGEBRA             |
| DATABASE SYSTEM CONCEPTS   |
| GENERAL RELATIVITY         |
| ORGANIC CHEMISTRY CONCEPTS |
+----------------------------+
4 rows in set (0.00 sec)
PROBLEM 10:
INPUT: UNCHANGED
mysql> SELECT bname from BORROWER NATURAL JOIN BORROWS WHERE bname like "%KUMAR%";
+--------------------+
| bname              |
+--------------------+
| AYUSH KUMAR SHUKLA |
+--------------------+
1 row in set (0.00 sec)
