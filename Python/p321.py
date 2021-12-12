score = list(map(int, input()))
ultimate = False

for i in range(1, len(score)):
    if sum(score[:i]) == sum(score[i:]):
        ultimate = True
        break

if ultimate:
    print('LUCKY')
else:
    print('READY')