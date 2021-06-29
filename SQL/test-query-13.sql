-- GROUP BY and HAVING extra word

SELECT country_of_birth, COUNT(*) FROM person GROUP BY country_of_birth HAVING COUNT(*) > 15 ORDER BY COUNT DESC;
