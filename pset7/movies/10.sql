/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/*Return all directors of movies with a rating of 9.0 or more. */
SELECT name FROM people WHERE id IN (SELECT person_id FROM (SELECT ratings.rating, ratings.movie_id, directors.movie_id, directors.person_id, people.id, people.name FROM ratings JOIN movies, directors, people ON ratings.movie_id = movies.id AND ratings.movie_id = directors.movie_id AND directors.person_id = people.id WHERE ratings.rating >= 9.0 ORDER BY people.name));