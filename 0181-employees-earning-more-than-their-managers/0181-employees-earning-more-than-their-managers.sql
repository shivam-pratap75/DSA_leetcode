# Write your MySQL query statement below
SELECT e.name AS Employee FROM Employee AS e
JOIN Employee AS a
ON e.managerId=a.id
WHERE e.salary > a.salary;
