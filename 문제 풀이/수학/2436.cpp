/*
작성자 : 이광민
일시 : 2021.07.12
제목 : 2436 - 공약수
풀이 : 최소공배수 = num1 * num2 / 최대공약수
       위 식을 조금 변경하여 잘 사용하면 시간초과를 내지 않고 제 시간안에 풀이가 가능하다.

	   위 식을 변경하면
	   num1 * num2 = GCD * LCM이며
	   num1과 num2는 최대 공약수로 GCD를 가지고 있기 때문에 
	   (num1 * num2) / (GCD * GCD) = LCM / GCD 로 처리가 가능하다.

	   이렇게 구한 LCM / GCD의 값을 AB라고 할 때, AB의 약수들이 num1과 num2가 될 수 있는 조건이 된다.
	   하지만, 약수라고 해서 무조건 num1과 num2가 될 수 없고
	   약수들의 최대공약수와 최소공배수가 A와 B와 같을때에만 값을 가져오도록 한다.

	   주의
	   1. LCM / GCD의 값으로 약수를 찾았기 때문에 실제 GCD와 LCM을 찾을 때에는 (약수를 i라고 할 때) i * A로 찾아주어야 한다.
	   2. 최대공약수를 나눈값에서 약수를 찾기 때문에 약수의 시작을 1로 두고 시작해야 한다. (그래야 1 * A로 A가 숫자가 되는것을 포함한다)
*/
#include<iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a%b);
}

long long lcm(long long a, long long b, long long g) {
	return (a*b) / g;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long A, B;
	cin >> A >> B;
	long long AB = A * B;
	AB /= (A * A);
	int x = -1, y = -1;
	for (int i = 1; i*i <= AB; i++) {
		if (AB % i == 0) {
			int a = i * A;
			int b = AB / i * A;
			int g = gcd(b, a);
			int l = lcm(b, a, g);
			if (g == A && l == B) {
				x = a;
				y = b;
			}
		}
	}
	cout << x << ' ' << y;
}