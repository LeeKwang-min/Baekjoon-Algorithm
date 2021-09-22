n, m = map(int, input().split())
# array = [[0] * m for _ in range(n)]

ans = 0
for i in range(n):
    data = list(map(int, input().split()))
    min_data = min(data)
    if ans < min_data :
        ans = min_data

print(ans)

