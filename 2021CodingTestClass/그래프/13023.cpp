/*
작성자 : 이상수
일시 : 2021.03.01
제목 : ABCDE - 13023
풀이 : 그래프에 친구 정보를 저장하고 dfs를 통해 깊이가 조건을 충족하는 값이 있을때
       올바른 출력을 해주면 되는 문제이다.

	   여러가지 방법이 있지만, dfs를 사용할 경우
	   백트래킹과 비슷하게 처리된다.

	   하나의 간선에서 시작하여 연결된 다른 간선들로 연결되어 갈 때
	   방문한적이 없는 노드들에 대해 연결을 진행하고 그 값들을 받아와서
	   검사하도록 한다. 정답을 찾았다면
	   answer를 조건으로 사용하여 탐색을 완전 종료하도록 한다. (시간 절약)
	   
	   현재 나는 dfs가 약한것 같다. 유심히 볼 필요가 있다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> g[2001];
bool chk[2001];
bool answer;

void dfs(int x, int len) {
	if (len == 4) { // 친구 관계 성립이 4명이면 완료
		answer = true;
		return;
	}

	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i]; // y = x와 연결된 노드
		// 방문한 적이 없다면 방문하여 탐색
		if (!chk[y]) {
			chk[y] = true;
			dfs(y, len + 1);
			chk[y] = false;
		}
		if (answer) return; // 이미 정답을 찾았다면 탐색 종료
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { // 처음부터 진행하기 위해 모든 방문 정보 리셋
			chk[j] = false;
		}
		chk[i] = true;
		dfs(i, 0); // i번에서 시작하는 dfs 시작
		if (answer == true) break;
	}

	if (answer) cout << 1;
	else cout << 0;
}