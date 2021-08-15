/*
작성자 : 이광민
일시 : 2021.06.30
제목 : 16973 - 직사각형 탈출
풀이 : 기본적인 BFS 문제에서 조금 변화된 문제이다.
       기존의 BFS 문제가 하나의 정점만을 이동시키고 확인하는 것이였다면
	   이 문제는 주어진 범위를 모두 이동시키는 문제이다.

	   이 문제에서 주어지는 범위는 사각형 형태로 주어지며, 이동하는 방향에 따라 확인해야 하는 값이 '한 줄'로 변한다.

	   그렇기 때문에 BFS로 이동하며
	   범위 내에 벽이 있는지 없는지 확인해주면 된다.

	   하지만, 이동하는 모든 경우를 매 탐색마다 확인을 하게 되면 O(n^3)으로 n의 크기가 최대 1000이기 때문에 이는 시간초과가 발생한다.

	   주어지는 범위가 사각형이라는 특징을 사용하여 각 이동에 대해 한 줄씩 변화되는 값들만 확인해주면 해결 가능하다.

	   위로 이동하는 경우 -> x - 1번째 줄 확인
	   오른쪽으로 이동하는 경우 -> y + w - 1번째 줄 확인
	   아래로 이동하는 경우 -> x + h - 1번째 줄 확인
	   왼쪽으로 이동하는 경우 -> y - 1번째 줄 확인

	   각 경우를 확인하여 이동이 가능하다면 좌표를 큐에 넣어 탐색을 진행하면 된다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, h, w;
int Sx, Sy, Fx, Fy;
int arr[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ Sx, Sy });
	chk[Sx][Sy] = true;
	dist[Sx][Sy] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= m + 1) continue;
			if (chk[nx][ny]) continue;
			bool wall = false;
			if (k == 0) {
				for (int j = y; j < y + w; j++)
					if (arr[nx][j] == 1) {
						wall = true;
						break;
					}
			}
			else if (k == 1) {
				if (ny + w - 1 > m) wall = true;
				else {
					for (int i = x; i < x + h; i++)
						if (arr[i][ny + w - 1] == 1) {
							wall = true;
							break;
						}
				}
			}
			else if (k == 2) {
				if (nx + h - 1 > n) wall = true;
				else {
					for (int j = y; j < y + w; j++)
						if (arr[nx + h - 1][j] == 1) {
							wall = true;
							break;
						}
				}
			}
			else {
				for(int i = x; i < x + h; i++)
					if (arr[i][ny] == 1) {
						wall = true;
						break;
					}
			}

			if (wall) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	cin >> h >> w >> Sx >> Sy >> Fx >> Fy;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = -1;

	bfs();
	cout << dist[Fx][Fy];
}