/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 쉬운 계단 수 - 10844
풀이 : 인접한 수가 무엇인지 알아야 하기 때문에 2차원 배열로 DP를 진행하였다.
       "D[N][K] = K로 끝나는 N자리 수의 개수" 로 설정하였다.
	   이 말은 K로 끝나기 위해서는 N-1자리에서 K-1 혹은 K+1로 끝났어야 한다.
	   하지만, K-1은 음수가 되면 안되고, K+1은 10보다 작아야 한다는 조건이 있다.

	   이 두가지를 만족할 때
	   D[N][K] = D[N-1][K-1] + D[N-1][K+1] 이 된다. (K-1과 K+1은 조건을 만족해야 함)

	   0으로 시작하지 못하기 때문에 기본 베이스 값으로 D[1][K] 는 0을 제외한 나머지 숫자들
	   1 ~ 9는 모두 1이 된다.

	   추가적으로 ans += d[n][i] % mod 로 처리하면 
	   d[n][i] % mod 가 먼저 처리되어 ans에는 계속 값이 증가하기 때문에 오버플로가 난다.
	   아래 코드처럼 ans = (ans + d[n][i]) % mod 와 같이 처리해 주어야 한다
	   (연산자 우선순위)
*/
#include<iostream>

using namespace std;

int n;
long long d[101][10];
const int mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				d[i][j] += (d[i - 1][j - 1]) % mod;
			}
			if (j + 1 <= 9) {
				d[i][j] += (d[i - 1][j + 1]) % mod;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + d[n][i]) % mod;

	cout << ans;
}