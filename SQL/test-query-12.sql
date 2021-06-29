-- Grouping

SELECT country_of_birth, COUNT(*) FROM person GROUP BY country_of_birth  ORDER BY COUNT DESC LIMIT 15;
