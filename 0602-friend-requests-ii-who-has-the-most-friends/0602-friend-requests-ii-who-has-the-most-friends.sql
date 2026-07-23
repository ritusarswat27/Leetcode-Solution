# Write your MySQL query statement below
WITH C1 AS(
    SELECT requester_id AS id , COUNT(*) AS cnt
    FROM RequestAccepted
    GROUP BY requester_id

    UNION ALL

    SELECT accepter_id AS id , COUNT(*) AS cnt
    FROM RequestAccepted
    GROUP BY accepter_id
)
SELECT id,  SUM(cnt) AS num
FROM C1
GROUP BY id
ORDER BY num DESC
LIMIT 1;