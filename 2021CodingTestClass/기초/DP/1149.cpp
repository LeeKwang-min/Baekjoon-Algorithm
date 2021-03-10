/*
작성자 : 이상수
일시 : 2021.02.25
제목 : RGB 거리 - 1149
풀이 : 인접한 집간의 색깔이 달라야 한다 라는 조건에 따라
       D[N][K] = N번째 집을 K번째 색으로 칠했을 때 최소 비용
	   이라고 가정하면 
	   색깔이 R, G, B 로 3가지 뿐이기 때문에 K는 1 2 3 으로 처리한다.
	   N번째 집을 1로 칠하고 싶다면 N-1번째 집은 2나 3이여야 한다.
	   그 중 작은 비용이 드는 것을 선택하면 된다.

	   최종적으로 정답이 담긴 값은 
	   D[N][1 ~ 3] 중 최소 비용을 가지는 것이 정답이 된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int p[1001][4];
int d[1001][4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < 4; j++)
			cin >> p[i][j];

	for (int i = 1; i < 4; i++)
		d[1][i] = p[1][i];

	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + p[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + p[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + p[i][3];
	}

	int ans = 1000 * 1000;
	for (int i = 1; i < 4; i++)
		ans = min(ans, d[n][i]);

	cout << ans;
}