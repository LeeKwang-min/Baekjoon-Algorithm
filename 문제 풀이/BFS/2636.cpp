/*
작성자 : 이광민
일시 : 2021.09.13
제목 : 치즈 - 2636
풀이 : BFS를 사용하여 치즈가 모두 녹는데 걸리는 시간을 구하는 문제
       치즈에 구멍이 존재하며 해당 구멍과 외부 겉면을 어떻게 구분을 짓는지가 가장 중요한 관건이였다.
	   방법은 다음과 같다.
	   주어지는 격자의 겉면 (0, 0), (0, 1), ... 은 항상 빈칸으로 치즈가 놓일 수 없다는 조건을 사용하면 간단하게 해결이 가능하다.
	   (0,0)이 항상 빈칸이기 때문에 해당 좌표를 넣어 겉면인 것을 구하면 된다.
	   1. 겉면 (외부 공기) 범위를 찾는다 -> air[x][y]값이 0이라면 외부 공기, -1이라면 치즈 혹은 구멍
	   2. 치즈가 있는곳을 확인하며 상, 하, 좌, 우의 air 값이 0이라면 해당 치즈를 녹인다.
	   3. 치즈를 녹일 때 치즈의 갯수를 구하고 현재 시간에 해당하는 모든 치즈를 녹였다면 시간을 증가시킨다.
	   4. 위 과정을 반복한다.

	   주어진 조건을 잘 찾아보고 그 조건을 잘 이용하자.
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101];
bool chk[101][101];
int air[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
int sec = 0;
int ans = 0;
int cnt = 0;

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			chk[i][j] = false;
			air[i][j] = -1;
		}
			
}

void bfs(int x, int y) {
	init();
	queue<pair<int, int>> q;
	q.push({ x, y });
	chk[x][y] = true;
	air[x][y] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cx = cur.first;
		int cy = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] == 1) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			air[nx][ny] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) cnt++;
		}
	}

	while (cnt > 0) {
		bfs(0, 0);
		ans = cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (air[nx][ny] == 0) {
							arr[i][j] = 0;
							cnt--;
							break;
						}
					}
				}
			}
		}
		sec++;
	}

	cout << sec << '\n' << ans;
}