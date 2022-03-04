function initArr(n, m){
    const arr = [];
    for(let i = 0; i<n; i++){
        const tmp = [];
        for(let j = 0; j<m; j++){
            tmp.push(0);
        }
        arr.push(tmp);
    }
    return arr;
}

function solution(arr1, arr2) {
    const answer = []; 
    arr1.forEach(v => answer.push(Array(arr2[0].length).fill(0))) 
    for(let i = 0; i<arr1.length; i++){
        for(let j = 0; j<arr2[0].length; j++){ 
            for(let jk = 0; jk<arr2.length; jk++){
                answer[i][j] += arr1[i][jk] * arr2[jk][j];
            }
        }
    }
    return answer;
}

console.log(solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]));
console.log(solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]] ,[[5, 4, 3], [2, 4, 1], [3, 1, 1]]));

// answer[0][0] 
//  = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0] + arr1[0][2] * arr2[2][0]

// answer[0][1]
//  = arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1] + arr1[0][2] * arr2[2][1]

// answer[0][2]
//  = arr1[0][0] * arr2[0][2] + arr1[0][1] * arr2[1][2] + arr1[0][2] * arr2[2][2]

// answer[1][0]
//  = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0] + arr1[1][2] * arr2[2][0]

// answer[1][1]
//  = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1] + arr1[1][2] * arr2[2][1]

// answer[1][2]
//  = arr1[1][0] * arr2[0][2] + arr1[1][1] * arr2[1][2] + arr1[1][2] * arr2[2][2]

