# Write your MySQL query statement below
select p.product_name,s.year,s.price 
From Product as p
Join Sales as s 
on p.product_id=s.product_id
