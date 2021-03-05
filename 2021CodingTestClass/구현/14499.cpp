/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 주사위 굴리기 - 14499
풀이 : 구현 문제.
       처음 해맨 이유는 접근 방식이 주사위가 1이 위에 있을 때 동서남북으로 이동하면 
	   값이 바뀌게 되는데 좌->상, 우->상 으로 할 경우 좌 우에 있는 값이 바뀌기 때문에
	   이를 어떻게 하면 처리할 수 있을까 라는 고민이 있었다.
	   (이렇게 어디서 어떻게 이동할 경우 그 곳의 값이 저장된 다른 배열을 참조하여 정답 추출)

	   하지만, 다른 관점에서 접근하면 간단하게 해결이 되었다.

	   주사위는 가만히 있고 주사위에 적힌 수들만 이동에 따라 바뀌도록 하면 되었다.
	   즉, 주사위의 방향에는 변함이 없도록 하면 되었다.

	   그 결과로 나온 것이 아래의 ewns에 따른 값 변화이다.

	   각 변화에 대해 
	   1. 범위를 확인해주고
	   2. 이동에 대한 주사위 값 변화를 적용하고
	   3. 상단(dice[1]) 값을 출력해주고
	   4. 지도와 주사위의 값에 대한 조건을 처리해주고
	   5. 현재 주사위의 위치를 바꿔준다.

	   이렇게 차례대로 처리하면 통과가 가능하다.

	   실제로 주사위를 가져와서 풀었다...
*/
#include<iostream>

using namespace std;

int n, m, x, y, k;
int mp[21][21];
int dice[7];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];

	while (k--) {
		int ewns;
		cin >> ewns;

		int nx = x + dx[ewns - 1];
		int ny = y + dy[ewns - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (ewns == 1) {
			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (ewns == 2) {
			int tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (ewns == 3) {
			int tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
		}
		else {
			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}

		cout << dice[1] << '\n';

		if (mp[nx][ny] == 0) {
			mp[nx][ny] = dice[6];
		}
		else {
			dice[6] = mp[nx][ny];
			mp[nx][ny] = 0;
		}
		x = nx;
		y = ny;
	}
}