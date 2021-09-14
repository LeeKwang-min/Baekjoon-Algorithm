/*
�ۼ��� : �̱���
�Ͻ� : 2021.09.14
���� : ���� �¼� - 2302
Ǯ�� : ���� �̾��� �¼� n���� ���� �� �̵� ������ ����� ���� ���� ����
       VIP���� �������� �����ϰ� �� ����� ���� ��� �����ָ� ������ ���´�.
	   1���� ���� ��� 1���� ��찡 �����
	   2���� ���� ��� 2���� ��찡 �����
	   3���� ���� ��� 3���� ��찡 �����
	   4���� ���� ��� 5���� ��찡 �����.

	   �� ���� ��ȭ������ �ٲٸ�
	   d[n] = d[n-2] + d[n-1] �� �ȴ�.

	   ī��Ʈ�� 0���� ����� �ϱ� ������ d[0]�� ���� 1�� �־�� �ϸ�
	   �� ��ȭ���� �ڵ忡 ������� �� ������ ó���ϸ� �ȴ�.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int d[41];
bool chk[41];
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		chk[tmp] = true;
	}
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}

	int ans = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			ans *= d[cnt];
			cnt = 0;
		}
		else cnt++;
	}
	ans *= d[cnt];
	cout << ans;
}
