/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return 5 highest rated movies in order that starred Chadwick Boseman */
SELECT movies.title FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE people.name = "Chadwick Boseman")) ORDER BY rating DESC LIMIT 5;