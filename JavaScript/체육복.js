function solution(n, lost, reserve) {
  var answer = 0;

  const cloth = [];
  for (let i = 0; i < n; i++) {
    cloth.push(1);
  }
  lost.map((item) => {
    cloth[item - 1]--;
  });
  reserve.map((item) => {
    cloth[item - 1]++;
  });
  for (let i = 0; i < n; i++) {
    if (cloth[i] == 0 && cloth[i - 1] == 2) {
      cloth[i] = 1;
      cloth[i - 1] = 1;
    } else if (cloth[i] == 0 && cloth[i + 1] == 2) {
      cloth[i] = 1;
      cloth[i + 1] = 1;
    }
  }
  cloth.map((i) => {
    if (i >= 1) answer++;
  });

  return answer;
}

console.log(solution(5, [2, 4], [1, 3, 5]));
console.log(solution(5, [2, 4], [3]));
console.log(solution(3, [3], [1]));
