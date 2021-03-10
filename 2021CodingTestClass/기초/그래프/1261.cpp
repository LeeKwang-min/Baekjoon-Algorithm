/*
작성자 : 이상수
일시 : 2021.03.04
제목 : 알고스팟 - 1261
풀이 : 벽을 부쉈느냐 부수지 않았느냐를 가지고 처리하면 되는 문제이다.
       다시 말해

	   빈방 -> 벽   = 가중치 1
	   빈방 -> 빈방 = 가중치 0 
	   으로 잡고 처리하면 된다. 
	   즉, 다음으로 가는 방이
	   벽이라면 가중치가 1 증가
	   빈방이라면 가중치가 0 증가 가 된다.

	   문제에서 "벽을 부수는 횟수" 라고 표현을 하기 때문에
	   가중치는 벽을 부순 횟수가 된다.

	   가중치가 0이라면 덱의 앞에 넣어주고
	   가중치가 1이라면 덱의 뒤에 넣어주어 BFS를 처리하면 된다.

	   그래프 탐색 문제에서 가장 중요한 것이
	   "무엇을 가중치로 두는가" 와 "어떤 값을 늘려가며 탐색해야 하는가" 이다.

	   이 두가지를 유의하며 값을 처리해야 한다.
*/
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int n, m;
int arr[101][101];
bool chk[101][101];
int brk[101][101];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	dq.push_back({ 0,0 });
	chk[0][0] = true;
	while (!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny]) continue;

			if (arr[nx][ny] == 1) {
				dq.push_back({ nx, ny });
				chk[nx][ny] = true;
				brk[nx][ny] = brk[x][y] + 1;
			}
			else {
				dq.push_front({ nx, ny });
				chk[nx][ny] = true;
				brk[nx][ny] = brk[x][y];
			}
		}
	}
	cout << brk[n - 1][m - 1];
}