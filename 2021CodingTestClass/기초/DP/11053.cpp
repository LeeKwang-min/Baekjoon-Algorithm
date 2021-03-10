/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 가장 긴 증가하는 부분 수열 - 11053
풀이 : N번째 자리의 수를 부분 수열로 쓸 경우 LIS가 어떻게 되는가 라는 관점에서 보면
       N번째 자리의 수와 1 ~ N-1 번째 자리의 수들을 비교하여 
	   A[N] > A[1 ~ N-1] 인 것을 찾고 max(D[1 ~ N-1]) + 1 이 정답이다.

	   즉 자신의 이전 수까지의 수열 중에서 가장 긴 LIS를 찾아서 +1을 해주는게 정답이다.
	   D[N] = MAX(D[K]) + 1
	   K < N
	   A[K] < A[N]
*/
#include<iostream>

using namespace std;

int n;
int d[1001];
int a[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int maxCnt = 0;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && maxCnt < d[j]) maxCnt = d[j];
		}
		d[i] = maxCnt + 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < d[i]) ans = d[i];
	cout << ans;
}