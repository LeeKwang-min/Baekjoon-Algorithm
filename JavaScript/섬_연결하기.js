function find_parent(parent, x) {
  if (parent[x] != x) {
    parent[x] = find_parent(parent, parent[x]);
  }
  return parent[x];
}

function union_parent(parent, a, b) {
  a = find_parent(parent, a);
  b = find_parent(parent, b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

function solution(n, costs) {
  var answer = 0;

  let parent = [];
  for (let i = 0; i < n; i++) {
    parent.push(i);
  }
  costs.sort((a, b) => a[2] - b[2]);
  costs.forEach((item) => {
    const [a, b, c] = item;
    if (find_parent(parent, a) != find_parent(parent, b)) {
      union_parent(parent, a, b);
      answer += c;
    }
  });

  return answer;
}

console.log(
  solution(4, [
    [0, 1, 1],
    [0, 2, 2],
    [1, 2, 5],
    [1, 3, 1],
    [2, 3, 8],
  ])
);
