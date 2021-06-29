-- Some examples of functions

-- SELECT MAX(price) FROM car;

-- SELECT MIN(price) FROM car;

-- SELECT ROUND(AVG(price)) FROM car;

SELECT make, model, MIN(price) FROM car GROUP BY make, model;
