function solution(genres, plays) {
  var answer = [];
  const data = {};
  const total = {};

  genres.map((item, idx) => {
    if (!total[item]) {
      total[item] = plays[idx];
      data[item] = [[plays[idx], idx]];
    } else {
      total[item] += plays[idx];
      data[item].push([plays[idx], idx]);
    }
  });

  const arr = [];
  for (const item in total) {
    arr.push([item, total[item]]);
  }

  arr.sort((a, b) => b[1] - a[1]);

  arr.map((item) => {
    const genre = item[0];
    data[genre].sort((a, b) => b[0] - a[0]);
    if (data[genre].length == 1) {
      answer.push(data[genre][0][1]);
    } else {
      answer.push(data[genre][0][1]);
      answer.push(data[genre][1][1]);
    }
  });

  return answer;
}

function amazingSolution(genres, plays) {
  var dic = {};
  genres.forEach((t, i) => {
    dic[t] = dic[t] ? dic[t] + plays[i] : plays[i];
  });

  var dupDic = {};
  return genres
    .map((t, i) => ({ genre: t, count: plays[i], index: i }))
    .sort((a, b) => {
      if (a.genre !== b.genre) return dic[b.genre] - dic[a.genre];
      if (a.count !== b.count) return b.count - a.count;
      return a.index - b.index;
    })
    .filter((t) => {
      if (dupDic[t.genre] >= 2) return false;
      dupDic[t.genre] = dupDic[t.genre] ? dupDic[t.genre] + 1 : 1;
      return true;
    })
    .map((t) => t.index);
}

console.log(
  solution(
    ["classic", "pop", "classic", "classic", "pop"],
    [500, 600, 150, 800, 2500]
  )
);
console.log(
  solution(
    ["classic", "pop", "classic", "classic", "classic"],
    [500, 1000, 400, 300, 200, 100]
  )
);
