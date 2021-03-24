/*
작성자 : 이상수
일시 : 2021.03.24
제목 : Two Dots - 16929
풀이 : 사이클의 유무를 찾는 문제이다.
       DFS를 사용하여 주어진 행렬 그래프에서 상하좌우로 이동하며 
	   사이클이 존재하는지 찾으면 된다.

	   사용 가능한 방법은 2가지가 있다.
	   1. dfs함수에 cnt 값을 주어 재방문시의 cnt 저장 값과 현재 cnt 값의 차이가
		  얼마나 나는지 확인하여 3이상이라면 사이클이 존재한다고 본다.
	   2. 현재 정점의 좌표를 다음 탐색으로 넘겨주어 이전 방문값은 다시 보지 않도록하고
		  이 때, 이미 방문한 정점을 재방문한다면 이는 사이클이 존재한다는 뜻이다.
       
	   이 2가지 방법 중 2번째 방법을 사용하였고 구현은 아래와 같다.

	   ******
	   만약 dfs함수를 bool 함수로 구현하고 싶다면 (ans 변수를 쓰지 않는다고하면)
	   return dfs( ... ) 가 아니라
	   if(dfs( ... )) return true; 와 같은 방식으로 사용해야한다.
	   (곧바로 return 할 경우 정상적으로 출력이 되지 않았다)
*/
#include<iostream>
#include<string>

using namespace std;

int n, m;
char arr[51][51];
bool chk[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool ans = false;

void dfs(int px, int py, int x, int y) {
	if (ans) return;
	chk[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (px == nx && py == ny) continue;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (arr[nx][ny] != arr[x][y]) continue;
		if (chk[nx][ny]) {
			ans = true;
			return;
		}
		dfs(x, y, nx, ny);
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
			dfs(-1, -1, i, j);
			if (ans) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}