function solution(s) {
  return s
    .split(" ")
    .map((item) => {
      if (item === "") return "";
      return item[0].toUpperCase() + item.substr(1).toLowerCase();
    })
    .join(" ");
}

console.log(solution("3people unFollowed me"));
console.log(solution("for the last week"));
// 예외 케이스 (공백이 연속될 경우 그냥 toUpperCase 사용시 런타임 에러 발생)
console.log(solution("hello  good"));
