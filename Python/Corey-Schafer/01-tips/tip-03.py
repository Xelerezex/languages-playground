# Zip stops after shortest zip, else we go zip_longest -> itertools

abc = [i for i in 'abcdefg']
num = [i for i in range(7)]
rev_num = [(100 - i) for i in num]

for number, letter, reverse in zip(num, abc, rev_num):
    print(f"{number} is pos to -> {letter} and rev is -> {reverse}")

print(zip(num, abc, rev_num))
print(list(zip(num, abc, rev_num)))
