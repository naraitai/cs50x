/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return names of all stars of Toy Story */
SELECT name FROM (SELECT movies.id, movies.title, stars.movie_id, stars.person_id, people.id, people.name FROM movies JOIN stars, people ON movies.id = stars.movie_id WHERE movies.title = "Toy Story" AND stars.person_id = people.id);