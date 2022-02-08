/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return number of movies with rating of 10.0 */
SELECT COUNT(title) FROM (SELECT movies.id, ratings.movie_id, movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE ratings.rating = 10.0);