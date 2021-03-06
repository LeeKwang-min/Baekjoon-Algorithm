/*
작성자 : 이상수
일시 : 2021.03.06
제목 : 로봇 청소기 - 14503
풀이 : 구현문제
       구현 문제는 대부분 의도만 파악하면 간단하게 처리가 가능하다.
	   의도를 파악하는데 한	번 꼬이면 계속 해매게 되고 그에따라 시간이 오래걸린다.

	   이 문제는 각 경우에대해 우선순위만 잘 따져서 처리하면 풀이가 가능한 문제이다.

	   c->d->a->b 순서로 처리하면 된다.
	   리팩토링하면 좀 더 깔끔한 코드가 될것 같기도하다.
*/
#include<iostream>

using namespace std;

int n, m, r, c, d;
int arr[51][51];
bool chk[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int x = r, y = c;
	int ans = 0;
	while (1) {
		// 1번
		if (!chk[x][y]) {
			chk[x][y] = true;
			ans++;
		}

		// 2번

		// c, d. 4방향 청소 여부와 벽 여부 확인
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int nxx = x + dx[k];
			int nyy = y + dy[k];
			if (nxx < 0 || nxx >= n || nyy < 0 || nyy >= m) continue;
			if (arr[nxx][nyy] == 1 || chk[nxx][nyy]) cnt++;
		}

		// 4방향 모두 벽이거나 청소를 했다
		if (cnt == 4) {
			// 후진할 경우 좌표
			int nxx, nyy;
			if (d == 0) {
				nxx = x + dx[2];
				nyy = y + dy[2];
			}
			else if (d == 1) {
				nxx = x + dx[3];
				nyy = y + dy[3];
			}
			else if (d == 2) {
				nxx = x + dx[0];
				nyy = y + dy[0];
			}
			else {
				nxx = x + dx[1];
				nyy = y + dy[1];
			}

			// 후진 가능 여부 확인
			// 후진 불가 (벽이면)
			if (arr[nxx][nyy] == 1) break;
			else {
				x = nxx;
				y = nyy;
				continue;
			}
		}


		//왼쪽 회전
		if (d == 0) d = 3;
		else d -= 1;

		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		// a. 왼쪽에 청소하지 않은곳이 있고 갈 수 있다면
		if (!chk[nx][ny] && arr[nx][ny] == 0) {
			x = nx;
			y = ny;
			continue;
		}
		// b. 왼쪽에 청소할 공간이 없다면 = 이미 청소 했거나 벽이라면
		else {
			continue;
		}
	}

	cout << ans;
}