/*
작성자 : 이광민
일시 : 2021.06.10
제목 : 17141 - 연구소 2
풀이 : BFS문제와 조합을 합친 문제
       단순 BFS나 단순 조합 문제의 경우 정말 간단하게 풀 수 있고 이 문제도 두 알고리즘을 합치면 간단하게 풀 수 있는 문제이지만 해매다가 풀 수 있었다.

	   조합을 구하는 방법은 
	   n과 m 문제들을 다시 한번 풀어보는 것이 필요하고
	   
	   특정 알고리즘과 특정 알고리즘을 합치는 과정이 아직까지 익숙하지 않은데 이에 익숙해져야 할 것 같다.

	   총 n개의 바이러스에서 m개를 골라서 처리할 때 이 과정에서 조합이 선택된다.
	   (조합인 이유 : 순열의 경우 순서만 다른 똑같은 수열이 사용되는데 이 문제에서는 순열은 똑같은 결과를 놓기 때문에 필요가 없다)
	   (그렇기 때문에 조합을 구하는 select_virus 함수 선언 후 사용)
	   
	   m개의 바이러스를 선택하고 그 바이러스로 bfs를 진행하여준다.
	   bfs 탐색을 마친 다음
	   '벽이 아니면서 탐색을 하지 못한 곳' 즉, 바이러스가 퍼지지 못한곳이 있다면 정답 비교를 하지 않는다.

	   이 과정을 진행하며 최종 결과를 도출하면 된다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> virus;

bool selected[11];
pair<int, int> select_xy[11];

int dx[] = { -1, 0, 1 ,0 };
int dy[] = { 0, 1, 0, -1 };

int ans = 987654321;

void bfs() {
	queue<pair<int, int>> q;
	bool chk[51][51];
	int dist[51][51];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
			dist[i][j] = -1;
		}
	
	for (int i = 0; i < m; i++) {
		q.push({ select_xy[i].first, select_xy[i].second });
		chk[select_xy[i].first][select_xy[i].second] = true;
		dist[select_xy[i].first][select_xy[i].second] = 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 1 || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	int cur_ans = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 1 && dist[i][j] == -1) {
				flag = true;
				break;
			}
			cur_ans = max(cur_ans, dist[i][j]);
		}
		if (flag) break;
	}
	if(!flag) 
	ans = min(ans, cur_ans);
}

void select_virus(int nxt, int cnt) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = nxt; i < virus.size(); i++) {
		if (selected[i]) continue;
		selected[i] = true;
		select_xy[cnt] = virus[i];
		select_virus(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
			
	select_virus(0, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
}