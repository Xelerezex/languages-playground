-- Aplying operators to our queries & renaming columns

SELECT id, make, model, price AS original_price, ROUND(price * .10, 2) AS ten_percent, ROUND(price - (price * .10), 2) AS price_after_discount FROM car;
