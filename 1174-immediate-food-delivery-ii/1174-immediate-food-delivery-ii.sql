# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT ROUND(
        SUM(CASE WHEN o=d THEN 1 END ) * 100 / COUNT(*),
        2
    ) AS immediate_percentage FROM (SELECT customer_id,MIN(order_date) AS o,
MIN(customer_pref_delivery_date) AS d , COUNT(*) AS c FROM Delivery
GROUP BY customer_id) AS k






