function wordCheck(word, base) {
  return word.split("").filter((item, idx) => item != base[idx]).length;
}

function dfs(cur, words, visited) {
  const q = [];
  visited[cur] = 0;
  q.push(cur);
  while (q.length) {
    const cur = q.shift();
    for (let i of words) {
      if (visited[i] != 0 || wordCheck(cur, i) != 1) continue;
      visited[i] = visited[cur] + 1;
      q.push(i);
    }
  }
}

function solution(begin, target, words) {
  if (!words.includes(target)) return 0;
  const visited = {};
  words.map((item) => {
    visited[item] = 0;
  });
  dfs(begin, words, visited);
  return visited[target];
}

console.log(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]));
console.log(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]));
