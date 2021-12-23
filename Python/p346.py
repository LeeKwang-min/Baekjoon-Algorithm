'''
재귀를 사용한다는 점에서 DFS 문제로 출제를 했다고 한다...
문제를 막상 풀어보면 재귀를 사용하는 것 빼고는 구현 문제에 가깝다는 것을 알 수 있다.

구현은 시키는대로 잘 처리하면 되고
중간에 인덱스를 조금 신경 쓰면 된다.

1. 빈 문자열이면 바로 리턴
2. u, v로 나누기 -> '(' 와 ')'의 개수가 같아지는 인덱스를 찾아서 u = s[:idx+1], v = s[idx+1:] 로 나눈다
3. u가 올바른 문자열인지 확인 -> stack 사용 (파이썬의 스택은 list)
4. 올바르다면 return u + step(v)
5. 올바르지 않다면 -> 주어진 과정을 따라한 다음 그 문자열을 리턴한다.

위 과정을 따라 처리하면 간단하게 해결할 수 있다.
(코드가 조금 더러운데 간단하게 만들 수 있을 것 같다.)
'''
def validation(u):
    stack = []
    for i in u:
        if i == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                return False
            tmp = stack.pop()
            if tmp != '(':
                return False
            
    if len(stack) != 0:
        return False
    
    return True

def step(s):
    if s == '':
        return ''
    op = 0
    cl = 0
    idx = 0
    for i in range(len(s)):
        if s[i] == ')':
            cl += 1
        else:
            op += 1
        if op == cl:
            idx = i
            break
    u = s[:idx+1]
    v = s[idx+1:]
    if(validation(u)):
        return u + step(v)
    else:
        stmp = '('
        stmp += step(v)
        stmp += ')'
        for i in range(1, len(u) - 1):
            stmp += ')' if u[i] == '(' else '('
        return stmp
        

def solution(p):
    answer = ''
    
    answer = step(p)
    
    return answer


print(solution("(()())()"))
print(solution(")("))
print(solution("()))((()"))