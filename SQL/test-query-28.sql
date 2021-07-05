-- SQL database to csv

\copy (SELECT * FROM person LEFT JOIN car ON car.id = person.car_id) TO '/Документы/__repo__/languages-playground/SQL' DELIMITER ',' CSV HEADER;
