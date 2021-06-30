/*
작성자 : 이광민
일시 : 2021.06.04
제목 : 16928 - 뱀과 사다리 게임
풀이 : 1차원 BFS 문제
       사다리와 뱀의 개수는 최대 15개이지만, 이 값들이 어디서 어디로 가는지 벡터에 저장하고 그때 그때 탐색하여 가져오게 되면
	   메모리의 효율성은 높아져도 시간적 효율은 떨어지게 된다. 그렇기 때문에 최대 100개의 칸에 사다리와 뱀이 놓이기 때문에
	   그냥 뱀과 사다리의 정보를 크기 100의 배열 2개에 따로 저장하여 검사한다.
	   검사를 진행하며 사다리나 뱀이 있다면 nx의 값을 바꾸어주도록 한다.

	   그렇게 탐색을 마치고 나서 dist[100]의 값이 정답이 된다.
*/
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int dist[101];
bool chk[101];
int ladder[101];
int snake[101];

int dx[] = { 1, 2, 3, 4, 5, 6 };

void go() {
	queue<int> q;
	q.push(1);
	chk[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			if (nx > 100 || chk[nx]) continue;
			if (ladder[nx] != 0) nx = ladder[nx];
			if (snake[nx] != 0) nx = snake[nx];
			if (nx > 100 || chk[nx]) continue;
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		ladder[from] = to;
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		snake[from] = to;
	}
	go();
	cout << dist[100];
}