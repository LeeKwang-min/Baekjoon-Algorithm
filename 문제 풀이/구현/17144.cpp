/*
작성자 : 이광민
일시 : 2021.06.02
제목 : 17144 - 미세먼지 안녕!
풀이 : 크게 2가지 기능을 구현하면 해결이 가능한 문제이다.

	   기본 조건
	   1. 집의 크기는 R X C 크기이다
	   2. 공기 청정기는 항상 1열에 존재하며 2개의 행을 차지한다
	   3. a 배열은 미세먼지의 양이다.
       구현할 것
	   1. 미세먼지 확산
	      - (r,c)의 인접 4방향으로 확산된다.
		  - 공기 청정기 혹은 벽인 경우 확산되지 않는다.
		  - 확산 되는 양은 a[r][c] / 5 이다 (소수점은 버린다)
		  - 확산이 끝난 다음 a[r][c]의 미세먼지 양은 (a[r][c] / 5) * 확산된 개수 만큼 감소한다.
	   2. 공기 청정기 작동
	      - 공기 청정기의 위쪽의 경우 반시계 방향으로 바람이 분다.
		  - 공기 청정기의 아래쪽의 경우 시계 방향으로 바람이 분다.
		  - 위 아래 모두 바람 방향에 따라 한칸씩 이동한다.
		  - 공기 청정기에서 나오는 바람의 미세먼지 양은 0이며 들어가는 경우도 미세먼지는 0이된다.
	   3. 총 미세먼지의 량

	   이 3가지를 구현하여 T초 동안 반복되도록 설정하면 된다.

	   확산의 경우 각 칸들이 얼마나 값이 증감되는지 구하기 위해 따로 add_dust라는 배열을 두고 모두 확산시킨 다음
	   한번에 그 값을 증감시키도록 한다.

	   공기 청정기의 작동은
	   처음 기계에서 나오는 바람의 미세먼지는 0이다 와
	   마지막 기계로 들어가는 미세먼지는 사라진다는 점을 사용하면 임시 배열을 만들지 않아도 처리가 가능하다.

	   처음 나오는 값을 저장해두고 스왑을 계속 진행하다가 마지막 값을 따로 저장하지 않아도 된다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, t;
int a[51][51];
vector<pair<int, int>> air_cleaner;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void spread() {
	int add_dust[51][51];
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			add_dust[i][j] = 0;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == 0 || a[i][j] == -1) continue;
			int spread_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 1 || nx >= r + 1 || ny < 1 || ny >= c + 1) continue;
				if (a[nx][ny] == -1) continue;
				add_dust[nx][ny] += a[i][j] / 5;
				spread_cnt++;
			}
			add_dust[i][j] -= (a[i][j] / 5) * spread_cnt;
		}
	}

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			a[i][j] += add_dust[i][j];
}

void up_work() {
	int x = air_cleaner[0].first;
	int y = air_cleaner[0].second;
	int prev_dust = 0;
	for (int i = y + 1; i <= c; i++) {
		int nxt_dust = a[x][i];
		a[x][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = x - 1; i >= 1; i--) {
		int nxt_dust = a[i][c];
		a[i][c] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = c - 1; i >= y; i--) {
		int nxt_dust = a[1][i];
		a[1][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = 2; i < x; i++) {
		int nxt_dust = a[i][y];
		a[i][y] = prev_dust;
		prev_dust = nxt_dust;
	}
}

void down_work() {
	int x = air_cleaner[1].first;
	int y = air_cleaner[1].second;
	int prev_dust = 0;
	for (int i = y + 1; i <= c; i++) {
		int nxt_dust = a[x][i];
		a[x][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = x + 1; i <= r; i++) {
		int nxt_dust = a[i][c];
		a[i][c] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = c - 1; i >= y; i--) {
		int nxt_dust = a[r][i];
		a[r][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = r - 1; i > x; i--) {
		int nxt_dust = a[i][y];
		a[i][y] = prev_dust;
		prev_dust = nxt_dust;
	}
}

int total_dust() {
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == -1) continue;
			cnt += a[i][j];
		}
	}
	return cnt;
}

void show_dust() {
	cout << '\n';
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				air_cleaner.push_back({ i, j });
			}
		}
	}

	while (t--) {
		spread();
		up_work();
		down_work();
	}
	int ans = total_dust();
	cout << ans;
}

