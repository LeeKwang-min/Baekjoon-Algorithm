/*
작성자 : 이광민
일시 : 2021.07.09
제목 : 1934 - 최소공배수
풀이 : 유클리드 호제법(유클리드 알고리즘) 을 사용하여 '최대공약수'와 '최소공배수'의 관계를 통한 풀이 문제이다.

       유클리드 호제법 : 2개의 자연수나 정식의 "최대공약수"를 구하는 알고리즘
	   호제법 : 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻는 알고리즘
	   방법
	   1. a, b가 있을 때, a를 b로 나눈 나머지를 r이라 한다. (단, a > b)
	   2. a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
	   3. 나머지인 r이 0이 될 때 나누는 수가 a와 b의 최대공약수이다. 
		  (a % b == 0 ---> b가 a와 b의 최대공약수)

	   이를 재귀함수를 통해 간단하게 구현할 수 있다.
	   gcd(a, b) -> a%b가 0이라면 b를 리턴 0이 아니라면 gcd(b, a%b)를 리턴


	   최소공배수의 경우
	   두 수 a, b가 있을 때, a와 b를 곱한 값에 a와 b의 최대공약수를 나누어주면 최소공배수가 된다.
	   방법
	   1. (a * b) / gcd(a, b)
*/
#include<iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lcm(int a, int b, int g) {
	return (a * b) / g;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int g;
		if(a > b) g = gcd(a, b);
		else g = gcd(b, a);
		cout << lcm(a, b, g) << '\n';
	}
}