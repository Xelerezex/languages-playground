
def sum_rec(array):
    number = array.pop()
    if (len(array) == 0):
        return number

    return number + sum_rec(array)


if __name__ == '__main__':
    array = [1, 12, 8, 10, 3]
    print(sum(array))
    print(sum_rec(array))
