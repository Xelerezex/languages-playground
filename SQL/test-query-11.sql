-- Regular Expressions: Basics

-- All persons with .com in the end
-- SELECT * FROM person WHERE email LIKE '%.com';

-- Select all persons with names of emails in 6 len
SELECT * FROM person WHERE email LIKE '______@%';
