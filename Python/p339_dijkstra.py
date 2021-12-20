import heapq
import sys

n, m, k, x = map(int, input().split())
INF = int(1e9)
dist = [INF] * (n+1)
graph = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append((1, b))

def dijkstra():
    dist[x] = 0
    q = []
    heapq.heappush(q, (0, x))
    while q:
        cost, cur = heapq.heappop(q)
        if cost > dist[cur]:
            break
        for i in graph[cur]:
            ncost, nxt = i
            if dist[nxt] > cost + ncost:
                dist[nxt] = cost + ncost
                heapq.heappush(q, (dist[nxt], nxt))

dijkstra()

flag = False
for i in range(len(dist)):
    if dist[i] == k:
        print(i)
        flag = True

if not flag:
    print(-1)