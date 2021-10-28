n = int(input())
arr = list(map(int, input().split()))

d = [0] * 100
d[0] = arr[0]
d[1] = max(d[0], arr[1]) # mistake 1

for i in range(2, n):
    d[i] = max(d[i-1], d[i-2] + arr[i]) # mistake 2

print(d[n-1])

'''
4
1 3 1 5

// 8
'''