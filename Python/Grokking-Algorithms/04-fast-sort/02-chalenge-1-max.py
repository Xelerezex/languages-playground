
def max_rec(array):
    if (len(array) == 1):
        return array[0]

    if (array[0] < array[-1]):
        array[0] = array[-1]
        array.pop()
    else:
        array.pop()

    return max_rec(array)


if __name__ == '__main__':
    array = [1, 12, 8, 10, 3]
    print(max_rec(array))
    print(len(array))
