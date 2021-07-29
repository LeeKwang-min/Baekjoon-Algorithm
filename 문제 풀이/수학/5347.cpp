/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.12
���� : 5347 - LCM
Ǯ�� : ��Ŭ���� �˰����� �ٽ� �����ϱ� ���� Ǭ ����.
       ������ ������ 100�� ���� �����ϱ� ������ �ּ� ������� ���� �� int�� ������ ��� �� �ִ�.
	   long long���� ��ȯ�Ͽ� ��� ó��������.

	   ��Ŭ���� �˰��� -> 1934�� ���� Ȯ��
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