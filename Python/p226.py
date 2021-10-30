n, m = map(int, input().split())
array = []
for i in range(n):
    array.append(int(input()))

d = [10001] * 10001
d[0] = 0
for i in range(m+1): # 0 1 2 3 4 5 6 ... n
    for j in array: # 2 3
        if i - j >= 0:
            d[i] = min(d[i], d[i-j] + 1)

if d[m] == 10001 : print(-1)
else: print(d[m])

'''
3 4
3
5
7

// -1



2 15
2
3

// 5
'''