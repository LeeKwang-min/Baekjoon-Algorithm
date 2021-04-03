/*
작성자 : 이상수
일시 : 2021.04.03
제목 : 특정한 최단 경로 - 1504
풀이 : 다익스트라 알고리즘을 사용하여 푸는 문제. 
       다익스트라 알고리즘의 개념을 잘 이해하고 있다면 간단하게 해결 가능한 문제이다.

	   다익스트라 알고리즘 : 시작 정점에서 나머지 모든 정점까지의 최단 거리를 구하는 알고리즘
	   이 문제는 v1과 v2가 주어질 때 이 두 점을 꼭 지나면서 N으로 가는 최소 값을 구하는
	   문제이다. 이 문제를 풀어 정의하자면

	   시작 정점은 1번 정점으로 똑같으나
	   v1과 v2를 거쳐서 n번 정점으로 가야 하므로
	   1 -> V1 -> V2 -> N 으로 갈 것인가
	   1 -> V2 -> V1 -> N 으로 갈 것인지를 정하면 되는 문제이다.

	   즉, 1번 정점에서 -> V1이나 V2로 가는 최소 값 +
	   V1이나 V2에서 -> V2나 V1으로 가는 최소 값 +
	   V2, V1에서 -> N으로 가는 최소 값을 모두 더한 값이
	   작은 경우를 정하면 된다.

	   추가적으로 이 문제에서는 총 3개의 값을 더해야 하기 때문에
	   3 정점이 모두 INF라면 값이 오버플로우가 나기 때문에
	   ans가 계산 가능한 최대값 보다 크거나 0 미만이라면 -1을 출력하도록 해야 한다.
	   (범위 생각을 잘 해서 INF를 정의하도록 하자)
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 987654321;
int n, e, v1, v2;
int dist[3][801];
vector<pair<int, int>> arr[801];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// dist[0][n] => 1번 정점
// dist[1][n] => v1번 정점
// dist[2][n] => v2번 정점

void dijkstra(int num, int st) {
	dist[num][st] = 0;
	pq.push({ dist[num][st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (dist[num][idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (dist[num][nidx] > cost + ncost) {
				dist[num][nidx] = cost + ncost;
				pq.push({ dist[num][nidx], nidx });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
		dist[2][i] = INF;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}

	cin >> v1 >> v2;

	dijkstra(0, 1);
	dijkstra(1, v1);
	dijkstra(2, v2);

	int sum1 = dist[0][v1] + dist[1][v2] + dist[2][n];
	int sum2 = dist[0][v2] + dist[2][v1] + dist[1][n];
	int ans = 0;
	if (sum1 > sum2) ans = sum2;
	else ans = sum1;

	if (ans > 800000 || ans < 0) cout << -1;
	else cout << ans;
}