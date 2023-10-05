-- In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year

SELECT
  NAME
FROM
  people
WHERE
  id IN (
    SELECT
      person_id
    FROM
      stars
    WHERE
      movie_id IN (
        SELECT
          id
        FROM
          movies
        WHERE
          YEAR = 2004
      )
  )
ORDER BY
  birth;