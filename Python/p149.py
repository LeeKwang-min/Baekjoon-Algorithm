dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input()))) # 공백이 아닌 문자열로 입력받아 한자리씩 처리하는 경우 이런 방식으로 사용

def dfs(graph, x, y, visited):
    visited[x][y] = True
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if visited[nx][ny] or graph[nx][ny] == 1:
            continue
        dfs(graph, nx, ny, visited)

def dfs_in_book(x, y):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    if graph[x][y] == 0: # 따로 visited를 사용하지 않고 graph의 숫자를 바꾸는 방식을 사용
        graph[x][y] = 1
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    return False

visited = [[False] * m for _ in range(n)]

result = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and graph[i][j] == 0:
            result += 1
            dfs(graph, i, j, visited)


print(result)


'''
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111

8
'''