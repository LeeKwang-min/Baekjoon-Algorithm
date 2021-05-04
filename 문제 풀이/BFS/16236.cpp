/*
작성자 : 이상수
일시 : 2021.05.04
제목 : 아기 상어 - 16236
풀이 : 유명한 삼성 기출문제
       bfs와 구현을 합쳐둔 문제이다.

	   bfs를 단순 구현할 뿐 아니라 추가적인 조건 추가가 필요하다.

	   1. 먹을 수 있는 물고기가 있는지 확인하는 함수 (find_fish)
	   2. 위치까지 몇초나 걸리는지 확인을 위한 함수 (BFS)
	   3. 현재 상태에서 (0, 0) ~ (N, N)까지 차례대로 확인하며 "먹을 수 있고" "최소 거리"를 가지는 물고기 찾기 (find_food)
	   4. 이동하기

	   위 4단계를 main 함수 안에서 추가적인 함수를 통해 구현하였다.

	   각 탐색을 위해 고려할 것이 몇가지 있다.
	   1. find_fish를 위해 이동이 가능한지 확인하기 위해 먼저 bfs 탐색을 진행 해주어야 한다. ( 물고기 크기 확인, 물고기가 있는지 확인, 이동 가능한지 확인)
	   2. bfs에서 이동이 가능한 것은 "물고기 크기 <= 상어 크기" 인 부분이다.
	   3. find_food에서 고려할 것은 다음과 같다.
	    3-1. 상어보다 크기가 작은 물고기들 찾기
		3-2. 이동 거리가 최소인 물고기 찾기
		 3-2-1. 거리가 같다면 가장 위쪽, 왼쪽인 물고기들 찾기
	   위 과정을 거친 다음 최종 이동할 위치를 넘겨주고 해당 위치로 상어를 이동시키면 된다.

	   추가적으로 상어의 크기를 증가시켜주는 부분도 필요하다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int shark_size;
int arr[21][21];
int dist[21][21];
bool chk[21][21];
int nx, ny;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool find_fish() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (shark_size > arr[i][j] && arr[i][j] != 0 && dist[i][j] != 0) return false;

	return true;
}

void bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			dist[i][j] = 0;
			chk[i][j] = false;
		}

	queue<pair<int, int>> q;
	q.push({ nx, ny });
	chk[nx][ny] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nxtx = x + dx[k];
			int nxty = y + dy[k];
			if (nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= n) continue;
			if (arr[nxtx][nxty] > shark_size || chk[nxtx][nxty]) continue;
			dist[nxtx][nxty] = dist[x][y] + 1;
			q.push({ nxtx, nxty });
			chk[nxtx][nxty] = true;
		}
	}
}

pair<int, int> find_food() {
	pair<int, int> ret = { n, n };
	int min_dist = n * n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (shark_size > arr[i][j] && arr[i][j] != 0 && dist[i][j] != 0) {
				if (min_dist > dist[i][j]) {
					min_dist = dist[i][j];
					ret.first = i;
					ret.second = j;
				}
				else if (min_dist == dist[i][j]) {
					if (ret.first > i && ret.second > j) {
						ret.first = i;
						ret.second = j;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	shark_size = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				nx = i;
				ny = j;
			}
		}
	}

	int sec = 0;
	int grow = 0;
	while(1) {
		bfs();

		if (find_fish()) {
			cout << sec;
			break;
		}

		auto nxt = find_food();
		arr[nx][ny] = 0;
		arr[nxt.first][nxt.second] = 9;
		sec += dist[nxt.first][nxt.second];
		grow++;
		if (grow == shark_size) {
			shark_size++;
			grow = 0;
		}
		nx = nxt.first;
		ny = nxt.second;

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/
	}
}

/*
6

1 2 1 1 1 1

1 3 6 2 2 3

1 2 5 2 2 3

3 3 2 4 6 3

0 0 0 0 0 6

0 0 0 1 1 9
*/