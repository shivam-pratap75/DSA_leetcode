# Write your MySQL query statement below

select ROUND(COUNT(*)/(SELECT COUNT(DISTINCT player_id) from Activity),2) AS fraction from Activity AS a1 
join (select MIN(event_date) AS event_date,player_id from Activity
group BY player_id) AS a2
on a1.player_id=a2.player_id
AND DATEDIFF(a1.event_date,a2.event_date)=1





