/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 동물원 - 1309
풀이 : 동물을 배치하는 방법이
       배치하지 않는것도 하나의 방법으로 치기 때문에
	   배치하지 않은 경우   (0)
	   왼쪽에 배치한 경우   (1)
	   오른쪽에 배치한 경우 (2)
	   로 두고
	   D[N][K] = N * 2 크기의 우리에 K에 배치한 경우의 수가 된다.
	   D[1][0] = 1  D[1][1] = 1  D[1][2] = 1
	   로 두고 각 경우를 처리하면 된다.
	   D[N][0] = 모든 D[N-1]이 올 수 있다.
	   D[N][1] = D[N-1]에서 왼쪽을 제외한 나머지가 올 수 있다.
	   D[N][2] = D[N-1]에서 오른쪽을 제외한 나머지가 올 수 있다.

	   정답은 0부터 2까지의 합이다.

	   주의
	   ans += d[][] % mod -> 잘못된 표현
	   ans = (ans + d[][]) % mod -> 올바른 표현
*/
#include<iostream>

using namespace std;

int n;
int d[100001][3];
const int mod = 9901;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % mod;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % mod;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % mod;
	}

	int ans = 0;
	for (int i = 0; i < 3; i++)
		ans = (ans + d[n][i]) % mod;
	cout << ans;
}