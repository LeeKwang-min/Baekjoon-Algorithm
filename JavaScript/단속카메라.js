function solution(routes) {
  var answer = 1;
  routes.sort((a, b) => a[1] - b[1]);
  let camera_position = routes[0][1];
  for (let i = 1; i < routes.length; i++) {
    if (camera_position < routes[i][0]) {
      answer++;
      camera_position = routes[i][1];
    }
  }
  return answer;
}

console.log(
  solution([
    [-20, -15],
    [-14, -5],
    [-18, -13],
    [-5, -3],
  ])
);

console.log(
  solution([
    [0, 1],
    [0, 1],
    [0, 1],
    [0, 1],
  ])
);

console.log(
  solution([
    [-100, 100],
    [50, 170],
    [150, 200],
    [-50, -10],
    [10, 20],
    [30, 40],
  ])
);

console.log(
  solution([
    [-2, -1],
    [1, 2],
    [-3, 0],
  ])
);
console.log(solution([[0, 0]]));
console.log(
  solution([
    [0, 1],
    [0, 1],
    [1, 2],
  ])
);
console.log(
  solution([
    [0, 1],
    [2, 3],
    [4, 5],
    [6, 7],
  ])
);
console.log(
  solution([
    [-20, -15],
    [-14, -5],
    [-18, -13],
    [-5, -3],
  ])
);
console.log(
  solution([
    [-20, 15],
    [-14, -5],
    [-18, -13],
    [-5, -3],
  ])
);
console.log(
  solution([
    [-20, 15],
    [-20, -15],
    [-14, -5],
    [-18, -13],
    [-5, -3],
  ])
);
