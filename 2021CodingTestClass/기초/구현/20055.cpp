/*
작성자 : 이상수
일시 : 2021.03.07
제목 : 컨베이어 벨트 위의 로봇 - 20055
풀이 : 구현문제
       문제 설명이 매우 애매하다...

	   문제에서 말하는 단계란
	   컨베이어 벨트 한칸이 이동하는것이 1단계이다
	   (내 해석은 로봇 하나가 내려가면 1단계 증가인줄 알았다...)

	   구현은 문제에서 주어지는 단계를 무조건 따라가야 한다.

	   무조건 한칸 회전이 우선이며 시작하면 회전이 우선된다.
	   각 단계 중간중간에
	   로봇이 내려가는 위치에 간 것은 아닌지 확인해야 하며
	   새로운 칸으로 이동할 때 로봇이 있는지 없는지를 확인해야한다.

	   유용한 STL
	   vector<int> a
	   1. rotate(a.begin(), a.begin()+1, a.end());
	   2. rotate(a.rbegin(), a.rbegin()+1, a.rend());

	   1. ABCD -> BCDA
	   2. ABCD -> DABC

	   a.begin()부터 a.begin()+1 까지의 범위를 a.end로 보낸다.
	   rend() = 뒤에서 부터 끝 = 가장 앞
*/
#include<iostream>
#include<deque>

using namespace std;

int n, k;
deque<int> dq;
deque<bool> chk;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	int zeroCnt = 0;
	int ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		int ai;
		cin >> ai;
		if (ai == 0) zeroCnt++;
		dq.push_back(ai);
		chk.push_back(false);
	}

	if (zeroCnt >= k) {
		cout << 1;
		return 0;
	}

	for(ans = 0; ; ans++) {
		// 한칸 회전한다.
		int bc = dq.back();
		dq.pop_back();
		dq.push_front(bc);

		bool bck = chk.back();
		chk.pop_back();
		chk.push_front(bck);

		// 한칸 회전하게 된다면 로봇이 내려가는 자리로 갈수도있다.
		if (chk[n - 1]) {
			chk[n - 1] = false;
		}
		
		// 로봇들 한칸 이동
		for (int i = n - 2; i >= 0; i--) {
			if (chk[i] && chk[i + 1] == false && dq[i + 1] > 0) {
				chk[i] = false;
				chk[i + 1] = true;
				dq[i + 1]--;
			}
		}

		if (chk[n - 1]) {
			chk[n - 1] = false;
		}

		// 로봇이 없다면 로봇을 올린다.
		if (dq[0] > 0 && chk[0] == false) {
			dq[0]--;
			chk[0] = true;
		}

		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
			if (dq[i] <= 0) cnt++;
		zeroCnt = cnt;
		if (zeroCnt >= k) break;
	}

	cout << ans + 1;
}