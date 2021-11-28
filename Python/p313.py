data = list(map(int, input()))

zero_one = [0] * 2
n = -1

for i in data:
    if n == i:
        continue
    else:
        zero_one[i] += 1
        n = i
        
print(min(zero_one[0], zero_one[1]))