/*
작성자 : 이상수
일시 : 2021.03.22
제목 : 빙산 - 2573
풀이 : BFS를 활용하여 얼음의 감소와 그룹의 수를 구현하는 함수를 사용하여 풀면 되는 문제이다.
       
	   얼음 감소 -> 현재 빙산을 기준으로 상, 하, 좌, 우에 몇개의 바다가 있는지 확인하여
	   해당 개수를 새로운 배열 혹은 벡터에 저장하여 마지막에 감소시킨다.
	   (안그러면 현재의 효과가 현재의 다른 빙산에 영향을 끼치게 된다)

	   그룹 수 -> bfs를 돌면서 몇번의 큐 탐색이 진행되었는가 확인한다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int arr[301][301];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int bfs() {
	bool chk[301][301];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			chk[i][j] = false;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0 && chk[i][j] == false) {
				cnt++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				chk[i][j] = false;
				
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					int x = cur.first, y = cur.second;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (chk[nx][ny] || arr[nx][ny] <= 0) continue;
						q.push({ nx, ny });
						chk[nx][ny] = true;
					}
				}
			}
		}
	}
	return cnt;
}

void decrease() {
	vector<vector<int>> tmp;
	for (int i = 0; i < n; i++) {
		vector<int> dec;
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (arr[nx][ny] <= 0) cnt++;
			}
			dec.push_back(cnt);
		}
		tmp.push_back(dec);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] -= tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; ; i++) {
		int res = bfs();
		if (res >= 2) {
			cout << i;
			break;
		}
		else if (res == 0) {
			cout << 0;
			break;
		}
		decrease();
	}
}