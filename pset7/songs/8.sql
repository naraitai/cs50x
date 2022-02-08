/*---------------------------------
Task 1 of 3

Brief
- Write a series of queries to answer questions about a database of songs

Distribution code
- songs.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return names of any song that features other artists (single column table) */

SELECT name FROM songs WHERE name LIKE "%feat%";