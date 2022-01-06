function solution(tickets) {
  var answer = [];
  tickets.sort();
  const visited = new Array(tickets.length).fill(false);
  function dfs(cur, cnt, route) {
    if (cnt == tickets.length && answer.length == 0) {
      answer = route;
      return;
    }
    for (let i = 0; i < tickets.length; i++) {
      if (visited[i]) continue;
      if (tickets[i][0] == cur) {
        visited[i] = true;
        dfs(tickets[i][1], cnt + 1, [...route, tickets[i][1]]);
        visited[i] = false;
      }
    }
  }
  dfs("ICN", 0, ["ICN"]);
  return answer;
}

console.log(
  solution([
    ["ICN", "JFK"],
    ["HND", "IAD"],
    ["JFK", "HND"],
  ])
);
console.log(
  solution([
    ["ICN", "SFO"],
    ["ICN", "ATL"],
    ["SFO", "ATL"],
    ["ATL", "ICN"],
    ["ATL", "SFO"],
  ])
);
