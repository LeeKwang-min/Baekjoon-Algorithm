# 파라메트릭 서치 문제 : 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
# 파라메트릭 서치는 전형적인 '이진 탐색'문제이다.
# 결정 문제 : 네, 아니오로 대답하는 문제

# 일단 문제가 나왔을 때 탐색해야하는 범위가 말도 안되게 크다면 '이진 탐색'을 사용하면 된다.

# 파라메트릭 서치 문제 유형은 이진 탐색을 재귀적으로 구현하지 않고 '반복문'을 이용해 구현하면 더 간결하게 문제를 풀 수 있다.

n, m = map(int, input().split())
rice_cake = list(map(int, input().split()))

def cut_height(height):
    sum = 0
    for i in rice_cake:
        sum += (i - height) if i - height > 0 else 0
    return sum

start = 0
end = max(rice_cake)
result = 0

while start <= end:
    mid = (start + end) // 2
    sum = cut_height(mid)
    if sum < m:
        end = mid - 1
    else:
        result = mid
        start = mid + 1

print(result)

'''
4 6
19 15 10 17

// 15

'''