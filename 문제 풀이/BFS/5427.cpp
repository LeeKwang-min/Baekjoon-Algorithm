/*
작성자 : 이상수
일시 : 2021.03.22
제목 : 불 - 5427
풀이 : BFS를 사용하여 처리하는 문제
       불이 퍼지는 시간과 
	   상근이가 주어진 범위 밖으로 나가는데 걸리는 시간을 구하면 되는데

	   불이 퍼지는 시간을 우선적으로 구하여
	   상근이가 이동하는 시간을 구할 때 BFS 탐색 중 큐에 삽입 조건으로 사용한다.

	   만약 불이 특정 칸으로 퍼지는 시간이 상근이가 해당 칸으로 이동하는데 걸리는 
	   시간보다 적다면 이동하지 못하기 때문에 큐에 넣어 탐색할 필요가 없다.

	   이를 사용하여 처리하며
	   더 적은 시간을 비교해야 하기 때문에 초기값을 -1로 두어
	   비교값이 -1이라면 불이 없다는 뜻이기 때문에 이동이 가능하도록 처리한다.
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		queue<pair<int, int>> fq;
		queue<pair<int, int>> sq;
		vector<vector<char>> mp(n, vector<char>(m, ' '));
		vector<vector<bool>> chk(n, vector<bool>(m, false));
		vector<vector<bool>> schk(n, vector<bool>(m, false));
		vector<vector<int>> fdist(n, vector<int>(m, -1));
		vector<vector<int>> sdist(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				mp[i][j] = s[j];
				if (mp[i][j] == '@') {
					sq.push({ i, j });
					sdist[i][j] = 0;
					schk[i][j] = true;
				}
				if (mp[i][j] == '*') {
					fq.push({ i, j });
					fdist[i][j] = 0;
					chk[i][j] = true;
				}
			}
		}

		while (!fq.empty()) {
			auto cur = fq.front();
			fq.pop();
			int x = cur.first, y = cur.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (chk[nx][ny] || mp[nx][ny] == '#') continue;
				fq.push({ nx, ny });
				chk[nx][ny] = true;
				fdist[nx][ny] = fdist[x][y] + 1;
			}
		}

		int cnt = 0;
		bool cn = false;
		while (!sq.empty()) {
			auto cur = sq.front();
			sq.pop();
			cnt++;
			int x = cur.first, y = cur.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					cn = true;
					cnt = sdist[x][y] + 1;
					break;
				}
				if (schk[nx][ny] || mp[nx][ny] == '#') continue;
				if (sdist[x][y] + 1 >= fdist[nx][ny] && fdist[nx][ny] != -1) continue;
				sq.push({ nx, ny });
				schk[nx][ny] = true;
				sdist[nx][ny] = sdist[x][y] + 1;
			}
			if (cn) break;
		}
		if (cn) cout << cnt << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}

}

