/*
작성자 : 이상수
일시 : 2021.02.21
제목 : 링크와 스타트 - 15661
풀이 : 스타트와 링크 문제에서 팀의 인원수가 반반이 되어야 한다는 조건이 빠지고
       팀의 인우너은 같지 않아도 되지만, 최소 한명은 있어야 한다 라는 조건으로 바뀌었다.

	   스타트와 링크 문제와 풀이는 똑같으며 
	   두 벡터를 받아오고 idx가 n과 같아졌을 때 
	   두 벡터중 하나라도 비어있다면 잘못된 값으로 return 한다.

	   그렇지 않을때는 각 팀의 능력치를 계산하여 처리한다.
*/
#include<iostream>
#include<vector>

using namespace std;

int point[21][21];
int n;
int ans = 1e9;

int chk(vector<int> t) {
	int sum = 0;
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (i == j) continue;
			sum += point[t[i]][t[j]];
		}
	}
	return sum;
}

void go(int idx, vector<int> f, vector<int> s) {
	if (idx == n) {
		if (f.empty() || s.empty()) return;
		int f_point = chk(f);
		int s_point = chk(s);
		int status = f_point > s_point ? f_point - s_point : s_point - f_point;
		if (ans > status) ans = status;
		return;
	}

	f.push_back(idx);
	go(idx + 1, f, s);
	f.pop_back();

	s.push_back(idx);
	go(idx + 1, f, s);
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> point[i][j];
	vector<int> first;
	vector<int> second;
	go(0, first, second);
	cout << ans;
}