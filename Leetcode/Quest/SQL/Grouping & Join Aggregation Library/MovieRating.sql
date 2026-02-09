-- Table: Movies

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | title         | varchar |
-- +---------------+---------+

-- movie_id is the primary key (column with unique values) for this table. title is the name of the movie. Each movie has a unique title.


-- Table: Users

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | user_id       | int     |
-- | name          | varchar |
-- +---------------+---------+
-- user_id is the primary key (column with unique values) for this table. The column 'name' has unique values.


-- Table: MovieRating

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | user_id       | int     |
-- | rating        | int     |
-- | created_at    | date    |
-- +---------------+---------+

-- (movie_id, user_id) is the primary key (column with unique values) for this table. This table contains the rating of a movie by a user in their review. created_at is the user's review date. 
 

-- Write a solution to:

--     1 - Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.
--     2 - Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.







(select name as results
from  MovieRating join Users on MovieRating.user_id = Users.user_id
group by  name
order by count(*) desc, name
limit 1)

union all

(select title as results
from MovieRating join Movies on MovieRating.movie_id = Movies.movie_id
WHERE extract(YEAR_MONTH FROM created_at) = 202002
group by title
order by avg(rating) desc, title
limit 1);