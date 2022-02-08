/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/*Return titles and release years of all Harry Potter movies in chronological order */
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;