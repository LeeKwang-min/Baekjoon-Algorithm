#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n;
int arr[26][26];
bool chk[26][26];
queue<pair<int, int>> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	chk[x][y] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; i < s.length(); j++) 
			arr[i][j] = s[j] - '0';
	}

	int ans = 0;
	vector<int> sz;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) continue;
			if (arr[i][j] == 1) {
				ans++;
				int cnt = bfs({ i, j });
				sz.push_back(cnt);
			}
		}
	}
}