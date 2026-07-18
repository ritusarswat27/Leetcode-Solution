# Write your MySQL query statement below
(
    SELECT u.name AS results
    FROM MovieRating r
    LEFT JOIN Users u
    ON r.user_id = u.user_id
    GROUP BY u.user_id
    ORDER BY COUNT(*) Desc, u.name
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM Movies m
    LEFT JOIN MovieRating r
    ON m.movie_id = r.movie_id 
    WHERE r.created_at between '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id
    ORDER BY AVG(r.rating) DESC, m.title
    LIMIT 1
)