function dfs(x, visited, n, computers) {
  visited[x] = 1;
  for (let i = 0; i < n; i++) {
    if (visited[i] != 0 || computers[x][i] == 0) continue;
    dfs(i, visited, n, computers);
  }
}

function solution(n, computers) {
  var answer = 0;

  const visited = new Array(n).fill(0);

  for (let i = 0; i < n; i++) {
    if (visited[i] != 0) continue;
    dfs(i, visited, n, computers);
    answer++;
  }

  return answer;
}

console.log(
  solution(3, [
    [1, 1, 0],
    [1, 1, 0],
    [0, 0, 1],
  ])
);
console.log(
  solution(3, [
    [1, 1, 0],
    [1, 1, 1],
    [0, 1, 1],
  ])
);
