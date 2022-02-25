const dirXY = {
    U: [-1, 0],
    D: [1, 0],
    R: [0, 1],
    L: [0, -1]
}

function solution(dirs) {
    const answer = {};
    let [x, y] = [5, 5];
    dirs.split('').forEach((item) => {
        const [dx, dy] = dirXY[item];
        if(x + dx < 0 || x + dx > 10 || y + dy < 0 || y + dy > 10) return;
        answer[`${x}${y}${x+dx}${y+dy}`] = 1;
        answer[`${x+dx}${y+dy}${x}${y}`] = 1;
        x += dx;
        y += dy;
    });
    return Object.keys(answer).length / 2;
}

console.log(solution("ULURRDLLU"));
console.log(solution("LULLLLLLU"));
console.log(solution("UD"));