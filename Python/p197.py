n = int(input())
items = list(map(int, input().split()))

m = int(input())
find = list(map(int, input().split()))

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] > target:
            end = mid - 1
        elif array[mid] < target:
            start = mid + 1
        else:
            return 'yes'
    return 'no'

items.sort()
for i in range(m):
    print(binary_search(items, find[i], 0, n - 1), end=' ');



'''
5
8 3 7 9 2
3
5 7 9

// no yes yes
'''