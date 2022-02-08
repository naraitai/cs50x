/*---------------------------------
Task 2 of 3

Brief
- Write a series of queries to answer questions about a database of movies

Distribution code
- movies.db

Key concept:
- SQL queries
-----------------------------------*/

/*Return movies starring Johnny Depp and Helena Bonham Carter */
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM (SELECT movie_id FROM stars WHERE person_id  = (SELECT id from people WHERE name = "Helena Bonham Carter")) WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id =  (SELECT id from people WHERE name = "Johnny Depp")));
