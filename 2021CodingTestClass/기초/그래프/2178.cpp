/*
작성자 : 이상수
일시 : 2021.03.03
제목 : 미로 탐색 - 2178
풀이 : 거리를 찾는 기본적인 문제
       거리를 찾는 문제는 dfs로는 불가능하고 bfs로 풀어야 한다.
	   (dfs의 경우 현재 위치에서 갈 수 있는 모든 위치가 거리 + 1 이 되어야 하는데 그게 안됨)

	   이를 위해 bfs를 구현하여 사용하면 처리 가능하다.
*/
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int arr[101][101];
bool chk[101][101];
int dist[101][101];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(pair<int, int> p) {
	queue<pair<int, int>> q;
	int x = p.first, y = p.second;
	q.push({ x, y });
	dist[x][y] = 1;
	chk[x][y] = true;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int nowx = now.first, nowy = now.second;
		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] == 0) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[nowx][nowy] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	dfs({ 0,0 });

	cout << dist[n - 1][m - 1];
}