from collections import deque
n = int(input())

cost = [0] * (n + 1)
graph = [[] for _ in range(n + 1)]
inDegree = [0] * (n + 1)
totalSum = [0] * (n + 1)

for i in range(1, n+1):
    data = list(map(int, input().split()))
    cost[i] = data[0]
    for j in data[1:-1]:
        inDegree[i] += 1
        graph[j].append(i)
        
q = deque()
        
for i in range(1, n+1):
    if inDegree[i] == 0:
        q.append(i)
        totalSum[i] = cost[i]
        
while q:
    n = q.popleft()
    for i in graph[n]:
        inDegree[i] -= 1
        if inDegree[i] == 0:
            q.append(i)
            totalSum[i] = totalSum[n] + cost[i]
            
for i in range(1, n+1):
    print(totalSum[i])
    
'''
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

// 10
// 20
// 14
// 18
// 17
'''