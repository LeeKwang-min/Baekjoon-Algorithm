/*
작성자 : 이상수
일시 : 2021.03.01
제목 : 토마토 - 7576
풀이 : dfs로 풀이가 불가능한 문제다. bfs 사용해야 한다.
       토마토가 하나만 주어진다면 미로탐색 문제와 똑같이 풀면 되는데,
	   토마토가 여러가지가 있을 수 있다.

	   이 때, 모든 토마토에서 똑같이 전파가 되어 익기 때문에
	   어떻게 처리할지가 중요하였다.

	   처음 생각한 방식은 탐색을 하다가 dist에 이미 값이 있다면 
	   그 값을 새로운 값과 비교하여 더 작은 값을 넣는 쪽으로 하였는데,
	   이렇게 하면 탐색 과정에서 문제가 있었다.

	   그래서 다시 생각한 방식이 처음 토마토가 있는 위치를 입력받을 때
	   모든 토마토가 있는 위치를 큐에 넣어두고 그 다음 bfs 탐색을 하는 방식이였다.

	   이렇게 진행하게 되면 처음 토마토가 있는 모든 위치에서 하루만에 
	   옆으로 퍼져나가게 되고 그 상태에서 큐의 상황은 
	   모든 2일차 토마토들의 위치가 담겨있다.

	   이렇게 반복하면서 만약 chk가 true인 곳을 만났다면 그 말은 더 빠른 날에
	   토마토가 익었다는 말이므로 굳이 바꿀 필요가 없었다.

	   단, 정답은 시작일이 0이 아닌 1로 주어 처리하였기 때문에 
	   정답에 -1을 한 값이 정답이다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int tomato[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int nowx = cur.first, nowy = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tomato[nx][ny] == -1 || chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[nowx][nowy] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == -1) dist[i][j] = -1;
			if (tomato[i][j] == 1) {
				q.push({ i, j });
				chk[i][j] = true;
				dist[i][j] = 1;
			}
		}
	}

	bfs();

	int ans = 0;
	bool cant = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0) cant = true;
			ans = max(ans, dist[i][j]);
		}
	}

	if (cant) cout << -1;
	else cout << ans - 1;
}