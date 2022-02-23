function solution(arr) {
    for(let i = 2; ; i++){
        let flag = true;
        for(let j = 0; j<arr.length; j++){
            if(i % arr[j] !== 0){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
}

function nlcm(num) {
    return num.reduce((a,b) => a*b / gcd(a,b))  
}

function gcd(a, b) {
    return a % b ? gcd(b, a%b) : b
}

console.log(solution([2,6,8,14]));
console.log(nlcm([2,6,8,14]));
console.log(solution([1,2,3]));