function solution(s)
{
    const stack = [];
    s.split('').forEach((item) => {
        if(stack.length === 0 || stack[stack.length - 1] !== item) stack.push(item);
        else stack.pop();
    });
    return stack.length === 0 ? 1 : 0;
}

console.log(solution('baabaa'));
console.log(solution('cdcd'));