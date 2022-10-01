# Write your MySQL query statement below
SELECT customer_number 
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;

# Write your MySQL query statement below
SELECT customer_number 
FROM Orders
GROUP BY customer_number
HAVING COUNT(order_number) >= all (
    SELECT COUNT(*) 
    FROM orders 
    GROUP BY customer_number
);