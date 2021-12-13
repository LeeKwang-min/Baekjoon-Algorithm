string = input()
word = []
number = []
for i in string:
    if i.isdigit():
        number.append(int(i))
    else:
        word.append(i)

word.sort()

for i in word:
    print(i, end='')
if sum(number) != 0:
    print(sum(number))

'''
K1KA5CB7

AJKDLSI412K4JSJ9D
'''