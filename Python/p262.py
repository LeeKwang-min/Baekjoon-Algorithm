import sys, heapq
input = sys.stdin.readline

n, m, c = map(int, input().split())
INF = int(1e9)

arr = [[] for _ in range(n + 1)]
distance = [INF] * (n+1)

for _ in range(m):
    x, y, z = map(int, input().split())
    arr[x].append((z, y))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in arr[now]:
            cost = dist + i[0]
            if distance[i[1]] > cost:
                distance[i[1]] = cost
                heapq.heappush(q, (cost, i[1]))

dijkstra(c)

canContry = 0
totalDist = 0
for i in distance:
    if i != INF:
        canContry += 1
        if totalDist < i:
            totalDist = i

print(canContry - 1, totalDist)

'''
3 2 1
1 2 4
1 3 2

// 2 4
'''