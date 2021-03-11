/*
작성자 : 이상수
일시 : 2021.03.11
제목 : 서울 지하철 2호선 - 16947
풀이 : 그래프에서 정점의 개수와 간선의 개수가 같을 때 사이클이 단 하나 뿐이라고 한다.
       이 때에 그래프에서 각 정점이 사이클에 해당되는지 안되는지를 정해주고
	   이 정보를 바탕으로 BFS를 돌리는 문제이다.

	   1. DFS로 사이클 확인
	   2. BFS로 사이클로 부터의 거리 확인

	   1. int형 DFS 함수를 통해 사이클 여부 확인
	   2. 사이크 = 0 나머지 = BFS를 통해 거리 계산
*/

#include<iostream>
#include<queue>

using namespace std;

vector<int> arr[3001];
int chk[3001];
int dist[3001];
int n;


// chk[0] = 방문 안함	chk[1] = 방문 했음	chk[2] = 방문 했고 사이클임
// go의 결과 => -2 = 사이클을 찾았고 x가 사이클에 포함되지 않는다.
//              -1 = 사이클을 찾지 못했다.
//               1 ~ n = 사이클을 찾았고 사이클의 시작 정점이다.
int cycle(int x, int p) { // p -> x (정점)
	if (chk[x] == 1) return x; // 이미 방문한 정점을 다시 방문했다 = 사이클의 시작점이다 = return
	chk[x] = 1; // x에 방문했다고 알리기
	for (int nxt : arr[x]) { 
		if (nxt == p) continue; // 이전에 방문했던 정점이라면 건너뛰기
		int res = cycle(nxt, x); // 다음 정점으로 갔을 때의 결과 = 사이클에 해당하는지 확인
		if (res == -2) return -2; // -2 = 사이클이 아니다.
		if (res >= 0) { // 양수 = 정점 이라면 사이클이다.
			chk[x] = 2; // 해당 정점은 사이클이고
			if (x == res) return -2; // 현재 정점이 시작점이라면 그 뒤로는 모두 사이클이 아니다 = -2 리턴
			else return res; // 시작점이 아니라면 시작점을 리턴
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	cycle(1, 0);

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nxt : arr[x]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[x] + 1;
			q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}