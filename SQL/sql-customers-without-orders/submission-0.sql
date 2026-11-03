-- Write your query below
select name from customers as c
where c.id not IN(select distinct customer_id from orders);