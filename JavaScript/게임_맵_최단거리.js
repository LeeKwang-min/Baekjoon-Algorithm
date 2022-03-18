const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

function solution(maps) {
    const n = maps.length;
    const m = maps[0].length;
    const q = [];
    const dist = Array.from(Array(n), item => Array(m).fill(0));
    dist[0][0] = 1;
    q.push([0, 0]);
    while(q.length){
        const [x, y] = q.shift();
        for(let k = 0; k<4; k++){
            const nx = x + dx[k];
            const ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] !== 0 || maps[nx][ny] === 0) continue;
            q.push([nx, ny]);
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    return dist[n-1][m-1] === 0 ? -1 : dist[n-1][m-1];
}

console.log(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]));
console.log(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]));
console.log(solution([[1,0,0,0,0],[1,0,0,0,0],[1,0,0,0,0],[1,0,0,0,0],[1,1,1,1,1]]));
console.log(solution([[1,0,],[1,1]]));
console.log(solution([[1,0,],[0,1]]));
console.log(solution([[1,1],[0,1], [1,1]]));