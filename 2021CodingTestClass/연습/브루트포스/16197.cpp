/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 두 동전 - 16197
풀이 : BFS처럼 보이지만 브루트포스쪽에 더 가깝다.
       문제를 처음 풀 때 강의를 보지 않고 풀다보니
	   습관이라면 습관이라고 할 수 있는 void 형을 선호한다.
	   그렇다보니 종료값을 생각하지 못했는데, 나중에 끝나고 생각해보니
	   
	   눌린 횟수가 10회를 넘어갈 때 그냥 종료해주는게 아니라
	   값을 11로 초기화하여 종료를 해주고 최종 출력에 있어
	   값이 11이라면 -1을 출력해주는 방식을 하면 되는 문제였다.

	   생각해야 하는 부분
	   1. 종료 조건 (t가 10보다 크다면)
	   2. 이동할 때, 이동하는 곳이 벽이라면 이동하지 않도록하는 것
	   3. 최종 출력에 있어 값을 설정하는 것

	   2번이 중요하다. (범위 내에서 움직이고, 벽이라면 이 전의 값을 그대로 유지 = 움직이지 않음)
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char>> con;
vector<pair<int, int>> coin;
int n, m;


int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int go(int t, int fx, int fy, int sx, int sy) {
	if (t > 10) {
		return -1;
	}

	int cnt = 0;
	if (fx < 0 || fx >= n || fy < 0 || fy >= m) cnt++;
	if (sx < 0 || sx >= n || sy < 0 || sy >= m) cnt++;
	if (cnt == 1) {
		return t;
	}
	else if (cnt == 2) return -1;
	int ans = -1;

	for (int i = 0; i < 4; i++) {
		int nfx = fx + dx[i];
		int nfy = fy + dy[i];

		int nsx = sx + dx[i];
		int nsy = sy + dy[i];

		if (nfx >= 0 && nfx < n && nfy >= 0 && nfy < m && con[nfx][nfy] == '#') {
			nfx = fx;
			nfy = fy;
		}
		if (nsx >= 0 && nsx < n && nsy >= 0 && nsy < m && con[nsx][nsy] == '#') {
			nsx = sx;
			nsy = sy;
		}
		int tmp = go(t + 1, nfx, nfy, nsx, nsy);
		if (tmp == -1) continue;
		if (ans == -1 || ans > tmp) ans = tmp;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<char> tmp;
		for (int j = 0; j < s.length(); j++) {
			tmp.push_back(s[j]);
			if (s[j] == 'o') {
				coin.push_back({ i, j });
			}
		}
		con.push_back(tmp);
	}

	cout << go(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
}