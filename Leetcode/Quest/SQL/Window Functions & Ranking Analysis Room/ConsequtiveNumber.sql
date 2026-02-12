-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+

-- In SQL, id is the primary key for this table. id is an autoincrement column starting from 1. Find all numbers that appear at least three times consecutively. Return the result table in any order.





select distinct l1.num as ConsecutiveNums
from Logs l1, Logs l2, Logs l3
where l1.num = l2.num and l2.num = l3.num and l1.id = l2.id - 1 and l2.id = l3.id - 1;