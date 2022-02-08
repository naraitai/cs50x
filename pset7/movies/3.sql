/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return all movies release on or after 2018 in alphabetical order */
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;