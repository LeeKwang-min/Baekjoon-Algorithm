/*
작성자 : 이상수
일시 : 2021.03.19
제목 : 영역 구하기 - 2583
풀이 : BFS 문제에서 좌표 개념이 아닌 공간 개념으로 나올 때 이 공간을 다시
       좌표의 개념으로 바꿀 수 있는지 확인 하는 문제
	   주어진 공간을 좌표로 생각한다는 것은 
	   주어지는 사각형의 좌표들을 x, y, nx, ny 라고 둘 때
	   x ~ nx - 1 까지
	   y ~ ny - 1 까지 가 해당 공간이 되고
	   이 공간들을 1로 만들어 주고 1이 아닌 공간의 크기와 개수를 가져오면 된다.
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k;
int arr[101][101];
bool chk[101][101];
vector<int> ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n >> k;
	while (k--) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int i = x; i < nx; i++) {
			for (int j = y; j < ny; j++) {
				arr[i][j] = 1;
			}
		}
	}

	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !chk[i][j]) {
				int cnt = 0;
				chk[i][j] = true;
				q.push({ i, j });
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					cnt++;
					int x = cur.first, y = cur.second;
					for (int ck = 0; ck < 4; ck++) {
						int nx = x + dx[ck];
						int ny = y + dy[ck];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (chk[nx][ny] || arr[nx][ny] != 0) continue;
						chk[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	
}