n = int(input())
cnt = 0

for h in range(n+1):
    for m in range(60):
        for s in range(60):
            if '3' in str(h) + str(m) + str(s):
                cnt += 1

print(cnt)

# range(60) -> i = 0; i < 60; i++
# range(n+1) -> i = 0; i <= n; i++

