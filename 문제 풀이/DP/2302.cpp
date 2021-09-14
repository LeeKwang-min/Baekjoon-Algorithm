/*
작성자 : 이광민
일시 : 2021.09.14
제목 : 극장 좌석 - 2302
풀이 : 서로 이어진 좌석 n개가 있을 때 이동 가능한 경우의 수를 구한 다음
       VIP들의 지정석을 제외하고 그 경우의 수를 모두 곱해주면 정답이 나온다.
	   1명이 있을 경우 1개의 경우가 생기고
	   2명이 있을 경우 2개의 경우가 생기고
	   3명이 있을 경우 3개의 경우가 생기고
	   4명이 있을 경우 5개의 경우가 생긴다.

	   위 값을 점화식으로 바꾸면
	   d[n] = d[n-2] + d[n-1] 이 된다.

	   카운트를 0부터 세어야 하기 때문에 d[0]의 값도 1로 주어야 하며
	   위 점화식을 코드에 적용시켜 그 값들을 처리하면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int d[41];
bool chk[41];
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		chk[tmp] = true;
	}
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}

	int ans = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			ans *= d[cnt];
			cnt = 0;
		}
		else cnt++;
	}
	ans *= d[cnt];
	cout << ans;
}
