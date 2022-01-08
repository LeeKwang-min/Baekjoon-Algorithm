function solution(clothes) {
  var answer = 0;

  const map = {};

  clothes.forEach((item) => {
    if (!map[item[1]]) map[item[1]] = 1;
    else map[item[1]] += 1;
  });

  answer = 1;
  const value = Object.values(map);
  for (const item of value) {
    answer *= item + 1;
  }
  answer -= 1;

  return answer;
}

console.log(
  solution([
    ["yellowhat", "headgear"],
    ["bluesunglasses", "eyewear"],
    ["green_turban", "headgear"],
  ])
);
