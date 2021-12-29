function solution(bridge_length, weight, truck_weights) {
  var answer = 0;
  const bridge = [];
  for (let i = 0; i < bridge_length; i++) {
    bridge.push(0);
  }
  while (bridge.length) {
    answer++;
    bridge.shift();

    if (truck_weights.length != 0) {
      const sum = bridge.reduce((num, item) => num + item, 0);
      if (sum + truck_weights[0] <= weight) bridge.push(truck_weights.shift());
      else bridge.push(0);
    }
  }

  return answer;
}

console.log(solution(2, 10, [7, 4, 5, 6]));
console.log(solution(100, 100, [10]));
console.log(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]));
