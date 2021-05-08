/*
작성자 : 이상수
일시 : 2021.05.07
제목 : 13302 - 리조트
풀이 : DP 탑다운 방식에 익숙해지기 위한 문제 2
       탑다운 방식의 매력이 느껴지기 시작한다.

	   바텀업 방식이 초기 값 구성이 중요했다면,
	   탑다운 방식은 조건의 구성이 매우 중요하다
	   (종료 조건, 건너뛰기, 값의 추가, return값 등등)

	   일반적으로 0이 값이 되는 것들이 많이 있으므로 
	   초기 d배열의 값들을 모두 -1로 두는 방식을 사용하자. (문제를 잘 읽고 무조건이 아니라 잘 파악하자)

	   바텀업의 경우 이 문제에서는 쿠폰이 최대 몇개가 있을지 예상해서 모두 확인하고 최소 값을 찾는 과정을 거쳐야 하는데,
	   탑다운방식의 경우 재귀함수를 통해 최소값을 자체적으로 찾아서 넘겨주기 때문에 그 과정을 생략 가능하다.

	   하지만, 메모리 사용율이 높다는 단점이 있다

	   두 방식을 모두 알아두고 잘 사용해야하겠다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[101];
int d[101][101];
bool chk[101];

int dp(int a, int b) {
	if (chk[a]) return dp(a + 1, b);
	if (d[a][b] != -1) return d[a][b];
	if (a > n) return 0;
	
	d[a][b] = 987654321;
	if (b >= 3) d[a][b] = min(d[a][b], dp(a + 1, b - 3));
	d[a][b] = min(d[a][b], dp(a + 1, b) + 10000);
	d[a][b] = min(d[a][b], dp(a + 3, b + 1) + 25000);
	d[a][b] = min(d[a][b], dp(a + 5, b + 2) + 37000);
	//cout << "d[" << a << "][" << b << "] = " << d[a][b] << '\n';
	return d[a][b];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			d[i][j] = -1;
	for (int i = 0; i < m; i++) {
		int day;
		cin >> day;
		chk[day] = true;
	}

	cout << dp(1, 0);
}