-- Sum Function

-- Summ of all cars in our table
-- SELECT SUM(price) FROM car;

SELECT make, SUM(price) FROM car GROUP BY make;
