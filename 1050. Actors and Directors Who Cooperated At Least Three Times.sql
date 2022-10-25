# Write your MySQL query statement below
SELECT actor_id , director_id from ActorDirector 
GROUP BY actor_id, director_id
HAVING COUNT(*) > 2;
# Write your MySQL query statement below
SELECT actor_id , director_id from ActorDirector 
GROUP BY 1,2
HAVING COUNT(*) > 2;