SELECT a_start.machine_id,ROUND(AVG(a_end.timestamp - a_start.timestamp), 3) AS processing_time
FROM Activity a_start
JOIN Activity a_end ON a_start.process_id = a_end.process_id 
    AND a_start.machine_id = a_end.machine_id
    AND a_start.activity_type = 'start'
    AND a_end.activity_type = 'end'
GROUP BY a_start.machine_id;
