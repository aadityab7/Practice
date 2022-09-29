# Write your MySQL query statement below
/*SELECT c.name as Customers 
from Customers as c left join Orders as o
on c.id = o.customerId
group by c.id
having count(o.id) = 0;
*/

SELECT Customers.name as 'Customers'
FROM Customers
WHERE Customers.id not in (
    SELECT customerId from Orders
);