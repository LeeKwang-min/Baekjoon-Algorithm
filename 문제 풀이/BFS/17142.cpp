/*
작성자 : 이광민
일시 : 2021.06.10
제목 : 17142 - 연구소 3
풀이 : 연구소 2(17141) 문제에서 특정 조건이 하나 더 생기는 문제이다.
       (연구소 2 문제를 풀어보았다면 간단하게 해결할 수 있는 문제)

	   비활성화 바이러스가 활성화 바이러스를 만나게 되면 활성화 바이러스가 되는 조건이 추가되는데
	   이 조건은 다음과 같이 처리된다.
	   - 이미 있었던 바이러스가 활성화되는 것이기 때문에 활성화 될 경우 퍼지는 시간이 추가되는것이 아닌 그냥 말 그대로 활성화 즉, 시간이 걸리지 않는다.

	   이를 다시 해결적 측면에서 말하자면
	   비활성화 바이러스가 있던 곳은 활성화 된다고 해서 활성화된 시간이 해당 위치에서 최대 시간일 경우 해당 시간이 최대가 되지 않는다.
	   (정답에 영향을 끼치지 않는다)

	   그렇기 때문에 연구소 2 문제에서 
	   미리 바이러스가 있었고, 해당 좌표까지 바이러스가 퍼지는 시간이 0이 아니라면 정답 처리에 포함시키지 않는다.(처음 퍼트리는 바이러스들의 좌표 시간은 모두 0으로 초기화 하기 때문)

	   이를 통해 해결이  가능하다.

	   브루트포스 + BFS를 합친 문제이다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 987654321;
int n, m;
int arr[51][51];
vector<pair<int, int>> virus;

bool select_chk[11];
pair<int, int> select_virus[11];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	bool chk[51][51];
	int dist[51][51];
	for(int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
			dist[i][j] = -1;
		}

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push({ select_virus[i].first, select_virus[i].second });
		chk[select_virus[i].first][select_virus[i].second] = true;
		dist[select_virus[i].first][select_virus[i].second] = 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny] || arr[nx][ny] == 1) continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	int cur_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2 && dist[i][j] != 0) continue;
			if (arr[i][j] != 1 && dist[i][j] == -1) return;
			cur_ans = max(cur_ans, dist[i][j]);
		}
	}
	ans = min(ans, cur_ans);
}

void select_virus_xy(int nxt, int cnt) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = nxt; i < virus.size(); i++) {
		if (select_chk[i]) continue;
		select_chk[i] = true;
		select_virus[cnt] = virus[i];
		select_virus_xy(i + 1, cnt + 1);
		select_chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}

	select_virus_xy(0, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
}