/*
작성자 : 이상수
일시 : 2021.04.29
제목 : 연구소 - 14502
풀이 : BFS와 완전탐색이 합쳐진 문제
       BFS 부분은 간단했다. 그저 빈칸으로 퍼져나가는 것을 모두 퍼져나갈때 까지 놔두고 나서
	   모든 퍼짐이 끝났을 때 빈칸(0)을 계산하여 리턴해주면 되었다.

	   완전탐색의 경우 최대 벽을 3개까지 세울 수 있기 때문에
	   최대 크기가 8 X 8의 크기이므로 모든 경우의 수를 처리 해보아도 되는 문제였다.
	   즉 모든 빈칸에 대해 벽을 놓아가며 확인해주면 된다.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int arr[9][9];
bool chk[9][9];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(int k[][9]) {
	queue<pair<int, int>> q;
	int a[9][9];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			a[i][j] = k[i][j];
			chk[i][j] = false;
		}
			

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 2) {
				q.push({ i, j });
				chk[i][j] = true;
			}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == 1 || chk[nx][ny]) continue;
			a[nx][ny] = 2;
			chk[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
				cnt++;

	return cnt;
}

void show(int a[][9]) {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int total = n * m;
	int ans = 0;
	for (int i = 0; i < total; i++) {
		if (arr[i / m][i % m] == 1 || arr[i / m][i % m] == 2) continue;
		for (int j = i + 1; j < total; j++) {
			if (arr[j / m][j % m] == 1 || arr[j / m][j % m] == 2) continue;
			for (int k = j + 1; k < total; k++) {
				if (arr[k / m][k % m] == 1 || arr[k / m][k % m] == 2) continue;
				arr[i / m][i % m] = 1;
				arr[j / m][j % m] = 1;
				arr[k / m][k % m] = 1;
				int tmp = bfs(arr);
				if (ans < tmp) ans = tmp;
				arr[i / m][i % m] = 0;
				arr[j / m][j % m] = 0;
				arr[k / m][k % m] = 0;
			}
		}
	}
	cout << ans;
}

