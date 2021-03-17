/*
작성자 : 이상수
일시 : 2021.03.17
제목 : 소문난 칠공주 - 1941
풀이 : 여러가지를 합쳐서 풀어야 하는 백트래킹 문제이다.
       총 25명의 자리에서 7명을 뽑아서 처리하는 문제인데,
	   7명의 자리가 어떻게 구성이 되어있을지 아무도 모른다.
	   그렇기 때문에 일반적인 DFS나 BFS로 풀기는 힘들고
	   조합을 이용하여 0 ~ 24의 값 중 7개를 뽑아서 그 수를 n이라고 할 때
	   arr[n / 5][n % 5] 를 통해 해당 값에 접근하도록 한다.

	   이렇게 뽑은 값들을 BFS를 통해 서로 인접한 자리에 있는지 확인하고
	   인접한 자리에 위치한다면 이 값들에 'S'의 개수가 4개 이상인지
	   확인한 다음 정답을 증가시키면 된다.

	   1. 25명 중에서 7명 뽑기
	   2. 뽑은 7명이 서로 인접한지 확인
	   3. 뽑은 7명 중 4명 이상이 'S'인지 확인

	   모두 만족시 정답 증가.

	   3번 확인하여 만족시 2번 확인하는 방식이 
	   2번 확인하여 만족시 3번 확인하는 방식보다
	   컴퓨터에서는 빠르고 백준에서는 느리다
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int ans = 0;
char arr[5][5];
char brr[7];
vector<pair<int, int>> xy;
bool chk[5][5];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check() {
	int zerone[5][5];
	bool chhk[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			zerone[i][j] = 0;
			chhk[i][j] = false;
		}


	for (int i = 0; i < 7; i++)
		zerone[xy[i].first][xy[i].second] = 1;

	queue<pair<int, int>> q;
	q.push({ xy[0].first, xy[0].second });
	chhk[xy[0].first][xy[0].second] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (chhk[nx][ny] || zerone[nx][ny] != 1) continue;
			q.push({ nx, ny });
			chhk[nx][ny] = true;
		}
	}

	for (int i = 0; i < 7; i++)
		if (chhk[xy[i].first][xy[i].second] == false) return false;

	return true;
}

void go(int st, int cnt) {
	if (cnt == 7) {
		if (!check()) return;
		int count = 0;
		for (int i = 0; i < 7; i++)
			if (brr[i] == 'S') count++;
		if (count >= 4) ans++;
		return;
	}

	for (int i = st; i < 25; i++) {
		int x = i / 5;
		int y = i % 5;
		brr[cnt] = arr[x][y];
		xy.push_back({ x, y });
		go(i + 1, cnt + 1);
		xy.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j++)
			arr[i][j] = s[j];
	}

	go(0, 0);

	cout << ans;
}