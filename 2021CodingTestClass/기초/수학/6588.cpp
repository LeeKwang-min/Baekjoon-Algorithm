/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 골드바흐의 추측 - 6588
풀이 : 2보다 큰 모든 짝수는 두 홀수 소수의 합으로 표현 가능하다.
       라는 골드바흐의 추측 문제이다.

	   C++의 입력과 출력이 느려서 ios_base와 cin.tie를 빼면 시간초과가 나온다. (유의하자)

	   에라토스테네스의 체로 미리 소수를 구해두고

	   아래에서 홀수이기 때문에 3부터 시작하여 구하면된다.
	   (2는 유일한 짝수 소수이다.)

	   10^18 이하의 수에서는 이 추측이 증명이 되었기 때문에
	   문제에서의 범위가 10^18보다 작기 때문에
	   틀렸을 때의 조건식을 넣지 않아도 된다.
*/
#include<iostream>

using namespace std;

const int MAX = 1000000;
bool chk[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	chk[0] = chk[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (chk[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			chk[j] = true;
		}
	}

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 3; i<=n; i+=2) {
			if (!chk[i] && !chk[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
				
		}
	}
}