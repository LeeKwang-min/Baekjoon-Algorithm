# n = int(input())
# move = list(input().split())

# dx = [-1, 0, 1, 0]
# dy = [0, 1, 0, -1]

# x = 1
# y = 1

# for item in move:
#     nx = x
#     ny = y
#     if item == 'U':
#         nx += dx[0]
#         ny += dy[0]
#     elif item == 'R':
#         nx += dx[1]
#         ny += dy[1]
#     elif item == 'D':
#         nx += dx[2]
#         ny += dy[2]
#     else:
#         nx += dx[3]
#         ny += dy[3]

#     if nx < 1 or nx > n or ny < 1 or ny > n:
#         continue
#     x = nx
#     y = ny

# print(x, y)

n = int(input())
x, y = 1, 1
plans = input().split()

# L, R, U, D에 따른 이동 방향
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

# 이동 계획을 하나씩 확인
for plan in plans:
    # 이동 후 좌표 구하기
    nx, ny = 0, 0
    for i in range(len(move_types)):
        if plan == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
        # 공간을 벗어나는 경우 무시
        if nx < 1 or nx > n or ny < 1 or ny > n:
            continue
        # 이동 수행
        x, y = nx, ny

print(x, y)