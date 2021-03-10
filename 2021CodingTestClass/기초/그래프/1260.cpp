/*
작성자 : 이상수
일시 : 2021.03.01
제목 : DFS와 BFS - 1260
풀이 : DFS와 BFS를 기본적으로 구현하는 문제이다.
       주석으로 처리한 함수들은 "인접행렬"을 이용한 풀이이며
	   주석이 아닌 본 코드는 "인접리스트"를 이용한 풀이이다.

	   BFS를 방문한다 = 함수를 호출한다 = 함수를 시작할 때 chk 값 변경
	   DFS를 방문한다 = 큐에 넣는다 = 큐에 넣을 때 chk 값 변경

	   DFS에 대해 잘 모르는 것을 여기서 잘 알아갈 필요가 있다.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, v;
vector<int> g[1001];
queue<int> q;
bool chk[1001];

void dfs(int x) {
	chk[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!chk[y]) {
			cout << y << ' ';
			dfs(y);
		}
	}
}

/*
void dfs(int x){
	chk[x] = true;
	for(int i = 1; i<=n; i++){
		if(a[x][i] == 1 && !chk[i]){
			dfs(i);
		}
	}
}
*/

void bfs(int x) {
	chk[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			if (!chk[y]) {
				cout << y << ' ';
				q.push(y);
				chk[y] = true;
			}
		}
	}
}

/*
void bfs(int x){
	chk[x] = true;
	q.push(x);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 1; i<=n; i++){
			if(a[now][i] == 1 && chk[i] == false){
				chk[i] = true;
				q.push(i);
			}
		}
	}
}
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	cout << v << ' ';
	dfs(v);
	cout << '\n';
	for (int i = 0; i < n + 1; i++)
		chk[i] = false;
	cout << v << ' ';
	bfs(v);
}