/*
작성자 : 이광민
일시 : 2021.06.29
제목 : 16958 - 텔레포트
풀이 : 플로이드 와샬 알고리즘을 사용하여 풀이를 하는 문제이다.
       플로이드 와샬 알고리즘도 결국은 부르트 포스 문제에 해당된다. 모든 경우를 탐색해보고 가장 빠른 값을 찾기 때문이다.

	   텔레포트가 가능한 도시와 불가능한 도시가 존재하며 주어진 각 좌표들의 값을 2차원 배열로 나타낸다.
	   값을 처리할 때 문제에서 주어진 abs(x1 - x2) + abs(y1 - y2)와 텔레포트가 가능한 두 도시라면 텔레포트 시간을 확인하여 더 짧은 값을 가지도록 한다.

	   이 값들을 가지고 있는 dist배열을 플로이드 와샬 알고리즘을 적용시켜 최단 시간을 찾아내고
	   m개의 a, b쌍을 dist 배열에서 찾아 그 값을 출력하도록 한다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, t, m;
bool telpo[1001];
int dist[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> t;
	vector<pair<int, int>> xy(n + 1);
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		if (s == 1) telpo[i] = true;
		xy[i] = { x, y };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int x_dist = xy[i].first > xy[j].first ? xy[i].first - xy[j].first : xy[j].first - xy[i].first;
			int y_dist = xy[i].second > xy[j].second ? xy[i].second - xy[j].second : xy[j].second - xy[i].second;
			int tel = 987654321;
			if (telpo[i] && telpo[j]) tel = t;
			dist[i][j] = (x_dist + y_dist) < tel ? (x_dist + y_dist) : tel;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
}