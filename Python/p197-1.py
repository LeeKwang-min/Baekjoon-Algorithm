n = int(input())
array = [0] * 1000001

for i in input().split(): # 공백으로 입력받은 수들을 반복문으로 순회하는 방법
    array[int(i)] = 1

m = int(input())
x = list(map(int, input().split()))

for i in x:
    if array[i] == 1:
        print('yes', end=' ')
    else:
        print('no', end=' ')