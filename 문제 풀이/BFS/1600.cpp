/*
작성자 : 이상수
일시 : 2021.04.02
제목 : 말이 되고픈 원숭이 - 1600
풀이 : 잘 풀어놓고 마지막 답 출력에서 잘못한 문제...
       잘못한 부분은 정답 출력을 ans - 1로 출력을 해서였는데,
	   마지막 ans를 찾는 과정에서 만약 정답이 없어서 ans에 -1이
	   저장되어 있다고 할 때 출력을 하면 -2가 나와서 오답 처리가 되었다...

	   그 외에 방식은 같다.
	   예전 벽깨고 이동하기 문제때와 같이 말 이동방식을 사용 가능하면 말처럼 이동하고
	   그렇지 않으면 그냥 이동하는 것을 3차원 chk 배열을 사용하여 풀면 되었다.

	   이동 가능한 횟수가 남아있다면 횟수를 하나 감소시키고 이동한 값을 저장해주고
	   횟수가 없다면 인접한 칸으로만 이동을 가능하게 한다.

	   이를 사용하면 간단하게 해결 가능하다
	   (실수좀... 하지... 말자...)

	   실수를 발견한 방법
		- 극단적인 값을 넣어보면 된다 (배열이 1X1 이라던가 가지 못하는 값이라던가 등등)
*/

#include<iostream>
#include<queue>

using namespace std;

int k, n, m;
int chk[201][201][31];
int arr[201][201];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int hdx[] = { -2, -2, -1, 1, 2, 2, 1, -1 }; // 8
int hdy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},k });
	chk[0][0][k] = 1;
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first.first, y = cur.first.second, z = cur.second;

		if (z > 0) {
			for (int k = 0; k < 8; k++) {
				int nx = x + hdx[k];
				int ny = y + hdy[k];
				int nz = z - 1;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (chk[nx][ny][nz] || arr[nx][ny] == 1) continue;
				q.push({ {nx, ny}, nz });
				chk[nx][ny][nz] = chk[x][y][z] + 1;
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1 || chk[nx][ny][z]) continue;
			q.push({ { nx, ny }, z });
			chk[nx][ny][z] = chk[x][y][z] + 1;
		}
		/*
		for (int k = 0; k < 8; k++) {
			int nx = x + hdx[k];
			int ny = y + hdy[k];
			int nz = z - 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0) continue;
			if (chk[nx][ny][nz] || arr[nx][ny] == 1) continue;
			q.push({ {nx, ny}, nz });
			chk[nx][ny][nz] = chk[x][y][z] + 1;
		}
		*/
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	bfs();

	int ans = -1;
	for (int i = 0; i <= k; i++) {
		if (chk[n - 1][m - 1][i] != 0) {
			if(ans == -1 || ans > chk[n - 1][m - 1][i] - 1)
				ans = chk[n - 1][m - 1][i] - 1;
		}
	}
	cout << ans;
}