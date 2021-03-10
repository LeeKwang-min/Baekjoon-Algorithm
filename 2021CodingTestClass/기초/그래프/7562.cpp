/*
작성자 : 이상수
일시 : 2021.03.03
제목 : 나이트의 이동 - 7562
풀이 : 기존 거리이동 문제에서 dx와 dy의 값을 바꿔주면 되는 문제이다.
       그림을 그려서 dx와 dy에 대한 좌표를 만들어주면 된다.

	   하나의 chk와 dist를 사용하기 때문에 
	   각 테스트 케이스를 돌 때 2개의 배열을 초기화 해주어야 한다.
*/
#include<iostream>
#include<queue>

using namespace std;

int t, n;
bool chk[301][301];
int dist[301][301];

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	queue<pair<int, int>> q;
	q.push({ x, y });
	chk[x][y] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int nowx = cur.first, nowy = cur.second;
		for (int k = 0; k < 8; k++) {
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny]) continue;
			q.push({ nx, ny });
			dist[nx][ny] = dist[nowx][nowy] + 1;
			chk[nx][ny] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				chk[i][j] = false;
				dist[i][j] = 0;
			}
		}

		int a, b;
		cin >> a >> b;
		bfs({ a, b });

		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
}