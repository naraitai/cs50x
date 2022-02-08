/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return all movies released in 2010 with ratings in descending order or alphabetical if same rating */
SELECT title, rating FROM (SELECT movies.id, ratings.movie_id, movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE movies.year = 2010) ORDER BY rating DESC, title;