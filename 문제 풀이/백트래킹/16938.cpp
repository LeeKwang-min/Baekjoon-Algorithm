/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16938 - 캠프 준비
풀이 : 조합을 구해 조건을 만족하는 경우에 한해 정답이 되는지 확인하면 되는 문제이다.
       조합은 중복이 아닌 조합을 구해주고 이 값들을 확인하여 그 값이 주어진 조건에 맞는지 (최저, 최고, 최고값 - 최저값) 확인해준다.
	   위 조건을 만족하는 경우에 대해 답을 증가시켜주면 된다.
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