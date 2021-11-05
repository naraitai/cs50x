/* Return all stars of movies released in 2004 ordered by birth year */
SELECT name FROM people WHERE id IN (SELECT person_id FROM (SELECT movies.id, movies.year, stars.movie_id, stars.person_id, people.id, people.name, people.birth FROM movies JOIN stars, people ON movies.id = stars.movie_id AND stars.person_id = people.id WHERE movies.year = 2004)) ORDER BY birth;