/*
작성자 : 이상수
일시 : 2021.02.09
제목 : Line Friends (Small) - 14588
풀이 : 플로이드 알고리즘을 사용하면 간단하게 풀이가 되는 문제이다.
       다만, 주어지는 정보가 거리나 배열의 인덱스 값으로 바로 주어지는 것이 아니라
	   다른 방식의 정보를 가공하여 인덱스값으로 집어 넣어야 하는 문제이다.

	   문제의 풀이는 다음과 같다. 
	   1차원 좌표상에서 주어지는 범위와 다른 범위들을 비교하여 
	   서로 겹치는 경우에 그래프의 좌표를 1로 주고 플로이드 알고리즘을 돌리면 간단하게 풀이된다.

	   처음 생각한 방식은 겹치는 경우를 생각하여 조건문을 구성하였는데
	   이 값이 생각보다 너무 많다 (4가지 경우 -> 성립하는 경우)

	   이렇게 풀어도 문제가 풀리지만, 조금만 시선을 바꿔서 
	   성립하지 않는 경우를 그냥 넘기면 더욱 간단하게 처리가 되었다.

	   기존의 4가지 경우로 짜여진 4개의 조건문에서 
	   성립하지 않는 2가지 경우를 OR 연산으로 구현한 1개의 조건문 만으로 처리가 되었다.

	   아래의 주석의 코드가 성립하는 경우를 구현한 코드이고
	   본문의 코드가 성립하지 않는 경우를 구현한 코드이다.

	   시선을 달리하는 습관을 가지자.
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[301][301];

int main() {
	cin >> n;
	vector<pair<int, int>> line(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		line[i] = make_pair(a, b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = line[i].first;
			int b = line[i].second;
			int c = line[j].first;
			int d = line[j].second;
			if (b < c || a > d) continue; // 성립하는 조건에서 성립하지 않는 조건으로 바꾼 조건문
			dist[i][j] = 1;
			dist[j][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int n1 = 1; n1 <= n; n1++) {
		for (int n2 = 1; n2 <= n; n2++) {
			for (int n3 = 1; n3 <= n; n3++) {
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3])
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
			}
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == 987654321) cout << -1 << '\n';
		else cout << dist[a][b] << '\n';
	}
}


// 위 설명에서 말한 복잡하게 생각한 경우의 구현 코드
/*
for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = line[i].first;
			int b = line[i].second;
			int c = line[j].first;
			int d = line[j].second;
			if (a <= c && b >= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (a >= c && b <= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (b >= c && b <= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (a <= d && b >= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
		}
	}
*/