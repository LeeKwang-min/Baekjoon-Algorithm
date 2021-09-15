/*
�ۼ��� : �̱���
�Ͻ� : 2021.09.15
���� : ���� �� ���ϱ� 5 - 11660
Ǯ�� : (x1, y1) ~ (x2, y2) �� ������ �� �����غ��� Ǯ�̰� ������ �����̴�.
	   �� ������ ���� �������� ���Ѵٰ� �������� �� 
	   (1, 1) ~ (x2, y2)�� ���� �˰� �ִٸ� 
	   ��ġ�� �κа� ���ʿ��� �κп� ���� ó���� ���ָ� Ǯ�̰� �����ϴ�.

	   ������� 
	   (2,2) ~ (3,3) �� ���� ���ؾ� �Ѵٸ�
	   dp[3][3] - dp[1][3] - dp[3][1] + dp[1][1]�� ó���� �����ϴ�.
	   ��, ��ȭ���� dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] �� �ȴ�.
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