function solution(people, limit) {
  var answer = 0;
  people.sort((a, b) => b - a);
  let cnt = 0;
  for (let i = 0; i + cnt < people.length; i++) {
    if (people[i] + people[people.length - 1 - cnt] <= limit) {
      cnt++;
    }
    answer++;
  }
  return answer;
}

console.log(solution([70, 50, 80, 50], 100));
console.log(solution([70, 80, 50], 100));
