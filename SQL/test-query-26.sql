-- Inner Join. Join information to one output from two tables88888888888iiiiiiiiiio

-- SELECT * FROM person JOIN car ON person.car_id = car.id;

SELECT person.first_name, car.make, car.model, car.price FROM person JOIN car ON person.car_id = car.id;
