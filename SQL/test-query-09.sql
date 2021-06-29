-- Picking elements from some space

-- SELECT * FROM person WHERE country_of_birth = 'China' OR country_of_birth = 'France' OR country_of_birth = 'Brazil';

-- Analog of upper query:
SELECT * FROM person WHERE country_of_birth IN ('Brazil', 'France', 'China') ORDER BY country_of_birth;
