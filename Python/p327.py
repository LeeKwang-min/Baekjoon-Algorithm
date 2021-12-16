'''
시키는대로 잘 하면 풀 수 있는 문제이다.
파이썬에서의 큐는 리스트를 사용하며
insert와 pop(0)을 사용하여 큐로 사용할 수 있다.

뱀의 위치에 대한 정보를 모두 가지고 있어야 한다.
몸통의 정보를 가지고 있어야 하며
꼬리가 어디있는지 알기 위해서 큐를 사용한다.
큐를 pop하면 꼬리가 짤리는것과 같다.

1. 몸 길이를 늘려 머리를 다음칸으로 이동한다.
  2. 사과가 있다면 사과가 사라지고 꼬리를 지우지 않는다.
  3. 사과가 없다면 꼬리를 지운다.
  
위 3가지를 잘 구현하면 해결할 수 있다.
'''
n = int(input())
k = int(input())
board = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(k):
    x, y = map(int, input().split())
    board[x][y] = 1
    
l = int(input())
play = []
for _ in range(l):
    x, c = input().split()
    play.append((int(x), c))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def printMap(array):
    for i in range(1, len(array)):
        for j in range(1, len(array)):
            print(array[i][j], end=' ')
        print()
    print()

direction = 0
x = 1
y = 1
sec = 0
board[x][y] = 10
nxt = [(x, y)]

while True:
    # printMap(board)
    nx = x + dx[direction]
    ny = y + dy[direction] 
    if nx < 1 or nx > n or ny < 1 or ny > n: 
        break
    if board[nx][ny] == 10: 
        break
    nxt.append((nx, ny))
    if board[nx][ny] == 1: 
        board[nx][ny] = 10
    else: 
        board[nx][ny] = 10
        pxy = nxt.pop(0)
        px = pxy[0]
        py = pxy[1]
        board[px][py] = 0 
    x = nx
    y = ny
    sec += 1
    if len(play) == 0:
        continue
    
    if play[0][0] == sec:
        if play[0][1] == 'D': # 다음 이동 방향 정해서 이동
            direction = (direction + 1) % 4
        else:
            direction = (direction + 3) % 4
        play.pop(0)
        
print(sec + 1)
    