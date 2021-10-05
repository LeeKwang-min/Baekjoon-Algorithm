n = int(input())
array = []
for i in range(n):
    array.append(int(input()))

array = sorted(array, reverse=True)

for i in array:
    print(i, end=' ')


'''
3
15
27
12

// 27 15 12
'''