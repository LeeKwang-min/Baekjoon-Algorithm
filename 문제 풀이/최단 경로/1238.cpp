/*
작성자 : 이상수
일시 : 2021.04.05
제목 : 파티 - 1238
풀이 : 다익스트라 알고리즘을 사용하여 푸는 문제
       각 정점에서 도착점(x)까지 걸리는 값을 구해주고
	   도착점에서 각 정점까지 걸리는 값을 구하여
	   두 값의 합이 최대가 되는 값을 출력 해주면 된다.

	   문제를 풀고나서 생각해보니 첫번째 각 정점에서 도착점까지 걸리는 값을 
	   구할 때에는 플로이드 와샬 알고리즘을 써도 될것 같다...

	   다익스트라 알고리즘의 시간 복잡도는 
	   O(ElogV)이다. (E = 간선의 개수, V = 정점의 개수)
	   이 문제에서 E = 10000   V = 1000 으로
	   최대 1000 * 10000 * 3 이 되기 때문에 시간초과가 나지 않는다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;
int n, m, x;
vector<pair<int, int>> arr[1001];
int distGo[1001];
int distBack[1001];

int dijkstraGo(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int dist[1001];
	fill(dist, dist + n + 1, INF);
	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (dist[idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (dist[nidx] > cost + ncost) {
				dist[nidx] = cost + ncost;
				pq.push({ dist[nidx], nidx });
			}
		}
	}
	return dist[x];
}

void dijkstraBack(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(distBack, distBack + n + 1, INF);
	distBack[st] = 0;
	pq.push({ distBack[st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (distBack[idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (distBack[nidx] > cost + ncost) {
				distBack[nidx] = cost + ncost;
				pq.push({ distBack[nidx], nidx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) {
			distGo[i] = 0;
			continue;
		}
		distGo[i] = dijkstraGo(i);
	}

	dijkstraBack(x);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < distGo[i] + distBack[i])
			ans = distGo[i] + distBack[i];
	}

	cout << ans;
}