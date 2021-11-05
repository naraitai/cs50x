/* Return average rating of all movies released in 2012 */
SELECT AVG(rating) FROM (SELECT movies.id, ratings.movie_id, movies.year, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE movies.year = 2012);