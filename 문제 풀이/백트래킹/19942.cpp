/*
작성자 : 이광민
일시 : 2021.09.16
제목 : 다이어트 - 19942
풀이 : 모든 경우를 확인해보고 조건을 만족하는 조합 중 가장 최소 비용을 가지는 조합을 찾는 문제
       조건 중 맞는 조합이 없을 때 -1을 출력해주는걸 빼먹고 한번 틀렸다.

	   모든 경우의 수를 돌면서 현재 ans값 보다 작은 경우가 생기면 ans를 바꿔주고
	   vector를 사용하여 조건을 만족하는 집합을 ansC라는 벡터에 대입하는 방식으로 그 값을 넣어준다.
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