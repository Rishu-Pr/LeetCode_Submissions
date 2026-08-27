# Write your MySQL query statement below
SELECT email FROM PERSON
GROUP BY email
HAVING COUNT(*) > 1;