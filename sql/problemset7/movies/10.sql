-- In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0

SELECT DISTINCT
  (NAME)
FROM
  people
WHERE
  id IN (
    SELECT
      person_id
    FROM
      directors
    WHERE
      movie_id IN (
        SELECT
          movie_id
        FROM
          ratings
        WHERE
          movie_id IN (
            SELECT
              id
            FROM
              movies
          )
          AND rating >= 9.0
      )
  );