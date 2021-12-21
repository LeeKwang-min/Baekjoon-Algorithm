'''
0 = 빈칸, 1 = 벽, 2 = 바이러스
1. BFS를 진행할 함수
2. 안전 공간을 계산할 함수
3. 3개의 벽을 추가로 칠 함수
4. 3개의 벽을 제거할 함수

위 함수들을 차례대로 만들고 벽을 치고 검사하고 벽을 다시 지우고를 반복해주면 된다.
BFS와 조합을 사용하면 간단하게 해결할 수 있다.

기억하자
collection - deque
itertools - combinations
'''
import sys
from collections import deque
from itertools import combinations

n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs():
    q = deque([])
    visited = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2:
                q.append((i, j))
                visited[i][j] = 2
            elif graph[i][j] == 1:
                visited[i][j] = 1
    
    while q:
        x, y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph[nx][ny] == 1 or visited[nx][ny] != 0:
                continue
            visited[nx][ny] = 2
            q.append((nx, ny))
            
    safe = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] == 0:
                safe += 1
    
    return safe

def choose():
    empty = []
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                empty.append((i, j))
    
    combi = list(combinations(empty, 3))
    ans = 0
    for f, s, t in combi:
        graph[f[0]][f[1]] = 1
        graph[s[0]][s[1]] = 1
        graph[t[0]][t[1]] = 1
        ans = max(ans, bfs())
        graph[f[0]][f[1]] = 0
        graph[s[0]][s[1]] = 0
        graph[t[0]][t[1]] = 0
        
    return ans
        
print(choose())