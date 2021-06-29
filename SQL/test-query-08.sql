-- Limits to output

-- Upper limit
-- SELECT * FROM person LIMIT 13;

-- Lower limit
-- SELECT * FROM person OFFSET 5 LIMIT 5;

-- Limit analog
SELECT * FROM person OFFSET 5 FETCH FIRST 7 ROW ONLY;
