/*
작성자 : 이상수
일시 : 2021.02.19
제목 : 스타트와 링크 - 14889
풀이 : 백트래킹 = 브루트포스 + 종료 조건
       (브루트 포스를 진행하다가 더 이상의 호출이 의미가 없을 경우 함수를 종료하는 방식)

	   백트래킹 문제이다.
	   코드 중간에 적어둔 조건문 한줄로 인해 함수의 실행 속도가 엄청 줄어든다.

	   1. 해맨 부분이라고 적어둔 부분과 같이 실수할 수 있는 부분을 정신 차리고 보자
	   2. vector의 가장 뒤에 넣었으면 가장 뒤에걸 빼면 된다 (pop_back())
	   3. 수업에서 사용한 코드는 int형 함수로 작성하였는데 함수의 실행 시간이 엄청 차이난다.
	   (왜...?)
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int status[21][21];
int ans = 1e9;

int statpoint(vector<int> team) {
	int sum = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = 0; j < team.size(); j++) {
			if (i == j) continue;
			sum += status[team[i]][team[j]]; // 해맨 부분
		}
	}
	return sum;
}

void go(int idx, vector<int> f, vector<int> s) {
	if (f.size() > n / 2 || s.size() > n / 2) return; // 이 한줄로 인해 292ms -> 168ms 가 됨
	if (idx == n) {
		if (f.size() != n / 2) return;
		if (s.size() != n / 2) return;
		int f_score = statpoint(f);
		int s_score = statpoint(s);
		int subscore = f_score > s_score ? f_score - s_score : s_score - f_score;
		if (ans > subscore) ans = subscore;
		return;
	}

	// first 팀에 들어간 경우
	f.push_back(idx);
	go(idx + 1, f, s);
	f.pop_back(); // erase를 쓸 필요 없음
	// second 팀에 들어간 경우
	s.push_back(idx);
	go(idx + 1, f, s);
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> status[i][j];

	vector<int> first;
	vector<int> second;
	go(0, first, second);
	cout << ans;
}