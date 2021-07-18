/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.12
���� : 2436 - �����
Ǯ�� : �ּҰ���� = num1 * num2 / �ִ�����
       �� ���� ���� �����Ͽ� �� ����ϸ� �ð��ʰ��� ���� �ʰ� �� �ð��ȿ� Ǯ�̰� �����ϴ�.

	   �� ���� �����ϸ�
	   num1 * num2 = GCD * LCM�̸�
	   num1�� num2�� �ִ� ������� GCD�� ������ �ֱ� ������ 
	   (num1 * num2) / (GCD * GCD) = LCM / GCD �� ó���� �����ϴ�.

	   �̷��� ���� LCM / GCD�� ���� AB��� �� ��, AB�� ������� num1�� num2�� �� �� �ִ� ������ �ȴ�.
	   ������, ������ �ؼ� ������ num1�� num2�� �� �� ����
	   ������� �ִ������� �ּҰ������ A�� B�� ���������� ���� ���������� �Ѵ�.

	   ����
	   1. LCM / GCD�� ������ ����� ã�ұ� ������ ���� GCD�� LCM�� ã�� ������ (����� i��� �� ��) i * A�� ã���־�� �Ѵ�.
	   2. �ִ������� ���������� ����� ã�� ������ ����� ������ 1�� �ΰ� �����ؾ� �Ѵ�. (�׷��� 1 * A�� A�� ���ڰ� �Ǵ°��� �����Ѵ�)
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