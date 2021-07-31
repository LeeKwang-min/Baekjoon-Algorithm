/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16943 - ���� ���ġ
Ǯ�� : �ִ� ���ڰ� 10^9�̸� �ڸ����� ������ 9�ڸ��̴�.
       �׷��� ������ �� ���ڵ��� ��� ������ �������� ����� �����ص� ����� ������ �ð��̴�.

	   A�� �ڸ����� ���Ϳ� �������� �����Ѵ�.
	   �� ���ͷ� ������ ����� �� ���� B���� ������ Ȯ���Ѵ�.
	   �������� �����߱� ������ 1�ڸ����� �ε��� 0�� ����Ǿ� �ִ�. 
	   while���� ���� ���� ó���ϸ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int A, B, ans = -1;
int sel[11];
bool chk[11];
vector<int> v;

int num() {
	if (sel[v.size() - 1] == 0) return -1;
	int ret = 0;
	int mul = 1;
	for (int i = 0; i < v.size(); i++) {
		ret += mul * sel[i];
		mul *= 10;
	}
	if (ret < B) return ret;
	return -1;
}

void go(int cnt) {
	if (cnt == v.size()) {
		int cur = num();
		if (cur != -1) ans = max(ans, cur);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (chk[i]) continue;
		chk[i] = true;
		sel[cnt] = v[i];
		go(cnt + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> A >> B;
	int tmpA = A;
	while (tmpA != 0) {
		v.push_back(tmpA % 10);
		tmpA /= 10;
	}
	
	go(0);
	cout << ans;
}