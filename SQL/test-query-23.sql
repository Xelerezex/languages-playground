-- Trying for made all emails as unique value

-- Finding that all emails unique
-- SELECT email, COUNT(*) AS quantity FROM person GROUP BY email HAVING COUNT(*) > 1;

ALTER TABLE person ADD CONSTRAINT unique_email_adress UNIQUE (email);
