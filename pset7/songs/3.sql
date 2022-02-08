/*---------------------------------
Task 1 of 3

Brief
- Write a series of queries to answer questions about a database of songs

Distribution code
- songs.db

Key concept:
- SQL queries
-----------------------------------*/

/* Return names of top 5 longest songs in descneding order (single column table) */

SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;