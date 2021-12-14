'''
문자열이 주어졌을 때 압축을 하는 정도에 대해 굳이 끝까지 확인할 필요가 없다.
문자열 길이의 반이 넘어가는 시점에서는 뒷 부분이 동일할 수 없기 때문에 최대 반틈까지만 확인하면 되는 것이다.

내가 풀이한 방식은 이전의 문자와 현재 비교하는 문자가 같다면 카운트 값을 증가시키고 다르다면 해당 길이만큼 추가해주는 작업으로 처리했다.

책에서 나온 풀이는 길이를 추가하는 것이 아닌 'compress'라는 문자열 변수를 두고 해당 변수에 값들을 문자열로 추가하고 마지막에 최후의 길이를 비교하는 방식을 사용한다.

내가 한 방식에서 주의할 점은 처음 비교에 대해 최대 문자열의 길이가 1000이여서 첫 answer의 값을 1000으로 두고 시작했다.
하지만, 'a'와 같이 한자리수의 문자가 들어오면 첫 반복문의 시작 자체가 되지 않아서 정답이 1000으로 넘어가게 되었다.
이를 방지하기 위해 첫 answer의 값을 s의 길이로 설정해주어 처리를 하였다.

풀이의 큰 차이는 없고 파이썬 문법에서 배울점은 파이썬 방식의 삼항 연산자가 될 것 같다.
    변수 = 참값 if 조건문 else 거짓값
위와 같이 처리하면 조건이 참일 경우 참값이 변수에 들어가고 거짓일 경우 거짓값이 들어간다.
(삼항 연산자라기 보다는 ':' 가 없는 if ~ else문에 가깝다)
'''
def solution(s):
    answer = len(s) # 시작 값을 최대 길이로 주고 시작하면 테스트 케이스 5번에 대한 문제를 해결할 수 있다.
    length = len(s)
    
    for k in range(1, length // 2 + 1):
        total = 0
        prev = s[0:k];
        count = 1
        for i in range(k, length, k):
            if s[i:i+k] == prev:
                count += 1
            else:
                total += len(prev)
                if count > 1 : total += len(str(count))
                prev = s[i:i+k]
                count = 1
        total += len(prev)
        if count > 1 : total += len(str(count))
        answer = min(answer, total)
    
    return answer

def bookSolution(s):
    answer = len(s)
    for k in range(1, len(s) // 2 + 1):
        compress = ''
        prev = s[0:k]
        count = 1
        for i in range(k, len(s), k):
            if s[i:i+k] == prev:
                count += 1
            else:
                compress += str(count) + prev if count > 1 else prev
                prev = s[i:i+k]
                count = 1
        compress += str(count) + prev if count > 1 else prev
        answer = min(answer, len(compress))
    
    return answer

print(solution('ababcdcdababcdcd')) # 9
