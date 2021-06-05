/*
작성자 : 이광민
일시 : 2021.06.04
제목 : 6087 - 레이저 통신
풀이 : BFS 풀이의 또 다른 방식을 알려준 문제
       (많이 고민했으나 풀지 못해서 풀이를 찾아보고 푼 문제)

	   이 문제는 일반적인 BFS로 풀면 풀지 못한다.
	   BFS는 최단 거리를 찾는데에 최적화된 문제이고 이 문제는 해당 경로로 가는 과정에서 몇번의 방향 변경이 생기는지를 확인하는 문제이기 때문이다.
	   그렇기 때문에 문제 풀이에 변화가 필요하다.
	   (일반적인 BFS에서 값의 변화가 필요하면 추가적으로 탐색을 다시 진행하는 방식이 있다곤 하는데 이 풀이보다 오래 걸린다)

	   이 풀이는 현재 정점에서 '방향 변경 없이'갈 수 있는 모든 정점을 한번에 방문하도록 하는 방식이다.

	   예를들어

	   . . C . .   가 있다면
	   1 1 0 1 1   로 처리가 된다는 뜻이다.

	   dist의 정의는 출발점에서 해당 정점까지 오는데 필요한 직선의 개수가 된다. (직선의 개수 - 1 => 필요한 거울의 갯수)
	   즉, 현재 직선에서 갈 수 있는 끝점 까지(범위가 끝나거나, 벽을 만나거나 하기 전까지) 모두 직선의 개수를 맞춰주도록 하는데
	   여기서 새로운 기술이 나온다.

	   바로 기존에 'if(nx < 0 || nx >= n || ny < 0 || ny >= m)' 을
	   다음과 같이 'while(nx >= 0 && nx < n && ny >= 0 && ny < m)'으로 바꾸어 해당 반복문 안에서
	   nx += dx[k] 
	   ny += dy[k]를 반복해주며
	   벽을 만나면 break시키고 그렇지 않다면 계속해서 증가시켜가며 
	   dist[nx][ny] = dist[x][y] + 1 로 처리 해준다. (위 예제처럼 처리한다)

	   이를 통해 최종 정답은 도착 C가 있는 좌표의 dist에서 -1을 해주면 된다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int w, h;
vector<pair<int, int>> rc;
char arr[101][101];
bool chk[101][101];
int dist[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void show() {
	cout << '\n';
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cout << dist[i][j] << "  ";
		}
		cout << '\n';
	}
}

void init() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			dist[i][j] = 987654321;
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({rc[0].first, rc[0].second});
	dist[rc[0].first][rc[0].second] = 0;
	chk[rc[0].first][rc[0].second] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			while (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (arr[nx][ny] == '*') break;
				if (!chk[nx][ny]) {
					chk[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
				nx += dx[k];
				ny += dy[k];
			}
			/*
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (chk[nx][ny] || arr[nx][ny] == '*') continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
			*/
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w;
	int cnt = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') rc.push_back({ i, j });
		}
	}
	//init();
	bfs();
	//show();
	cout << dist[rc[1].first][rc[1].second] - 1;
}
