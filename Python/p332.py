'''
기본적으로 주어지는 N이 최대 50이고 조합을 구하는 M의 개수도 13이기 때문에
모든 경우의 수를 다 처리해도 주어진 시간 안에 처리가 가능하다.
그렇기 때문에 다음과 같은 과정을 통해 처리하면 된다.
1. M개의 치킨집을 고른다.
2. 현재 집에서 가장 가까운 치킨거리를 가지는 치킨집을 찾는다.
3. 모든 집에 대해 반복하여 합을 구한다.
4. 치킨집 조합을 돌면서 최소가 되는 경우를 찾는다.

파이썬에서는 "itertools" 라이브러리에서 combinations를 통해 조합을 간단하게 만들 수 있다.

itertools
- combinations : 조합 => [1, 2, 3, 4, 5] => list(combinations(arr, 2)) => [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '4'), ('3', '5'), ('4', '5')]
- permutations : 순열 => [1, 2, 3, 4, 5] => list(permutations(arr, 2)) => [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '1'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '1'), ('3', '2'), ('3', '4'), ('3', '5'), ('4', '1'), ('4', '2'), ('4', '3'), ('4', '5'), ('5', '1'), ('5', '2'), ('5', '3'), ('5', '4')]

주의할 점은 결과 값이 튜플로 주어진다는 점인데 파이썬의 반복문 사용법이 워낙 좋기 때문에 알아만 두고 사용하면 된다.
'''
from itertools import combinations

n, m = map(int, input().split())
totalmap = []
for _ in range(n):
    totalmap.append(list(map(int, input().split())))

chickmap = []
housemap = []
for i in range(n):
    for j in range(n):
        if totalmap[i][j] == 2:
            chickmap.append((i, j))
        elif totalmap[i][j] == 1:
            housemap.append((i, j))
            
choosemap = list(combinations(chickmap, m))

ans = 987654321
for chick in choosemap: 
    total = 0
    for house in housemap:
        dist = 987654321
        for i in chick:
            x = i[0] - house[0] if i[0] - house[0] >= 0 else house[0] - i[0]
            y = i[1] - house[1] if i[1] - house[1] >= 0 else house[1] - i[1]
            dist = min(dist, x+y)
        total += dist
    ans = min(ans, total)

print(ans)