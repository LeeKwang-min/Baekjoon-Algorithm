/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 합분해 - 2225
풀이 : 이 문제에서 요구하는 방식을 그림을 그려서 보면 쉽다.
       
	   O + O + O + ... + O = N
	  |        K개        |
	  |       K-1개     |  = N - 마지막 O
	  가 된다.
	  위 그림에서 확인할 수 있듯이
	  마지막 O에 들어갈 수 있는 값은 0 ~ N이며
	  그에 따라 N - (0 ~ N) 값들을 확인하면 된다.

	  D[N][K] = 0 ~ N의 숫자를 K개 사용한 합이 N이 되는 경우의 수
	  이므로
	  D[N][K] = D[N-1][K-0] + D[N-1][K-1] + D[N-1][K-2] + ... 해가면 된다.
	  K - ? 의 범위는 N의 크기를 따라간다.
*/
#include<iostream>

using namespace std;

int n, k;
long long d[201][201];
const int mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		d[1][i] = i;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] + d[i - 1][j - k]) % mod;
			}
		}
	}

	cout << d[n][k];
}