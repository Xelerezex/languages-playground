-- Changing NULL in output to fill it

SELECT COALESCE(email, '!!!!NO EMAIL!!!!') FROM person;
