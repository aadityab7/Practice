# Write your MySQL query statement below
select DISTINCT product_id, product_name
from product as p
join sales as s 
using(product_id)
where sale_date >= '2019-01-01' and sale_date <= '2019-03-31' and p.product_id not in (
    select product_id from sales
    where sale_date < '2019-01-01' || sale_date > '2019-03-31'
);