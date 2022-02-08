/*---------------------------------
Task 1 of 3

Brief
- Write a series of queries to answer questions about a database of songs

Distribution code
- songs.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return names of any song by Post Malone (single column table) */

SELECT name FROM (SELECT songs.artist_id, artists.id, songs.name, artists.name FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = "Post Malone");