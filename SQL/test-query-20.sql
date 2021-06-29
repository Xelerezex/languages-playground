-- Escaping division by zero

-- SELECT 10 / 0; - ERROR
-- SELECT 10 / NULL; - NOT ERROR

-- SELECT 10 / NULLIF(0, 0);

SELECT COALESCE((10 / NULLIF(0, 0)), 12345);
