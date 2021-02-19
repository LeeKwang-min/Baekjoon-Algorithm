/*
작성자 : 이상수
일시 : 2021.02.19
제목 : 1, 2, 3 더하기
풀이 : 이 문제는 최대 경우의 수가 3^10으로 브루트 포스를 사용하여 풀어도 되고
       DP를 사용하여 풀어도 되는 문제이다.

	   브루트 포스로 풀이 하는 경우 재귀함수를 통해 구현하고
	   DP의 경우 자신 이전의 3개 값을 더하여 처리가 가능하다.
*/
#include<iostream>

using namespace std;

int go(int sum, int n) {
	if (sum == n) return 1;
	else if (sum > n) return 0;

	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(sum + i, n);
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
}