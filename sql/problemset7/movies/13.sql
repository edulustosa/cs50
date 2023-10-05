-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

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
          movie_id
        FROM
          stars
          JOIN people ON stars.person_id = people.id
        WHERE
          NAME = 'Kevin Bacon'
          AND birth = 1958
      )
  )
  AND NAME <> 'Kevin Bacon';