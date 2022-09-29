# Write your MySQL query statement below
/*SELECT w.id
FROM weather AS w
JOIN weather AS wh
ON DATEDIFF(w.recordDate, wh.recordDate) = 1
AND (w.temperature > wh.temperature);
*/

SELECT DISTINCT a.Id
FROM Weather a,Weather b
WHERE a.Temperature > b.Temperature
AND DATEDIFF(a.Recorddate,b.Recorddate) = 1