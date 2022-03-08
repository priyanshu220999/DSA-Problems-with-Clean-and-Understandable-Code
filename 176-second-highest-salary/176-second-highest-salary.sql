# Write your MySQL query statement below
select max(sal) as SecondHighestSalary from 
(select id as i,salary as sal from employee where salary < (select max(salary) from employee)) b;