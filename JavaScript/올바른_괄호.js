function solution(s){
    const stack = [];
    for(let i = 0; i<s.length; i++){
        if(s[i] === '(') stack.push(s[i]);
        else{
            const cur = stack.pop();
            if(cur !== '(') return false;
        }
    }
    if(stack.length !== 0) return false;
    return true;
}

console.log(solution("()()"));
console.log(solution("(())()"));
console.log(solution(")()("));
console.log(solution("(()("));
