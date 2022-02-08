/*---------------------------------
Task 1 of 3

Brief
- Write a series of queries to answer questions about a database of songs

Distribution code
- songs.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return names of any song with danceability, energy and valence above 0.75 (single column table) */

SELECT name FROM songs WHERE (danceability > 0.75 AND energy > 0.75 AND valence > 0.75);