/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16938 - ķ�� �غ�
Ǯ�� : ������ ���� ������ �����ϴ� ��쿡 ���� ������ �Ǵ��� Ȯ���ϸ� �Ǵ� �����̴�.
       ������ �ߺ��� �ƴ� ������ �����ְ� �� ������ Ȯ���Ͽ� �� ���� �־��� ���ǿ� �´��� (����, �ְ�, �ְ� - ������) Ȯ�����ش�.
	   �� ������ �����ϴ� ��쿡 ���� ���� ���������ָ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, L, R, X;
int A[16];
bool chk[16];
int ans;
vector<int> v;

void go(int nxt, int cnt, int sum) {
	if (cnt >= 2) {
		if (v[v.size() - 1] - v[0] >= X && sum >= L && sum <= R) ans++;
	}
	if (cnt >= N) return;

	for (int i = nxt; i < N; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		v.push_back(A[i]);
		go(i + 1, cnt + 1, sum + A[i]);
		v.pop_back();
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	go(0, 0, 0);

	cout << ans;
}