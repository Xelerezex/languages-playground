# Still don't understand for what this stuff needs

class Person():
    pass


person = Person()

person_info = {'first': 'Corey', 'second': 'Shafer'}

for key, value in person_info.items():
    setattr(person, key, value)

print(person.first)
print(person.second)

for key in person_info.keys():
    print(getattr(person, key))
