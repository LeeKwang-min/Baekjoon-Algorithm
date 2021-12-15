'''
문제에서 요구하는 '90도 회전'하는 함수와 '홈에 맞는 키인지'를 찾는 함수만 잘 구현하면 문제없이 해결되는 문제이다.
90도 회전의 경우 각 좌표값들이 회전하게 되면 어느 좌표로 이동하는지를 잘 확인해보자
예를들어 3X3 크기의 좌표를 회전한다고 하면 
(오게될 좌표) -> (이동하는 좌표)
(0, 0) -> (2, 0)  (0, 1) -> (1, 0)  (0, 2) -> (0, 0)
남은것들을 생략하고 보게되면 다음과 같은 공식을 가지게 된다.
rotation[y][N-1-x] = arr[x][y]
이 공식을 잘 사용하여 회전 함수를 구현하면 된다.

열쇠의 홈을 찾는 방식은 각 범위를 생각해서 돌리고 할 필요 없이
처음부터 자물쇠의 크기를 3배 키워서 기존의 자물쇠는 중앙에 위치한다고 생각해보자
그렇다면 (0,0)에서 시작하여 한칸씩 오른쪽, 아래쪽으로 이동하면서 기존의 값들과 새로운 좌표의 값들을 따지면 된다.
'''

def rotation(key):
    n = len(key)
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n-1-i] = key[i][j]
    return result
            
def check(a):
    n = len(a) // 3
    for i in range(n, 2*n):
        for j in range(n, 2*n):
            if a[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    
    total = [[0] * (n*3) for _ in range(n*3)]
    
    for i in range(n):
        for j in range(n):
            total[n+i][n+j] = lock[i][j]
    
    for k in range(4):
        for i in range(3 * n - m + 1):
            for j in range(3 * n - m + 1):
                for x in range(m):
                    for y in range(m):
                        total[x + i][y + j] += key[x][y]
                if check(total):
                    return True
                for x in range(m):
                    for y in range(m):
                        total[x + i][y + j] -= key[x][y]
        key = rotation(key)
    
    return False

print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))