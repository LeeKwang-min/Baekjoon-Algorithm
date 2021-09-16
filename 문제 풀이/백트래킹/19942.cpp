/*
�ۼ��� : �̱���
�Ͻ� : 2021.09.16
���� : ���̾�Ʈ - 19942
Ǯ�� : ��� ��츦 Ȯ���غ��� ������ �����ϴ� ���� �� ���� �ּ� ����� ������ ������ ã�� ����
       ���� �� �´� ������ ���� �� -1�� ������ִ°� ���԰� �ѹ� Ʋ�ȴ�.

	   ��� ����� ���� ���鼭 ���� ans�� ���� ���� ��찡 ����� ans�� �ٲ��ְ�
	   vector�� ����Ͽ� ������ �����ϴ� ������ ansC��� ���Ϳ� �����ϴ� ������� �� ���� �־��ش�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int ans = 987654321;
vector<int> choise;
vector<int> ansC;

void go(int cnt, int cp, int cf, int cs, int cv, int cc) {
	if (ans < cc) return;
	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
		if (ans > cc) {
			ans = cc;
			ansC = choise;
		}
		return;
	}

	for (int i = cnt; i <= 15; i++) {
		choise.push_back(i);
		go(i + 1, cp + p[i], cf + f[i], cs + s[i], cv + v[i], cc + c[i]);
		choise.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}

	go(1, 0, 0, 0, 0, 0);

	if(ans == 987654321) cout << -1 << '\n';
	else cout << ans << '\n';
	for (int i : ansC)
		cout << i << ' ';
}