/*
작성자 : 이상수
일시 : 2021.03.10
제목 : N-Queen - 9663
풀이 : 백트래킹을 돌면서 맞는 경우의 수를 찾으면 되는 문제
       강의에서 알려주는 풀이는 매번 다른 풀이를 알려줘서 너무 힘들다...

	   퀸은 공격 가능한 방향이
	   좌, 우 대각선과 가로 세로 행 열 이다.
	   이를 감안하여 같은 대각선과 같은 방향의 행 열에는 하나의 퀸만 남을 수 있다.
*/
#include<iostream>

using namespace std;

int n, cnt = 0;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void go(int k) {
	if (k == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[k + i] || isused3[n + k - i - 1]) continue;
		isused1[i] = true;
		isused2[k + i] = true;
		isused3[n + k - i - 1] = true;
		go(k + 1);
		isused1[i] = false;
		isused2[k + i] = false;
		isused3[n + k - i - 1] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	go(0);
	cout << cnt;
}