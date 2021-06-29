-- Filters the data based on Conditions

-- SELECT * FROM person WHERE gender = 'Non-binary';

SELECT * FROM person WHERE gender = 'Female' AND (country_of_birth = 'China' OR country_of_birth = 'Russia') AND last_name = 'Crocetti';
