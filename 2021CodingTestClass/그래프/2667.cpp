/*
작성자 : 이상수
일시 : 2021.03.02
제목 : 단지번호붙이기 - 2667
풀이 : bfs나 dfs를 사용하여 경로찾기와 비슷하다.
       기존에 void형이였던 dfs와 bfs 기본형에서 단지의 크기를 return 해주어야 하기 때문에
	   int형으로 바꿔주어야 한다.
	   처음 탐색을 시작할 때 크기는 1로서 큐에 새로운 장소가 추가될 때마다 값을
	   증가시켜주면 된다.
	   값을 증가시켜주고 탐색이 끝날때 (자신의 주변이 모두 1이 아닐때) 그 값을 return 해준다.

	   이 값들의 증가와 탐색을 모든 노드에 대해 진행하고
	   벡터 정렬을 통해 최종 정답을 출력 해준다.

	   1. 단지 크기를 위한 값
	   2. 단지 개수를 위한 값이 필요하다.

	   dfs로 풀 때 처음 int 함수로 만들어서 return 하도록 할려고 했으나
	   올바른 값이 나오지 않았다.
	   이를 해결하고자 한 방식이 전역변수로 하나를 만들어서 그 값을 증가시켰다.
	   강의에서 처리한 방식은 각 단지에 번호를 매겨서
	   해당 단지 번호를 인덱스로 하는 배열에 갯수를 따로 전부 탐색하며 누적합으로 나타내었다.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int arr[26][26];
bool chk[26][26];
int n;
int cntSz = 0; // dfs일 때

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	queue<pair<int, int>> q;
	q.push({ x,y });
	chk[x][y] = true;

	int cnt = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int nowx = cur.first, nowy = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 0 || chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			cnt++;
		}
	}

	return cnt;
}

void dfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	chk[x][y] = true;
	cntSz++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (chk[nx][ny] || arr[nx][ny] == 0) continue;
		dfs({ nx, ny });
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}

	int cnt = 0;
	vector<int> sz;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && chk[i][j] == false) {
				cnt++;
				//int cntSz = bfs({i,j}); // bfs일 때
				cntSz = 0; // dfs일 때
				dfs({ i,j }); // dfs일 때
				sz.push_back(cntSz);
			}
		}
	}

	cout << cnt << '\n';
	sort(sz.begin(), sz.end());
	for (int i : sz)
		cout << i << '\n';
}