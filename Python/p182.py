n, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

for i in range(k):
    # 무조건 바꿔주면 되는게 아니다. (놓친 부분) -> A의 최소값이 B의 최대값보다 클 수도 있다.
    if A[i] < B[i]:
        A[i] = B[i]
    else:
        break

print(sum(A))

'''
5 3
1 2 5 4 3
5 5 6 6 5

// 26
'''