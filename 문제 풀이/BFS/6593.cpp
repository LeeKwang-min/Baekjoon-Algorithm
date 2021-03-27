/*
작성자 : 이상수
일시 : 2021.03.27
제목 : 상범 빌딩 - 6593
풀이 : 2차원에서 진행하던 BFS 탐색을 3차원에서 수행하는 문제이다.
       [z][x][y]로 두고 이동을 한다고 가정하였을 때
	   z는 2가지
	   x는 2가지
	   y는 2가지로 총 6가지의 이동이 가능하다.
	   이 이동들을 조합하여 이동 배열을 만들어주고
	   평소와 같이 BFS 탐색을 진행하면된다.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int l, r, c;
char arr[31][31][31];
int chk[31][31][31];

int dz[] = { 0, 0, 0, 0, -1, 1 };
int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					arr[i][j][k] = ' ';
					chk[i][j][k] = 0;
				}
			}
		}

		queue<pair<int, pair<int, int>>> q;
		pair<int, pair<int, int>> ep;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				string s;
				cin >> s;
				for (int k = 0; k < c; k++) {
					arr[i][j][k] = s[k];
					if (s[k] == 'S') {
						q.push({ i, {j, k} });
						chk[i][j][k] = 1;
					}
					if (s[k] == 'E') ep = { i, {j, k} };
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int z = cur.first, x = cur.second.first, y = cur.second.second;
			for (int k = 0; k < 6; k++) {
				int nz = z + dz[k];
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nz < 0 || nz >= l) continue;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (chk[nz][nx][ny] || arr[nz][nx][ny] == '#') continue;
				q.push({ nz, {nx, ny} });
				chk[nz][nx][ny] = chk[z][x][y] + 1;
			}
		}
		
		if (chk[ep.first][ep.second.first][ep.second.second] == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << chk[ep.first][ep.second.first][ep.second.second] - 1 << " minute(s).\n";
	}
}