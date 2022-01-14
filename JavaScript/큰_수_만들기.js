function solution(number, k) {
  const stack = [];
  for (let i = 0; i < number.length; i++) {
    const cur = number[i];
    while (k > 0 && stack[stack.length - 1] < cur) {
      stack.pop();
      k--;
    }
    stack.push(cur);
  }
  return stack.slice(0, stack.length - k).join("");
}

console.log(solution("1924", 2));
console.log(solution("1231234", 3));
console.log(solution("4177252841", 4));
