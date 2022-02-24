function solution(s) {
    const sArr = s.split(' ');
    return sArr
        .map((item) => Number.parseInt(item))
        .sort((a, b) => a - b)
        .filter((item, index) => index === 0 || index === sArr.length - 1)
        .join(' ');
}

console.log(solution("1 2 3 4"));
console.log(solution("-1 -2 -3 -4"));
console.log(solution("-1 -1"));