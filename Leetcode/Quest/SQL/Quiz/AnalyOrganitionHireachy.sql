-- Table: Employees

-- +----------------+---------+
-- | Column Name    | Type    | 
-- +----------------+---------+
-- | employee_id    | int     |
-- | employee_name  | varchar |
-- | manager_id     | int     |
-- | salary         | int     |
-- | department     | varchar |
-- +----------------+----------+

-- employee_id is the unique key for this table. Each row contains information about an employee, including their ID, name, their manager's ID, salary, and department. manager_id is null for the top-level manager (CEO). Write a solution to analyze the organizational hierarchy and answer the following:

--     1 - Hierarchy Levels: For each employee, determine their level in the organization (CEO is level 1, employees reporting directly to the CEO are level 2, and so on).
--     2 - Team Size: For each employee who is a manager, count the total number of employees under them (direct and indirect reports).
--     3 - Salary Budget: For each manager, calculate the total salary budget they control (sum of salaries of all employees under them, including indirect reports, plus their own salary).
-- Return the result table ordered by the result ordered by level in ascending order, then by budget in descending order, and finally by employee_name in ascending order.

-- The result format is in the following example.





WITH RECURSIVE
LEVELS as (
    SELECT 
    e.employee_id,
    e.employee_name,
    e.manager_id,
    e.salary,
    e.department,
    1 As level
    FROM 
    Employees e
    WHERE 
    e.manager_id IS NULL 
    
    UNION ALL 
    SELECT 
    c.employee_id,
    c.employee_name,
    c.manager_id,
    c.salary,
    c.department,
    l.level+1
    FROM 
    Employees c
    JOIN LEVELS l
    on
    c.manager_id = l.employee_id
),

CLOSURE AS (

  SELECT
    m.employee_id AS Manager_id,
    d.employee_id AS Desendent_id
  FROM Employees d
  JOIN Employees m
    ON d.manager_id = m.employee_id

  UNION ALL


  SELECT
    cl.Manager_id AS Manager_id,
    e.employee_id AS Desendent_id
  FROM CLOSURE cl
  JOIN Employees e
    ON e.manager_id = cl.Desendent_id
),
agg as (
    SELECT 
    cl.manager_id,
    COUNT(*) as Team_Size,
    SUM(e.salary) as Subordinate_salary
    FROM closure cl
    JOIN 
    Employees e 
    on e.employee_id = cl.Desendent_id
    GROUP BY cl.manager_id
)
SELECT 
l.employee_id,
l.employee_name,
l.level,
COALESCE(a.Team_Size,0) as team_size,
COALESCE(a.Subordinate_salary,0)+l.salary as budget
FROM 
LEVELS l 
LEFT JOIN agg a
ON 
a.manager_id = l.employee_id
ORDER BY 
l.level asc,
budget desc