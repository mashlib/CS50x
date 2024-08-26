SELECT name FROM people, stars, movies
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND year = 2004
ORDER BY birth;
