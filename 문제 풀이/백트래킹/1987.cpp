/*
작성자 : 이상수
일시 : 2021.04.07
제목 : 알파벳 - 1987
풀이 : BFS로 풀다가 DFS로 바꾸어 푼 문제
       처음에 간단하게 생각하고 모든 경로를 생각하는게 아니라 일반적인
	   길 찾기와 같이 진행하여 갯수를 찾아볼까 하였다.
	   BFS의 경로찾기와 같이 진행하며 값의 최대값을 출력하자
	   문제의 예제는 똑바로 나와서 제출하였으나
	   전체적인 경로를 생각하지 않아 당연히 실패

	   이를 바꾸기 위해 DFS로 백트래킹때와 같이 방문 여부를 참/거짓으로 탐색의
	   전 후에 바꿔주며 진행하였다.

	   추가적으로 2가지의 실수를 더 하였다.
	   1. map의 탐색 속도는 생각보다 느리다
	     일반적인 배열이 O(N)이라면 map의 탐색은 이보다 느리다. 그렇기 때문에
		 이 문제에서는 빠른 진행을 위해 map이 아닌 일반적인 배열을 사용해야한다.
	   2. 1번에서 연계되는 실수인데, 1번을 해결하기 위해 문자열로 주어지는 
	     값들을 " - '0' " 하여 인덱스로 바꾸어 배열에 저장하였고 이를 맵과 같이 사용
		 하지만, 이미 실수가 보이듯이 주어지는 문자들은 'A' - 'Z' 인데 
		 - '0'을 하는 실수를 했다. 이를 바꾸어 - 'A'로 해주었다.

	   이를 사용하여 적당히 경로를 찾고 종료 조건을 주면서 진행해주면 된다.
*/

#include<iostream>
#include<string>

using namespace std;

int n, m;
int ans = 1;
char arr[21][21];
int alp[30];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int cnt, int x, int y) {
	if (ans < cnt) ans = cnt;
	alp[arr[x][y] - 'A']++;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (alp[arr[nx][ny] - 'A'] != 0) continue;
		dfs(cnt + 1, nx, ny);
	}
	alp[arr[x][y] - 'A']--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	dfs(1, 0, 0);

	cout << ans;
}