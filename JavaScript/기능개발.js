function solution(progresses, speeds) {
  var answer = [];
  let days = 0;
  const stack = [];

  for (const i in progresses) {
    const percent =
      (100 - progresses[i]) % speeds[i] == 0
        ? parseInt((100 - progresses[i]) / speeds[i])
        : parseInt((100 - progresses[i]) / speeds[i]) + 1;
    stack.push(percent);
  }

  while (stack.length > 0) {
    days++;
    let count = 0;
    if (stack[0] <= days) {
      while (stack[0] <= days) {
        stack.shift();
        count++;
        if (stack.length == 0) break;
      }
      answer.push(count);
    }
  }

  return answer;
}

console.log(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]));
console.log(solution([93, 30, 55], [1, 30, 5]));
