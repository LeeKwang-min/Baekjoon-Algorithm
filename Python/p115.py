# position = input()
# x, y = int(position[1]), position[0]
# alpha_to_num = ['a','b','c','d','e','f','g','h']
# y = alpha_to_num.index(y) + 1

# dx = [-2, -2, -1, 1, 2, 2, 1, -1]
# dy = [-1, 1, 2, 2, 1, -1, -2, -2]

# cnt = 0
# for i in range(8):
#     nx = x + dx[i]
#     ny = y + dy[i]
#     if nx < 1 or nx > 8 or ny < 1 or ny > 8:
#         continue
#     cnt += 1

# print(cnt)

input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1

steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

result = 0
for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]
    if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
        result += 1

print(result)

# ord() : 특정한 한 문자를 아스키 코드 값으로 변환해 주는 함수
# chr() : 아스키 코드 값을 문자로 변환해 주는 함수 (10진수, 16진수 사용 가능)