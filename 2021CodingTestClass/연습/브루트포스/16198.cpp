/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 에너지 모으기 - 16198
풀이 : 에너지를 선택해가면서 해당 에너지 구슬을 지우면 되는데,
       풀기는 했지만, 새로운 벡터를 만들어서 넘기는 과정에서 시간을 조금 잡아먹는다.

	   이를 해결할 방법이 필요하며 (구현 코드로 변경)
	   (기존 코드는 반복문을 돌며 처리)

	   넘겨주는 벡터의 크기가 3보다 작다면 더이상 구슬을 부수지 못하므로
	   값을 비교해주고 종료하면 된다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int ans = 0;

void go(vector<int> e, int mul) {
	if (e.size() < 3) {
		if (ans < mul) ans = mul;
		return;
	}

	for (int i = 1; i < e.size() - 1; i++) {
		vector<int> tmp(e);
		tmp.erase(tmp.begin() + i);
		go(tmp, mul + e[i - 1] * e[i + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<int> energy(n);
	for (int i = 0; i < n; i++)
		cin >> energy[i];

	go(energy, 0);
	cout << ans;
}