function solution(jobs) {
  var answer = 0;
  jobs.sort((a, b) => a[0] - b[0]);
  const priorityQueue = [];
  const len = jobs.length;
  let sec = 0;

  while (priorityQueue.length || jobs.length) {
    while (jobs.length && jobs[0][0] <= sec) {
      priorityQueue.push(jobs.shift());
      priorityQueue.sort((a, b) => a[1] - b[1]);
    }

    if (priorityQueue.length == 0) sec++;
    else {
      const cur = priorityQueue.shift();
      sec += cur[1];
      answer += sec - cur[0];
    }
  }

  return parseInt(answer / len);
}

console.log(
  solution([
    [0, 3],
    [1, 9],
    [2, 6],
  ])
);
