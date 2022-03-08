function solution(n) {
    const contryNum = [1, 2, 4]
    let answer = '';
    while(n > 0){
        answer = contryNum[(n - 1) % 3] + answer;
        n = Math.floor((n - 1) / 3);
    }
    return answer;
}

console.log(solution(1));
console.log(solution(2));
console.log(solution(3));
console.log(solution(4));