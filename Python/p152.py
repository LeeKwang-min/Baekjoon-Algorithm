from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input()))) # 파이썬의 경우 입력 받을 때 인덱스를 1부터 입력받기가 힘들어서 가능하면 (1,1)에서 시작되도 (0,0)에서 되도록 처리하자

dist = [[0] * m for i in range(n)]

def bfs(x, y):
    global dist, graph
    queue = deque()
    queue.append((x, y)) # list의 경우 deque를 선언하며 바로 집어 넣을 수 있지만, tuple의 경우 그렇지 않다.
    dist[x][y] = 1
    while queue:
        cur = queue.popleft()
        cx = cur[0]
        cy = cur[1]
        for k in range(4):
            nx = cx + dx[k]
            ny = cy + dy[k]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if dist[nx][ny] != 0 or graph[nx][ny] != 1:
                continue
            queue.append((nx, ny))
            dist[nx][ny] = dist[cx][cy] + 1

bfs(0, 0)

print(dist[n - 1][m - 1])


'''
def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph[nx][ny] == 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))
    
    return graph[n - 1][m - 1]

print(bfs(0, 0))
'''

'''
5 6
101010
111111
000001
111111
111111

// 10
'''