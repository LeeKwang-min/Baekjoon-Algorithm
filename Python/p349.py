from itertools import permutations

maxans = 0
minans = 987654321

n = int(input())
arr = list(map(int, input().split()))
prop = list(map(int, input().split())) # 0: +, 1: -, 2: x, 3: %

