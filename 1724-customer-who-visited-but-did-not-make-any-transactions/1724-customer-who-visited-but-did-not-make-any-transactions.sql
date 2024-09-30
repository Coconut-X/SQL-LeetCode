SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM Visits
where Visits.visit_id not in (select visit_id from Transactions)
GROUP BY customer_id
