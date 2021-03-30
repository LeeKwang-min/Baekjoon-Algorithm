/*
작성자 : 이상수
일시 : 2021.03.30
제목 : 불켜기 - 11967
풀이 : 큐를 사용하고 BFS를 사용하여 풀이한 문제
       문제를 알고리즘적으로 풀어서 말로 설명하면
	   (1) 현재 장소에서 불을 킬 수 있는곳의 모든 방에 불을 킨다
	   (2) 이동 가능한 방을 찾아 이동한다
	   (3) 이동한 장소에서 큐가 빌 때까지 (1)과 (2)를 반복한다

	   가 되겠다. 이 과정에서 나는 몇가지 실수로 한번에 AC를 받지 못하였는데
	   그 실수는 다음과 같다.

	   1. 다음 방으로 이동이 가능한가를 확인하는 타이밍
	   2. 새로운 방의 불을 켤 때 갈 수 있는 방이 새롭게 생겼는가.

	   인데, 2번 때문에 1번의 실수가 생겼다고 볼 수 있다.
	   그 이유는 다음과 같다.
	   새로운 장소로 이동하게 될 때 만약 연속된 두 방의 불을 키게 되는데
	   연속된 방에서 뒷쪽의 방을 먼저 키고 중간의 방의 불을 키지 않고
	   이동 가능여부를 확인하게 되면 이동이 불가능하고 문제가 생긴다.

	   위 실수를 고치기 위해 모든 좌표에 대해 이동 가능한 새로운 방이 있나
	   확인을 해보았으나 이 코드는 시간초과를 받게 되었다.

	   마찬가지로 2번의 실수는 위의 실수를 고치기 위해 새롭게 불이 켜지는 모든 방의
	   좌표를 저장하고 해당 방의 좌표만 이동가능한지 확인을 했는데, 여기서 
	   놓친 것이 새롭게 불이 켜지게 되면서
	   기존에 이동하지 못하던 불이 켜져 있던 방과의 이음새 역할을 해주게 되면
	   이동이 가능한 새로운 방이 생기게 되는 것이다.
	   Ex) O X O -> O O O 

	   이런 실수들을 고치기 위해 최종적으로 시행한 방법이
	   하나의 방에서 가능한 모든 스위치를 작동시켜 불을 키고 나면
	   BFS 탐색을 돌면서 기존에 방문하지 않은 방 중 갈 수 있는 모든 방을
	   vector에 담아 반환시키는 것이다.
	   이 벡터를 반복문을 통해 갈 수 있는 곳들을 모두 큐에 넣어 다시 탐색을
	   진행하는 방식을 사용하여 Solve할 수 있었다.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> arr[101][101];
bool on[101][101];
bool chk[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pair<int, int>> canGo() {
	vector<vector<bool>> tmp(n + 1, vector<bool>(n + 1, false));
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	tmp[1][1] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
			if (tmp[nx][ny] || on[nx][ny] == false) continue;
			q.push({ nx, ny });
			tmp[nx][ny] = true;
		}
	}

	vector<pair<int, int>> vv;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 방문한적이 없지만 갈 수 있는 방인경우
			if (tmp[i][j] && chk[i][j] == false) vv.push_back({ i, j });
		}
	}
	
	return vv;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	on[x][y] = true;
	chk[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		// 우선 모든 방의 불을 켜준다.
		for (auto nxt : arr[x][y]) {
			int nx = nxt.first;
			int ny = nxt.second;
			on[nx][ny] = true; 
		}
		
		// 새롭게 갈 수 있는 모든 방의 좌표를 받아와서 큐에 넣는다.
		vector<pair<int, int>> tmp = canGo();
		for (auto nxt : tmp) {
			int nx = nxt.first;
			int ny = nxt.second;
			q.push({ nx, ny });
			chk[nx][ny] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		arr[x][y].push_back({ a, b });
	}

	bfs(1, 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (on[i][j]) cnt++;
		}
	}
	cout << cnt;
}