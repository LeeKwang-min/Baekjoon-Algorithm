/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 1, 2, 3 더하기 5 - 15990
풀이 : 1차원 DP가 아닌 2차원 DP로 풀이하는 문제이다.
       문제의 조건으로 추가된것이 동일한 숫자를 연속해서 사용하지 못한다 라는 조건인데,
	   이 때문에 기존의 점화식을 사용하지 못한다.

	   이를 풀기 위해 이 전의 수에서 해당 경우를 만드는데 어떤 수로 끝났는지를
	   저장하는 부분을 구해야 한다.

	   다시 말해 
	   D[N][K] = N을 만드는데, K를 마지막으로 사용하여 만들었다.
	   라는 뜻이다.

	   이를 사용하여 
	   D[N][K] = D[N-K][K가 아닌 1, 2, 3 중 하나] + D[N-K][K가 아닌 1, 2, 3 중 하나]
	   로 처리한다
	   Ex) D[4][1] = D[3][2] + D[3][3]
	       -> 3을 만드는 수 중 마지막에 사용한 수가 2나 3인 것에 1을 더해 4를 만드는 경우

	   문제에서 mod로 나눈 값을 출력하라고 하였는데,
	   D[N][K]를 구할때는 물론이고 ans를 구할 때에도 mod로 나누어 주어야 한다.
	   ans는 3가지 경우를 더하다 보면 int 범위를 넘어갈 수 있기 때문에 long long으로 해준다.
*/
#include<iostream>

using namespace std;

int n, t;
long long d[100001][4];
const int mod = 1000000009;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	d[1][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;
	
	for (int i = 4; i <= 100000; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = (d[n][1] + d[n][2] + d[n][3]) % mod;
		cout << ans << '\n';
	}

}