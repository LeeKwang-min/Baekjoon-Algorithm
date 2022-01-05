function tmp(arr, target) {
  let start = 0;
  let end = arr.length;
  while (start < end) {
    const mid = parseInt((start + end) / 2);
    if (target <= arr[mid]) end = mid;
    else start = mid + 1;
  }
  return arr.length - start;
}

function solution(info, query) {
  var answer = [];
  const data = {};
  for (const t of info) {
    const w = t.split(" ");
    const word = [
      `----`,
      `${w[0]}---`,
      `-${w[1]}--`,
      `--${w[2]}-`,
      `---${w[3]}`,
      `${w[0]}${w[1]}--`,
      `${w[0]}-${w[2]}-`,
      `${w[0]}--${w[3]}`,
      `-${w[1]}${w[2]}-`,
      `-${w[1]}-${w[3]}`,
      `--${w[2]}${w[3]}`,
      `${w[0]}${w[1]}${w[2]}-`,
      `${w[0]}${w[1]}-${w[3]}`,
      `${w[0]}-${w[2]}${w[3]}`,
      `-${w[1]}${w[2]}${w[3]}`,
      `${w[0]}${w[1]}${w[2]}${w[3]}`,
    ];
    for (const item of word) {
      if (!data[item]) data[item] = [];
      data[item].push(parseInt(w[4]));
    }
  }

  for (const t in data) {
    data[t].sort((a, b) => a - b);
  }

  for (const t of query) {
    const w = t.split(" and").join("").split(" ");
    const word = w[0] + w[1] + w[2] + w[3];
    data[word] ? answer.push(tmp(data[word], w[4])) : answer.push(0);
  }

  return answer;
}

const info = [
  "java backend junior pizza 150",
  "python frontend senior chicken 210",
  "python frontend senior chicken 150",
  "cpp backend senior pizza 260",
  "java backend junior chicken 80",
  "python backend senior chicken 50",
];
const query = [
  "java and backend and junior and pizza 100",
  "python and frontend and senior and chicken 200",
  "cpp and - and senior and pizza 250",
  "- and backend and senior and - 150",
  "- and - and - and chicken 100",
  "- and - and - and - 150",
];

console.log(solution(info, query));
