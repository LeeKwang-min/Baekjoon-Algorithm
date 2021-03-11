/*
작성자 : 이상수
일시 : 2021.03.11
제목 : Two Dots - 16929
풀이 : DFS를 통해 사이클이 있는지 찾는 문제
       2가지 방법이 있다.

	   첫번째로는 
	   1. DFS 함수의 매개변수로 현재 진행되는 단계의 수 (그래프 시작부터 몇단계 지났는지)
	   2. 방문 했는지 안했는지 여부
	   3. 방문한곳의 시작 정점으로부터의 거리

	   이 3가지를 가지고 현재 정점에서 다음으로 방문하고자 하는 정점이
	   "이미 방문한 정점"이고 "현재 진행 단계" - "해당 정점의 거리" 가
	   4 이상이라면 사이클이 맞기 때문에 정답으로 처리한다.


	   두번째로는
	   1. 이전 정점의 좌표
	   2. 현재 정점의 좌표

	   이 2가지를 가지고 새롭게 방문 가능한 좌표를 이전 정점은 제외하는 방식이다.
	   이 전의 정점을 방문하지 않고 탐색을 진행하게 되면
	   사이클이 생기지 않는 한 이전에 방문했던 정점으로 가지 않는다.

	   이 점을 이용하여 이전 정점의 정보를 가지고 사이클 여부를 판단 가능하다.
*/
#include<iostream>
#include<string>

using namespace std;

int n, m;
bool chk[51][51];
char arr[51][51];
bool ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void go(int px, int py, int x, int y) {
	if (ans) return;
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == px && ny == py) continue;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (arr[x][y] != arr[nx][ny]) continue;
		if (chk[nx][ny]) {
			ans = true;
			return;
		}
		go(x, y, nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			go(-1, -1, i, j);
			if (ans) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}