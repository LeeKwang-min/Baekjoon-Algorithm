n = int(input())
array = []
for i in range(n):
    data = input().split()
    array.append((data[0], int(data[1]))) # 튜플로 저장하는 방법 -> split으로 구분지어 저장 -> 정수는 int로 변경하여 저장

def setting(data):
    return data[1]

result = sorted(array, key=setting)
for i in result:
    print(i[0], end=' ')

'''
2
홍길동 95
이순신 77

// 이순신 홍길동
'''