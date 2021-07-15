/*
작성자 : 이광민
일시 : 2021.06.25
제목 : 16987 - 계란으로 계란치기
풀이 : 문제에서 요구하는 과정을 정확하게 이해하고 처리하는것이 중요하다.
       몇가지 지시사항을 똑바로 이해하지 못했는데, 그 부분은 다음과 같다.

	   문제에서 요구하는
	   1. 가장 왼쪽의 계란을 든다.
	   2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 
	   (단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.) 
	   이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.
	   3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다. 
	   단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.

	   이 과정에서 2번의 괄호 친 예외 경우에 대해서 정확한 처리를 하지 못했다.
	   '손에 든 계란이 깨졌거나, 깨지지 않은 다른 계란이 없다면' 이 말을 다시 풀어서 보면 ~~거나 이기 때문에 따로 보게되면
	   손에 든 계란이 깨졌다 -> cur번째 계란의 내구도가 0 이하이다.
	   깨지지 않은 다른 계란이 없다 -> 단 한번도 다른 계란과 부딪힌 적이 없다.

	   이 경우에 대해 처리해주면 된다.
	   우선 손에 든 계란이 깨졌는지 확인해주고 깨졌다면 3번 과정 (go(cur+1))으로 넘어가고
	   깨지지 않았다면 계란을 하나씩 확인해주면서 깨지지 않은것이 있는가 확인한다.
	   이 때 깨지지 않은 다른 계란이 없다면 이 말은 위에서 요구한 예외와 일치하며 더불어 더이상 진행이 무의미하다는 의미가 된다.
	   그렇기 때문에 바로 go(n)으로 넘어가주면 된다. (이를 위해 부딪혔는지 안했는지를 확인하기 위한 bool 변수가 필요)

	   추가적으로
	   "손에 든 계란이 깨졌다면" 의 반대는 "손에 든 계란이 깨지지 않았다면"이 된다. 그렇기 때문에
	   서로 독립적 시행이 아닌 조건문을 통한 서로 연관된 실행을 해야한다.


	   놓친것
	   1. if ~ else (깨졌거나 안깨졌거나)
	   2. chk (부딪혔거나 안부딪혔거나)
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int ans = 0;
vector<pair<int, int>> v;

void go(int cur) {
	if (cur == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (v[i].first <= 0) cnt++;
		if (ans < cnt) ans = cnt;
		return;
	}

	if (v[cur].first <= 0) go(cur + 1);
	else {
		bool chk = true;
		for (int i = 0; i < n; i++) {
			if (cur == i || v[i].first <= 0) continue;
			v[cur].first -= v[i].second;
			v[i].first -= v[cur].second;
			chk = false;
			go(cur + 1);
			v[cur].first += v[i].second;
			v[i].first += v[cur].second;
		}
		if (chk) go(n);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, w;
		cin >> s >> w;
		v.push_back({ s, w });
	}
	go(0);
	cout << ans;
}