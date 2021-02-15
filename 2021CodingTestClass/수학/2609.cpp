/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 최대공약수와 최소공배수 - 2609
풀이 : 최대공약수는 유클리드 호제법
       최소공배수는 최대공약수를 이용하여

	   유클리드 호제법 => GCD(a, b) = GCD(b, a%b) 이며 b가 0일 때 a가 a와 b의 최대공약수이다.

	   최소 공배수 => GCD(a, b) = g 라고 할 때
	   LCM(a, b) = (a * b) / g 이다.
*/
#include<iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	
	int g = gcd(a, b);
	int l = a * b / g;

	cout << g << '\n';
	cout << l << '\n';
}