/*
작성자 : 이상수
일시 : 2021.03.16
제목 : 적록색약 - 10026
풀이 : BFS를 이용하여 그룹의 수를 구하는 문제인데,
       총 2번의 탐색을 진행해야 한다. 
	   이 때 한번은 일반적인 BFS를 수행하면 되고
	   다른 한번은 탐색 조건을 달리하여 수행하여야 한다.

	   적록 색맹이기 때문에
	   R, G, B 값 중에서
	   R, G는 같은 색으로 보게 된다.
	   이 말은 다르게 말하자면 둘 중 하나가 B일때 다른 하나가 B가 아니라면 
	   서로 다른 그룹이 된다는 말이다.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool chk[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	char arr[101][101];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}

	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) continue;
			q.push({ i, j });
			chk[i][j] = true;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				int x = cur.first, y = cur.second;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (chk[nx][ny] || arr[x][y] != arr[nx][ny]) continue;
					q.push({ nx, ny });
					chk[nx][ny] = true;
				}
			}

			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) continue;
			q.push({ i, j });
			chk[i][j] = true;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				int x = cur.first, y = cur.second;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (chk[nx][ny]) continue;
					if ((arr[x][y] == 'B' && arr[nx][ny] != 'B') || (arr[x][y] != 'B' && arr[nx][ny] == 'B')) continue;
					q.push({ nx, ny });
					chk[nx][ny] = true;
				}
			}

			cnt2++;
		}
	}

	cout << cnt << ' ' << cnt2;
}