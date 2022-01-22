function dfs(cur, cnt, numbers, target) {
  let answer = 0;
  if (cnt == numbers.length) {
    if (cur == target) return 1;
    return 0;
  }
  answer += dfs(cur + numbers[cnt], cnt + 1, numbers, target);
  answer += dfs(cur - numbers[cnt], cnt + 1, numbers, target);
  return answer;
}

function solution(numbers, target) {
  return dfs(0, 0, numbers, target);
}

console.log(solution([1, 1, 1, 1, 1], 3));
