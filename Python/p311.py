# 그리디 기출 문제
# 정렬의 경우 처음에 내림차순으로 진행을 하였으나 1000, 1, 1, 1, 1, 1, 1 과 같은 값이 들어오면 6개의 그룹을 형성할 수 있음에도 1개의 팀도 못만든다는 결론이 내려진다.
# 그렇기 때문에 오름차순 정렬 후 차례를 살피는 것이 맞다.
# 핵심은 다음과 같다.
# '현재 그룹에 포함된 모험가의 수'가 '현재 확인하고 있는 공포도' 보다 크거나 같다면 그룹화 한다.
# 다시 말해 가장 적은 공포도를 가진 모험가부터 그룹을 형성하면서 그룹원의 수를 미리 증가시키고 공포도와 그룹원 수를 비교하여 
# 그룹원 수가 더 많거나 같다면 그룹으로 처리하고 마무리 짓는 것이다.
n = int(input())
fear = list(map(int, input().split()))

fear.sort()

result = 0
group = 0

for i in fear:
    group += 1
    if group >= i:
        result += 1
        group = 0

print(result)

'''
5
2 3 1 2 2

// 2
'''