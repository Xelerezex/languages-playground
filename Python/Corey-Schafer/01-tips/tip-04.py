# Unpacking
A, _ = (1, 0)  # Want to unpack only a-value, _ - it's just temporary variable, where 2 goes to nowhere

print(A)

a, b, *c = (i for i in range(6))

print(a, b, c)

a, b, *_ = (i for i in range(6))  # If we want only first two values, and don't give a shit about other

a, b, *c, d, e, f = (i for i in range(2, 10))
print(a, b, c, d, e, f)
