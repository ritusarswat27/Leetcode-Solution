# Write your MySQL query statement below
SELECT  x , y , z ,
IF(x + y > z && y + z > x && z + x > y , "Yes" , "No") AS triangle 
FROM Triangle