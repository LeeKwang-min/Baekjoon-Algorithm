/*
작성자 : 이상수
일시 : 2021.02.10
제목 : 최단경로 - 1753
풀이 : 다익스트라를 사용하는 문제
	   아래 주석으로 되어있는 부분은 직관적으로 생각한 방식으로 O(n^2)과 메모리 초과 에러가 난다

	   본 코드의 내용은 힙을 사용하여 풀이한 코드이다.
	   다익스트라 알고리즘에서 항상 최소 비용을 가지는 값을 골라야 하는데
	   이 때 최소 힙을 선언하면 유용하게 사용 가능하다.

	   과정은 다음과 같다.
	   1. 각 간선 정보를 (비용, 도착정점) 저장한 다음 ★
	   2. 시작 노드를 힙에 넣어준다. (0, 시작노드)
	   
	   3. 힙에서 비용이 가장 적은 원소를 선택한다. (최소힙을 사용하기 때문에 그냥 .top())
	   4. 해당 원소는 힙에서 제거한다. (.pop())
	   5. 최단 거리 배열(dist)의 값과 힙의 비용을 비교하여 같지 않으면 continue (dist[idx] != dst)
	   6. 같은 경우
		6.1. 최단 거리 배열의 값과 비교하여 같다면 해당 정점에서 갈 수 있는 다른 정점들(도착점)을 
			 확인하여 시작점에서 도착점까지 바로가는 경우와 idx를 거쳐가는 경우를 비교하여 처리
			 해주고 그 값들을 힙에 넣어준다.
		6.2. 값이 다르다면 그냥 힙에서 제거하고 넘어간다.
	   7. 이 과정을 힙이 빌때까지 반복한다.

	   8. 최종 값을 출력해준다.

	   그 유명한 다익스트라 알고리즘이다. 힙을 사용하는 방식은 O(NlgN)으로 처리가 가능하다고 한다.
	   이 과정을 익혀두고 사용하자.

	   플로이드와 다익스트라 2가지가 코딩 테스트에서 주로 쓰인다.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
const int INF = 1e9 + 10; // ★
int dist[20001];
vector<pair<int, int>> arr[20001]; // 간선 정보를 저장하기 위한 벡터 
								   // 2차원 배열을 사용하지 않고 arr[정점] = {{비용, 정점}} 이다.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	// 최소 힙을 사용하여 항상 최소값이 선택되도록 한다.

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	fill(dist, dist + n + 1, INF); // ★
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b }); // ★
	}
	dist[k] = 0;
	pq.push({ dist[k], k }); // 시작점을 (0, 시작점) 으로 힙에 넣는다.
	while (!pq.empty()) { // 다익스트라 처리 시작 // ★
		auto cur = pq.top();
		pq.pop();
		int dst = cur.first, idx = cur.second; // dst = 비용, idx = 정점
		if (dist[idx] != dst) continue; // 최단 거리 배열과 값이 다르다면 continue
		for (auto nxt : arr[idx]) { // nxt = idx에서 갈 수 있는 정점들 정보 (비용, 정점)
			int cost = nxt.first, nidx = nxt.second; // cost = 다음 정점까지 비용, nidx = 다음 정점
			if (dist[nidx] > dst + cost) { // 최단 거리 배열과 비교하여 거쳐가는게 더 싸다면
				dist[nidx] = dst + cost; // 최단 거리 배열의 값을 변경
				pq.push({ dist[nidx], nidx }); // 그 정보를 힙에 담는다.
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

















/*
// O(n^2)의 풀이 (시간, 메모리 초과가 난다)
#include <iostream>

using namespace std;

int n, m, k;
int INF = 987654321;

int dist[20001];
bool chk[20001];
int line[20001][20001];

int getSmallerIndex() {
	int min = INF;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		if (i == k) continue;
		if (min > dist[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = line[k][i];
	chk[start] = true;
	for (int i = 1; i <= n - 1; i++) {
		int cur = getSmallerIndex();
		chk[cur] = true;
		for (int j = 1; j <= n; j++) {
			if (chk[j]) continue;
			if (dist[j] > dist[cur] + line[cur][j])
				dist[j] = dist[cur] + line[cur][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			line[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		line[a][b] = line[a][b] > c ? c : line[a][b];
	}

	dijkstra(k);

	dist[k] = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}
*/