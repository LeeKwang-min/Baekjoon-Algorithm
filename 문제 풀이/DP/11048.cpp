/*
작성자 : 이상수
일시 : 2021.05.06
제목 : 이동하기 - 11048
풀이 : DP 문제이다.
       하나의 칸에서 총 3방향으로 갈 수 있고, 이를 반대로 말하면 
	   한 칸의 공간으로 올 수 있는 방법은 총 3가지가 있다는 뜻이다.
	   즉, 현재 칸이 (r, c) 라면, (r-1, c-1) (r-1, c) (r, c-1) 총 3군데에서 올 수 있다.

	   3가지 모두에서 올 수 있는 곳은 (1,1)에서 부터 시작하여 (n-1, m-1)까지 이며
	   0행과 0열은 모두 왼쪽에서 오른쪽으로 혹은 위에서 아래로만 갈 수 있는 방법의 수이기 때문에
	   기본 베이스값으로 지정해주고 시작하면 된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	for (int i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + arr[0][i];

	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + arr[i][0];

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];

	cout << dp[n - 1][m - 1];
}