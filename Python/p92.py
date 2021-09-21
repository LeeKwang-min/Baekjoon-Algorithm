n, m, k = map(int, input().split())
array = list(map(int, input().split()))

array.sort(reverse= True)

ans = 0
cnt = 0
while(m > 0):
    if cnt == k:
        ans += array[1]
        cnt = 0
    else:
        ans += array[0]
        cnt += 1
    m -= 1

print(ans)

first = array[0]
second = array[1]

# 8 3 // 식 : 8 / 4 * 3 = 6 -> 가장 큰 수가 6번 반복된다는 것이다.
count = int(m / (k + 1)) * k # 반복되는 수열을 몇번 반복하는지 구해주고
count += m % (k + 1) # 남는 것을 구한 다음 더해준다

result = 0
result += (count) * first # 가장 큰 수가 몇번 나오는지 구했으니 그 수를 더해준다.
result += (m - count) * second # 두번째로 작은 수를 더해준다.

print(result)