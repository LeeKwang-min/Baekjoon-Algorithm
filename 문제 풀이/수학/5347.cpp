/*
작성자 : 이광민
일시 : 2021.07.12
제목 : 5347 - LCM
풀이 : 유클리드 알고리즘을 다시 복습하기 위해 푼 문제.
       문제의 범위가 100만 까지 가능하기 때문에 최소 공배수를 구할 때 int의 범위를 벗어날 수 있다.
	   long long으로 변환하여 모두 처리해주자.

	   유클리드 알고리즘 -> 1934번 문제 확인
*/
#include<iostream>

using namespace std;

long long GCD(long long a, long long b) {
	if (a % b == 0) return b;
	return GCD(b, a%b);
}

long long LCM(long long a, long long b) {
	return (a * b) / GCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if(a > b) cout << LCM(a, b) << '\n';
		else cout << LCM(b, a) << '\n';
	}
}