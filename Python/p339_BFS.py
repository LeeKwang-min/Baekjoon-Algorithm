'''
정리해야 할 부분들이 조금 있다.
1. 이 문제에서 주어지는 입력은 최대 백만줄이다. (a, b에 대한 정보를 입력하는 부분)
2. 파이썬에서 deque의 사용 방법은 "변수 = deque(초기배열)" 이다.

우선 1번에 대해 정리하면
처음 풀이는 다익스트라로 풀이를 시작했다.
다익스트라로 풀었을 때 시간 초과를 받아서 다익스트라로 풀지 못하는 문제이구나... 라는 생각을 하고 BFS로 풀이를 진행하였다.
하지만 BFS로 풀어도 마찬가지로 시간 초과를 받게 되었고 질문을 읽어보다 보니 주어지는 입력이 최대 백만줄이여서 문제가 생긴다는 것을 알게 되었다.
여기서 새로운 사실을 알게 되었는데
파이썬에서 입력이 '개행'을 통해서 이루어질 때 sys를 import하여 sys.stdin.readline을 이용하는 것은 알고 있었다.
하지만, 이를 처음부터 사용하는 것은 문제가 있다는 것이다.
앞선 풀이에서 처음부터 input = sys.... 로 처리 하였으나 에러가 발생하였고 반대로 
a, b에서만 사용하자 문제가 발생하지 않았다.  (이 부분에 대해서는 그냥 그렇구나 하고 넘어가자 백준 자체 문제일 수도 있다.)
그냥 입력이 너무 많이 주어질 때에는 그냥 input으로 처리하면 시간 초과가 난다는 것만 알아두자

deque의 사용방법은 무조건 외워서 알아두자
'''
from collections import deque
import sys

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)

dist = [-1] * (n + 1)
dist[x] = 0

q = deque([x])
while q:
    now = q.popleft()
    for nxt in graph[now]:
        if dist[nxt] == -1:
            dist[nxt] = dist[now] + 1
            q.append(nxt)

flag = False
for i in range(1, n + 1):
    if dist[i] == k:
        print(i)
        flag = True

if not flag:
    print(-1)