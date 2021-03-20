#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chk[i][j] = false;
			dist[i][j] = 0;
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	int ans = -1;
	q.push({ 0, 0 });
	chk[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] != 0) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}

	if (dist[n - 1][m - 1] != 0) ans = dist[n - 1][m - 1];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	int ans;
	ans = bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				setup();

				arr[i][j] = 0;
				int tmp = bfs();
				if (ans == -1) ans = tmp;
				else {
					if(tmp != -1) ans = min(ans, tmp);
				}
				arr[i][j] = 1;
			}
		}
	}

	cout << ans;
}



/*
1. BFS를 통해서 쉽게 해결할 수 있는 문제이다. 먼저 본인은 Queue에서 4가지 변수를 관리해주었다.

  { {x, y}, {벽 부순 횟수, 현재 칸수} } 이렇게 총 4가지 변수들에 대해서 관리해주었다.



2. 일반적인 BFS를 실행시키되, 벽을 부쉈는지 안부쉈는지에 대해서만 따로 확인을 해주면 되기 때문에

   탐색한 정점을 나타내는 Visit함수를 3차원 배열을 이용해서 나타내었다.

   Visit[x][y][벽을부순횟수] 이렇게 표현하였다.

   이미 방문한 정점이더라도, 벽을 부수고 왔는지, 벽을 부수지 않고 왔는지는 서로 다른 경로가 되기 때문에 저렇게 표현

   하였다.



3. BFS안에서 이동할 다음칸에 대해서도 조건을 하나 더 생각해 주어야 한다.

  1. 만약 이동하려는 다음 칸이 벽이고, 이미 벽을 한번 부셨다면?

	 → 더이상 진행할 수 없다. 따라서 Queue에 넣어주지 않는다.

  2. 만약 이동하려는 다음 칸이 벽이고, 벽을 아직 부수지 않았다면?

	 → 벽을 부쉈다는 표시를 해주고, Queue에 넣어서 다음 단계를 진행한다.

  3. 만약 이동하려는 다음 칸이 빈 칸이고, 벽을 한번 부수고 방문한다면?

	 → 벽을 한번 부수고 방문한 정점인지 확인해주고, 아니라면 Queue에 넣어서 다음 단계를 진행한다.

  4. 만약 이동하려는 다음 칸이 빈 칸이고, 벽을 부수지 않고 방문한다면?

	 → 벽을 부수지 않고 방문한 정점인지 확인해주고, 아니라면 Queue에 넣어서 다음 단계를 진행한다.



  생각해야될 게 4가지나 되는 것 처럼 보이지만, 실제로 구현해보면 그렇지 않다.

  정확한 내용은 코드를 참고하자.



출처: https://yabmoons.tistory.com/73 [얍문's Coding World..]
*/