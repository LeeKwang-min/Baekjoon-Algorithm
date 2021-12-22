'''
문제를 풀 때 조금 간단하게 생각할 필요가 있다.
처음 접근 방식을 '우선순위 큐'를 사용하여 항상 바이러스가 작은 순서를 유지하도록 하자
라는 접근 방식을 생각했지만... 우선순위 큐에 넣는 시간도 많이 들지만 더군다나 굳이 이렇게 할 필요가 없었다.
일반 큐에 가장 적은 바이러스 순서로 처음에 넣어주게 되면 그 뒤에는 자동으로 작은 순서를 유지하게 된다.

두 번째 잘못은 주어지는 초에 대해 끝까지 끝낼 필요가 없다는 것이다.
s초라고 해서 s초가 완전히 지나야 찾고자 하는 (x, y) 좌표의 바이러스를 찾을 수 있는 것은 아니라는 뜻이다.

큐를 순회하다가 찾고자 하는 초, 좌표를 찾았다면 그냥 멈추고 출력해주면 되는 것이다.

시간 초과를 조심하자.
'''
import sys
from collections import deque

n, k = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))
    
fs, fx, fy = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

virus = []
for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            virus.append((graph[i][j], 0, i, j))
            
virus.sort()
q = deque(virus)

while q:
    num, s, x, y = q.popleft()
    if s == fs:
        break
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= n or graph[nx][ny] != 0:
            continue
        graph[nx][ny] = graph[x][y]
        q.append((num, s+1, nx, ny))


print(graph[fx-1][fy-1])