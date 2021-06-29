-- How to insert records into tables

INSERT INTO person ( -- column_name
    first_name,
    last_name,
    gender,
    date_of_birth)
VALUES ('Anne', 'Smith', 'FEMALE', '1988-01-10');  -- Each value meet each column_name. It can't be meet only if colum_name Conatins NULL value
                                                   -- Our values, except for email field all NOT NULL values. And should be filled
INSERT INTO person (
    first_name,
    last_name,
    gender,
    date_of_birth,
    email)
VALUES ('Jakob', 'Wager', 'MALE', '1991-01-01', 'jak@jajaK.com');
