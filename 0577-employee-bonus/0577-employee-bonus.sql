# Write your MySQL query statement below
select e.name, b.bonus from Employee as e
left join Bonus as b
on e.empId=b.empId
WHERE b.bonus IS NULL OR b.bonus<1000