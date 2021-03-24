/*
작성자 : 이상수
일시 : 2021.03.24
제목 : 순열 사이클 - 10451
풀이 : DFS를 사용하여 사이클의 개수를 구하는 문제
       주어지는 입력은 모두 순열에 존재하는 순열 사이클이며
	   이 때문에 사이클이 아닌 값을 주어지지 않으므로 따로 고려할 필요 없이
	   방문시에 이미 방문한 노드를 재방문 하는지만 확인 해주면 된다.

	   총 dfs 탐색 횟수를 계산해주면 된다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[1001];
bool chk[1001];

void dfs(int x) {
	if (chk[x]) return;

	chk[x] = true;
	dfs(arr[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			chk[i] = false;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i]) continue;
			cnt++;
			dfs(i);
		}

		cout << cnt << '\n';
	}
}