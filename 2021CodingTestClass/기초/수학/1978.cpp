/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 소수 찾기 - 1978
풀이 : 일반적인 소수 찾는 문제
       주어지는 테스트 케이스가 100개 이하이고 그 값이 1000 이하이기 때문에
	   일반적인 소수 계산을 통해 진행해도 충분히 통과 가능하다.

	   주의사항
	   1. 검사는 주어지는 수 N의 제곱근 까지만 해주면된다.
	   2. 제곱근을 할 때는 함수 sqrt는 근사값으로 떨어지기 때문에 i * i로 하는게 정확하다.
*/
#include<iostream>

using namespace std;

bool prime(int a) {
	if (a < 2) return false;
	 
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		int a;
		cin >> a;
		if (prime(a)) cnt++;
	}
	cout << cnt;
}