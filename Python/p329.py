# 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
# 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
'''
처음 접근한 방식은 각 삭제와 추가에 대해 해당되는 조건만을 처리하고자 하였다.
하지만, 그 과정에서 모든 조건을 내가 찾아내지 못하였는지 문제를 맞추지 못하였고 그에 따라 전수조사 방식으로 변경하였다.

전수조사를 하는 것도 크게 문제는 없었다.
총 명령어의 개수는 1000개 였고 시간 제한은 5초로 N^3으로 풀어도 큰 문제가 없었기 때문이다.

각 경우에 대해 위에 주석으로 달아둔 조건을 잘 명시하여 구현하면 해결이 가능하다.

새로운 문법
element in array -> 배열 내부에 element에 해당하는 내용이 있는지 확인하여 Boolean으로 반환한다.
'''

def check(arr):
    for i in arr:
        x, y, a = i
        if a == 0:
            if y == 0 or [x-1, y, 1] in arr or [x, y, 1] in arr or [x, y-1, 0] in arr:
                continue
            return False
        else:
            if [x, y-1, 0] in arr or [x+1, y-1, 0] in arr or ([x-1, y, 1] in arr and [x+1, y, 1] in arr):
                continue
            return False
        
    return True

def solution(n, build_frame):
    answer = []
    for build in build_frame:
        x, y, a, b = build
        if x > n or y > n:
            continue
        if b == 1:
            answer.append([x, y, a])
            if not check(answer):
                answer.remove([x, y, a])
        else:
            answer.remove([x, y, a])
            if not check(answer):
                answer.append([x, y, a])
                
    answer.sort()
    
    return answer

print(solution(5, 	[[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))