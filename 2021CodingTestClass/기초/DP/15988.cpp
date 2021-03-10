/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 1, 2, 3 더하기 3 - 15988
풀이 : 1, 2, 3 더하기 문제와 모든 조건이 같지만, 주어지는 N의 크기가
       최대 백만이기 때문에 브루트포스로 풀이가 불가능하다.

	   일반적인 식을 사용해서 풀면 된다.
	   하지만, 정답이 엄청나게 커지기 때문에
	   d배열을 long long 형으로 해주어야 한다.

	   주의
	   1. 자료형
	   2. 나머지 연산
*/
#include<iostream>

using namespace std;

int n, t;
long long d[1000001];
const int mod = 1000000009;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % mod;

	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}