# Write your MySQL query statement below
SELECT  "Low Salary" AS Category,  COUNT(CASE WHEN income < 20000 THEN 1 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT  "Average Salary" AS Category,  COUNT(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT  "High Salary" AS Category,  COUNT(CASE WHEN income > 50000 THEN 1 END) AS accounts_count
FROM Accounts