/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 오르막 수 - 11057
풀이 : 수가 같거나 커지는 모습을 가져야 하며 
       0으로 시작이 가능하기 때문에

	   D[1][0 ~ 9] = 1
	   D[i][j] = sum(d[i-1][k])  (k <= j)
	   로 처리해주면 된다.
*/
#include<iostream>

using namespace std;

int n;
int d[1001][10];
const int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] + d[i - 1][k]) % mod;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + d[n][i]) % mod;

	cout << ans;
}