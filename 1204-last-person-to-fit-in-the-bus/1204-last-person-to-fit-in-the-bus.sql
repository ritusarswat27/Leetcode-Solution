# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name , TURN  , SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
) AS q
WHERE total_weight <= 1000
ORDER BY TURN DESC
LIMIT 1