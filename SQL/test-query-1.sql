-- Normal TABLE should created with contains like: BIGSERIAL, NOT NULL, PRIMARY KEY

CREATE TABLE person (
    id BIGSERIAL NOT NULL PRIMARY KEY,  -- {BIGSERIAL} <-- Signed integer, wich auto increments,
                                        -- {NOT NULL} <-- Table now can't hold NULL values,
                                        -- {PRIMARY KEY} <-- uniquely identify each row in the table
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    gender VARCHAR(7) NOT NULL,
    date_of_birth DATE NOT NULL,
    email VARCHAR(150)
);
