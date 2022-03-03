function solution(board)
{
    let answer = 0;
    const n = board.length;
    const m = board[0].length;

    if(n < 2 || m < 2){
        for(let i = 0; i<n; i++){
            for(let j = 0; j<n; j++){
                if(board[i][j] === 1) return 1;
            }
        }
        return 0;
    }

    for(let i = 1; i<n; i++){
        for(let j = 1; j<m; j++){
            if(board[i][j] >= 1){
                board[i][j] = Math.min(board[i-1][j], board[i][j-1], board[i-1][j-1]) + 1;
                answer = answer > board[i][j] ? answer : board[i][j];
            }
        }
    }

    return answer * answer;
}

console.log(solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]));
console.log(solution([[0,0,1,1],[1,1,1,1]]));
console.log(solution([[1],[1]]));
console.log(solution([[0],[0]]));
console.log(solution([[0]]));
console.log(solution([[1]]));