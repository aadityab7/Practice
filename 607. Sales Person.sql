# Write your MySQL query statement below
#get all the com_id and name for that sales person
select sales.name from salesPerson as sales where sales.name not in (
    select s.name
    from (
        orders as o
        join company as c
        on o.com_id = c.com_id
        and c.name = "RED" 
    )
    join salesPerson as s
    on s.sales_id = o.sales_id
);



select s.name
from salesPerson as s
where s.sales_id not in
(
    select o.sales_id
    from orders as o
    join company as c
    on o.com_id = c.com_id
    and c.name = "RED" 
);




