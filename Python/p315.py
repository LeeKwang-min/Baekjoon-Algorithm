n, m = map(int, input().split())
ball = list(map(int, input().split()))

# 정렬 라이브러리 사용하여 O(N^2) 처리
ball.sort() 

total = 0
for i in range(n):
    for j in range(i+1, n):
        if ball[i] < ball[j]:
            total += 1
            
# 계수 정렬을 사용하여 O(N) 처리
'''
array = [0] * 11

for x in ball:
    array[x] += 1
    
result = 0
for i in range(1, m+1):
    n -= array[i] # n을 빼가면서 이 전에 처리했던 값들은 제외시킨다.
    result += array[i] * n            
'''

print(total)

'''
5 3
1 3 2 3 2
// 8

8 5
1 5 4 3 2 4 5 2
// 25
'''