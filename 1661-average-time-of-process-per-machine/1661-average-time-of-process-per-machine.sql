# Write your MySQL query statement below
with temp as(select machine_id, COUNT(process_id) as count, ROUND(SUM(timestamp),3) AS timestamp from Activity
where activity_type='start'
group by machine_id),
 tempo as(select machine_id, COUNT(process_id) as count, ROUND(SUM(timestamp),3) AS timestamp from Activity
where activity_type='end'
group by machine_id)

select t.machine_id, ROUND((t1.timestamp-t.timestamp)/t.count,3) as processing_time from temp as t
join tempo as t1
on t.machine_id=t1.machine_id