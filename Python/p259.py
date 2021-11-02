import sys
input = sys.stdin.readline

INF = int(1e9)

n, m = map(int, input().split())
distance = [[INF] * (n+1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            distance[i][j] = 0

for i in range(m):
    a, b = map(int, input().split())
    distance[a][b] = 1
    distance[b][a] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

x, k = map(int, input().split())
sum = distance[1][k] + distance[k][x]
if sum > INF:
    print(-1)
else:
    print(sum)


'''
4 2
1 3
2 4
3 4
-1



'''