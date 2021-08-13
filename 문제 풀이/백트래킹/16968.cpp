/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16968 - ���� ��ȣ�� 1
Ǯ�� : �־����� ������ ���̿� ���� ������ ������ �� ������ ī��Ʈ ���� ������ ���̿� �������� ������������ ��´�.
       ��� ������ ��Ƶΰ� ������ ���� ������ ������ �� ������ �� �� �ִ����� Ȯ���ϴ� ����� ������, �������� ���� ������
	   ó������ ��� �޴� ����� ����ϵ��� �ߴ�.

	   ���ڰ� d Ȥ�� c�� 2���� ��� ���̸� 
	   d�� ��� ���� 0 ~ 9 ������ 10���� ���
	   c�� ��� ���� a ~ z ������ 26���� ����̴�.
	   �� �ΰ����� ���� ���ڷ� ó������ �ʰ� ���ڷ�
	   0 ~ 9 (d) 10 ~ 25 (c) �� ó���Ͽ���.

	   ���� �ִ� ���� �� ���� � ���� ������ Ȯ���Ͽ� ���� ���� ���� �ʵ��� �Ͽ� ó���Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

string s;
int ans = 0;
int sel[4];

void go(int cnt) {
	if (cnt == s.length()) {
		ans++;
		return;
	}

	if (s[cnt] == 'd') {
		for (int i = 0; i < 10; i++) {
			sel[cnt] = i;
			if (cnt > 0 && sel[cnt] == sel[cnt - 1]) continue;
			go(cnt + 1);
		}
	}
	else {
		for (int i = 10; i < 36; i++) {
			sel[cnt] = i;
			if (cnt > 0 && sel[cnt] == sel[cnt - 1]) continue;
			go(cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	go(0);
	cout << ans << '\n';
}