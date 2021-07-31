/*
작성자 : 이광민
일시 : 2021.06.04
제목 : 16948 - 데스 나이트
풀이 : 체스 말의 이동 방식에 따라 특정 좌표에서 다른 좌표까지 이동이 가능한지 불가능한지 확인하는 문제이다.
       일반적으로 dx, dy 배열을 설정하고 나서 BFS를 수행해주면 된다.

	   기본 dist의 값을 -1로 두면 후에 따로 불가능한 경우에 대해 예외 처리를 해줄 필요가 없어진다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int dist[201][201];
bool chk[201][201];
int r1, c1, r2, c2;

int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = -1;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ r1, c1 });
	chk[r1][c1] = true;
	dist[r1][c1] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	init();
	bfs();
	cout << dist[r2][c2];
}