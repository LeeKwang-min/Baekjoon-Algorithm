n = int(input())
array = [0] * 30001

## Top Down 방식 -> stack 깊이 제한 에러에 걸림
# def make_one(x):
#     cur = int(x)
#     if cur == 1:
#         return 0

#     if array[cur] != 0:
#         return array[cur]
    
#     array[cur] = make_one(cur - 1) + 1

#     if x % 5 == 0:
#         array[cur] = min(array[cur], make_one(cur // 5) + 1)
    
#     if x % 3 == 0:
#         array[cur] = min(array[cur], make_one(cur // 3) + 1)

#     if x % 2 == 0:
#         array[cur] = min(array[cur], make_one(cur // 2) + 1)
    
#     return array[cur]

# make_one(n)

## Bottom Up 방식
for i in range(2, n+1):
    array[i] = array[i-1] + 1
    if i % 5 == 0:
        array[i] = min(array[i], array[i // 5] + 1)
    
    if i % 3 == 0:
        array[i] = min(array[i], array[i // 3] + 1)

    if i % 2 == 0:
        array[i] = min(array[i], array[i // 2] + 1)

print(array[n])