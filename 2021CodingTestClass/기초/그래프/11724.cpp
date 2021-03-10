/*
작성자 : 이상수
일시 : 2021.03.01
제목 : 연결 요소의 개수 - 11724
풀이 : 모든 정점을 시작점으로 하여 dfs나 bfs를 돌기 시작하면
       방문한적이 없는 시작점에 대해서만 탐색을 시작하면
	   그 횟수가 정해진다.

	   이를 통해 처리하면 되는 간단한 문제이다.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> g[1001];
bool chk[1001];
queue<int> q;

void dfs(int x) {
	chk[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!chk[y]) dfs(y);
	}
}

void bfs(int x) {
	chk[x] = true;
	q.push(x);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < g[y].size(); i++) {
			int cur = g[y][i];
			if (!chk[cur]) {
				chk[cur] = true;
				q.push(cur);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		dfs(i);
		ans++;
	}

	cout << ans;
}