def binary_search(list, item):
    low = 0
    high = len(list) - 1

    while (low <= high):
        mid = (low + high) // 2
        print(mid)
        guess = list[mid]

        if (guess == item):
            return mid

        if (guess > item):
            high = mid - 1
        else:
            low = mid + 1

    return None


my_list = [i for i in range(1, 100, 2)]
print(len(my_list))

print(binary_search(my_list, 81))
