/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 테트로미노 - 14500
풀이 : 테트로미노를 구성하는 블럭들은 하나의 블럭을 제외하면 
       한 좌표에서 시작하여 연속되는 3개의 블럭을 방문하는 모양이다.
	   이를 이용하면 DFS와 비슷한 방식으로 풀이가 가능하다.

	   DFS와 다른점은 단 하나 뿐이다. 하나의 블럭에서 해당 블럭을 사용했다고 해서
	   그 블럭을 그만 가도 되는것이 아니라
	   다른 블럭에서 해당 블럭을 사용할수도 있기 때문에
	   이를 관리 해주는 chk 배열을 함수가 종료될 때 다시 false로 바꿔주어야한다.

	   이처럼 현재 값을 가지고 탐색을 진행하면서 
	   가장 큰 값을 찾고

	   ㅁㅁㅁ
	     ㅁ
	   이 모양은 연속된 3가지가 아니기도 하고 재귀로 구현하면 시간이 더 오래 걸리기 때문에
	   이 모양만 따로 예외를 두어 블럭 처리를 하도록 한다.

	   기존 DFS와 다른 점 하나만 생각해주면 된다.

	   (모든 경우 구현보다 시간은 훨 오래 걸린다)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[501][501];
int chk[501][501];

int n, m;
int ans = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void go(int cnt, int cur, int x, int y) {
	if (cnt == 4) {
		ans = max(ans, cur);
		return;
	}

	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (chk[x][y]) return;
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		go(cnt + 1, cur + a[x][y], nx, ny);
	}
	chk[x][y] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(0, 0, i, j);
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}
	cout << ans;
}