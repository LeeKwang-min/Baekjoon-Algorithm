/*
작성자 : 이상수
일시 : 2021.02.09
제목 : 플로이드 2 - 11780
풀이 : 플로이드 알고리즘에서 경로를 구해야 하는 문제

       주어진 방식과 크게 다른게 없다.
	   기본적으로 플로이드 알고리즘을 진행하면서
	   현재 정점에서 다음으로 가는 정점이 어디인지 저장하는 배열을 하나 더 사용하면 된다.

	   만약 플로이드 알고리즘에서 거쳐가는 정점이 더 짧다면
	   다음으로 가는 정점 값을 거쳐가는 정점의 값으로 바꿔준다.
	   다시 말해
	   nxt[n][m] = n에서 m으로 갈 때의 다음 정점 (이 값이 m과 같으면 도착한 것이다)
	   처음 기본값은 모두 m이다.

	   하지만, 플로이드 알고리즘을 돌면서 
	   dist[n][m] = dist[n][k] + dist[k][m] 이라면
	   nxt[n][m] = nxt[n][k]가 된다.

	   이 후에 nxt[n][m]이 m과 같을 때 까지 순회하면서 값을 저장하고 출력하면된다.
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[101][101];
int nxt[101][101];
int main() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = dist[a][b] > c ? c : dist[a][b];
		nxt[a][b] = b;
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int n1 = 1; n1 <= n; n1++) {
		for (int n2 = 1; n2 <= n; n2++) {
			for (int n3 = 1; n3 <= n; n3++) {
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3]) {
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
					nxt[n2][n3] = nxt[n2][n1];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 987654321) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> path;
			if (i == j) {
				cout << 0 << '\n';
				continue;
			}
			int cur = nxt[i][j];
			path.push_back(i);
			while (cur != j) {
				path.push_back(cur);
				cur = nxt[cur][j];
			}
			path.push_back(j);

			cout << path.size() << ' ';
			for (int k = 0; k < path.size(); k++)
				cout << path[k] << ' ';
			cout << '\n';
		}
	}
}