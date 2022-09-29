# Write your MySQL query statement below
SELECT e.name as Employee 
from Employee as e join Employee as m 
ON e.managerId = m.id AND m.salary < e.salary; 
