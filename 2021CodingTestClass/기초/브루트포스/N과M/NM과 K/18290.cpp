/*
작성자 : 이상수
일시 : 2021.02.18
제목 : NM과 K (1) - 18290
풀이 : N과 M 문제가 1차원에서 개수를 정해서 뽑아내는 문제였다면
       이 문제는 2차원에서 개수를 뽑아내어 푸는 문제이다.

	   처음 접근했던 방식은 현재 처리한 좌표를 다음으로 넘겨서 인접한지 아닌지 
	   확인하는 방식을 썻는데, 이렇게 하면 쓰레기값의 문제나
	   가장 처음 넘겨주는 값을 무엇으로 줘야 하는지가 문제였다.

	   이 때문에 바꿔서 생각한 방식이
	   현재 처리하고자 하는 좌표의 인접한 칸에 이미 방문했는지 안했는지 확인하여
	   방문했다면 건너뛰는 방식을 사용하였다.

	   주의할점은 다음과 같다.
	   nx와 ny의 범위를 설정할 때 유의하여야 하며 (0 <= / > n)
	   가장 처음 최소값을 설정할 때 음수값을 가지는 곳도 있기 때문에 
	   충분히 작은 값을 주어야 한다는 점 
	   이 두가지를 유의 해야 한다. 
	   (가장 위에 적은 접근 방식도 중요)
	   go 함수에 대한 설명
*/
#include<iostream>

using namespace std;

int n, m, k;
int ans = -2147483647;
int point[11][11];
bool chk[11][11];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void go(int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			bool con = true;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (chk[nx][ny]) con = false;
				}
			}
			if (con) {
				chk[i][j] = true;
				go(sel + 1, sum + point[i][j]);
				chk[i][j] = false;
			}
		}
	}
}
/*
	go 함수는 중복된 좌표를 여러번 검사하기 때문에
	시간 복잡도를 계산해보면 약 1억이 나와 겨우 시간에 통과하게 된다.

	이를 방지하기 위해 사용되는 방식이
	go_fast 함수와 같다.

	px와 py는 이전에 선택한 값의 좌표를 넘겨주는 것이며
	이 값을 가져와서 새로 선택할 좌표의 범위를 줄여주는 방식이다.

	i좌표를 px부터 시작하는 이유는 간단하지만,
	j좌표를 i값에 따라 다르게 하는 이유는 다음과 같다.
		i == px -> 이미 검사한 행이기 때문에 px 다음부터 검사한다.
			(이전에 선택한 행과 같은 행인 경우)
		i != px -> 검사하지 못한 행이기 때문에 처음부터 검사한다.
			(이전에 선택한 행과 다른 행인 경우)
	이렇게 값을 검사하며 중복된 검사를 피한다.
*/
void go_fast(int px, int py, int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = px; i < n; i++) {
		for (int j = (i == px ? py : 0); j < m; j++) {
			if (chk[i][j]) continue;
			bool con = true;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (chk[nx][ny]) con = false;
				}
			}
			if (con) {
				chk[i][j] = true;
				go_fast(i, j, sel + 1, sum + point[i][j]);
				chk[i][j] = false;
			}
		}
	}
}
/*
	go_1d의 경우
	2차원배열에 있는 값을 1차원 배열로 보고 처리하는 방식이다.

	N * M 크기의 배열은 다음과 같이 1차원으로 처리가 가능하다.
	
	[r][c] = [r*c]
	(r, c) = r * m + c

	즉 2차원 배열을 1차원으로 붙여둔것과 동일하다.

	반복문의 최종 반복 횟수는 같지만, go_fast와 같이 오름차순을 유지하며
	처리하면 더 빠르기 때문에 
	오름차순 유지를 위해 prev 값을 넘겨준다.
	prev = 이전 선택 좌표
*/
void go_1d(int prev, int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int j = prev + 1; j < n*m; j++) {
		int x = j / m;
		int y = j % m;
		if (chk[x][y]) continue;
		bool con = true;
		for (int t = 0; t < 4; t++) {
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (chk[nx][ny]) con = false;
			}
		}
		if (con) {
			chk[x][y] = true;
			go_1d(x*m + y, sel + 1, sum + point[x][y]);
			chk[x][y] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> point[i][j];
		}
	}
	go(0, 0);
	go_fast(0, 0, 0, 0);
	go_1d(-1, 0, 0);
	cout << ans;
}