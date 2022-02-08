/*---------------------------------
Task 1 of 3

Brief
- Write a series of queries to answer questions about a database of songs

Distribution code
- songs.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return average enery of songs by Drake (single column and single row table) */

SELECT AVG(energy) FROM (SELECT songs.artist_id, artists.id, songs.energy, artists.id FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = "Drake");