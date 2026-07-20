# Write your MySQL query statement below
SELECT p.product_name , unitSum AS unit 
FROM Products p
JOIN (
    SELECT  product_id , SUM(unit) AS unitSum
    FROM Orders
    WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY product_id
) AS t
ON p.product_id = t.product_id
WHERE unitSum >= 100