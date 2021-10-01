n, m = map(int, input().split())
A, B, d = map(int, input().split())

chk = [[0] * m for _ in range(n)] # [0] m개를 n개만큼 반복해서 넣는다.
chk[A][B] = 1

land = []
for i in range(n):
    land.append(list(map(int, input().split()))) # append를 사용하여 새로운 list를 만들어 넣는다.

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

cnt = 0
result = 1
while True:
    d = (d + 3) % 4
    nx = A + dx[d]
    ny = B + dy[d]
    if chk[nx][ny] == 1 or land[nx][ny] == 1:
        cnt += 1
        if cnt == 4:
            nx = A + dx[(d + 2) % 4]
            ny = B + dy[(d + 2) % 4]
            if land[nx][ny] == 1:
                break
            else:
                A, B = nx, ny
            cnt = 0 # 실수한 부분 -> 이전으로 이동했다 == 이동 불가능 방향 카운트를 초기화
    else:
        result += 1
        chk[nx][ny] = 1
        A, B = nx, ny
        cnt = 0

print(result)
    

'''
input
4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1

output
3
'''