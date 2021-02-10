/*
작성자 : 이상수
일시 : 2021.02.11
제목 : 최소비용 구하기 2 - 11779
풀이 : 다익스트라의 경로 복원 문제
       플로이드 알고리즘과 매우 유사한데,
	   플로이드 알고리즘의 경로를 찾는것은 start에서 시작하여 다음 노드를 찾아 갔다면

	   다익스트라 알고리즘의 경로를 찾는것은 "end에서 시작하여 이전 노드를 찾아간다"
	   즉 거꾸로 탐색을 해간다는 것이다.
	   
	   방법은 다음과 같다
	   힙에 들어가서 값의 처리가 일어날 때, 새로운 정점의 이전 노드를 기록하는 것이다.
	   플로이드와 달리 1차원 배열만 있으면 된다.

	   문제 구현에서 처음엔 플로이드와 비슷하게 접근해서 nxt라고 배열을 지었으나
	   정확한 명칭은 pre가 맞을것 같다.

	   ★ 이 후가 아닌 이 전의 노드를 저장하고 받아와서 반대로 출력한다.

	   추가적으로 변수 이름을 잘 지을 필요가 있다.
	   확실한 명칭을 위해 end와 같은 값을 선언한 적이 있는데 이는 vector의 iter와 
	   이름이 겹치기도 하므로 다른 이름을 선언할 필요가 있다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

vector<pii> line[1001];
int d[1001];
int nxt[1001];
const int INF = 1e9 + 10;
int n, m, st, en;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(d, d + n + 1, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({ c, b });
	}

	cin >> st >> en;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int dist = cur.first, idx = cur.second;
		if (d[idx] != dist) continue;
		for (auto nnxt : line[idx]) {
			int cost = nnxt.first, nidx = nnxt.second;
			if (d[nidx] > cost + dist) {
				d[nidx] = cost + dist;
				pq.push({ d[nidx], nidx });
				nxt[nidx] = idx; // 어느 노드에서 왔는지를 기록
			}
		}
	}


	int now = en; // end에서 출발하여 값을 path에 기록
	vector<int> path;
	while (now != st) {
		path.push_back(now);
		now = nxt[now];
	}
	path.push_back(now);
	reverse(path.begin(), path.end()); // 뒤집어 준 다음 출력

	cout << d[en] << '\n';
	cout << path.size() << '\n';
	for (auto i : path)
		cout << i << ' ';
}