/*
작성자 : 이광민
일시 : 2021.09.15
제목 : 구간 합 구하기 5 - 11660
풀이 : (x1, y1) ~ (x2, y2) 의 범위를 잘 생각해보면 풀이가 가능한 문제이다.
	   위 범위에 대한 구간합을 구한다고 가정했을 때 
	   (1, 1) ~ (x2, y2)의 합을 알고 있다면 
	   겹치는 부분과 불필요한 부분에 대한 처리를 해주면 풀이가 가능하다.

	   예를들어 
	   (2,2) ~ (3,3) 의 합을 구해야 한다면
	   dp[3][3] - dp[1][3] - dp[3][1] + dp[1][1]로 처리가 가능하다.
	   즉, 점화식은 dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] 가 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1025][1025];
int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		dp[1][i] = dp[1][i - 1] + arr[1][i];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}

}