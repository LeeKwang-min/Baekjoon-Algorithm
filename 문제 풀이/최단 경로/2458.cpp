/*
작성자 : 이광민
일시 : 2021.07.13
제목 : 2458 - 키 순서
풀이 : 플로이드 와샬 알고리즘을 사용하여 그래프에서 서로 연관되어 있는지를 확인할 수 있는 문제
       문제에서 n보다 m이 키가 크다 라는 정보를 준다.

	   이 정보를 이용하여 내 키가 주어진 N명 중에서 몇번째 순서인지 확인 가능한 사람의 명수를 구하는 문제이다.
	   플로이드 알고리즘을 사용하면 이는 간단하게 해결된다.

	   처음 M개의 관계가 주어지고 이 관계를 사용하여 다음과 같이 진행하면 된다.
	   플로이드 알고리즘을 사용하여 현재 n과 m의 관계가 없지만 (dist[n][m] == INF)
	   n과 k, k와 m의 관계가 있다면 (dist[n][m] > dist[n][k] + dist[k][m])
	   이는 n, k, m 학생들 사이의 관계를 유추할 수 있기 때문에 알고리즘을 통해 뽑아낼 수 있다.

	   모든 과정을 마치고 나서 자신의 순위를 확실히 알 수 있는 사람이 몇명인지 확인하는 방법은
	   dist[n][m] => n보다 m이 키가 크다 이므로

	   dist[n][m]과 dist[m][n] 둘 중 하나라도 그 값이 INF가 아니라면 (키에 대한 관계가 있다면)
	   이는 자신이 해당 인원보다 크거나 작다는것을 알 수 있기 때문에 카운트를 증가 시켜준다.
	   자기 자신을 제외하고 N-1명과의 관계가 나온다면 자신의 순위를 알수있는 인원이므로 정답의 갯수를 늘려준다.
*/
#include<iostream>

using namespace std;

const int INF = 987654321;
int n, m;
int dist[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) 
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF || dist[j][i] != INF)
				sum++;
		}
		if (sum == n - 1) ans++;
	}

	cout << ans;
}