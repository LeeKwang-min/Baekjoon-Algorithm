number = list(map(int, input()))
total = 0

for i in number:
    total = max(total+i, total*i)

result = number[0]

for i in range(1, len(number)):
    num = number[i]
    if num < 2 or result < 2:
        result += num
    else:
        result *= num

print(total)
print(result)

'''
02984
// 576

567
// 210
'''