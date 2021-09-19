lst = ['John', 'Jason', 'Bill', 'Muray']

for index, name in enumerate(lst, start=5):
    print(index, name)

print(list(enumerate(lst)))
