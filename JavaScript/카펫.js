function solution(brown, yellow) {
  var answer = [];
  const add = (brown + 4) / 2;
  const mul = brown + yellow;
  for (let i = 1; i <= add / 2; i++) {
    if (i * (add - i) == mul) {
      answer.push(add - i);
      answer.push(i);
      break;
    }
  }
  return answer;
}

console.log(solution(10, 2));
console.log(solution(8, 1));
console.log(solution(24, 24));
