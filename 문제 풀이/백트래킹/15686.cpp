/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 15686 - 치킨 배달
풀이 : 언뜻 문제를 보면 2차원 배열을 사용해야 할 것 같지만, 
	   치킨집의 위치와 집의 위치만 가지고 조합을 통해 정답을 도출하는 조합 문제이다.
	   치킨집의 위치들을 벡터에 모두 저장해두고 이 중에서 M개를 뽑아 조합을 만들어
	   집들의 거리를 계산하고 최소값을 구해주면 된다.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int ans = 987654321;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> choose_chicken;

int calc() {
	int ret = 0;
	for (int i = 0; i < house.size(); i++) {
		int closer = 1000;
		for (int j = 0; j < choose_chicken.size(); j++) {
			int x = house[i].first > choose_chicken[j].first ? house[i].first - choose_chicken[j].first : choose_chicken[j].first - house[i].first;
			int y = house[i].second > choose_chicken[j].second ? house[i].second - choose_chicken[j].second : choose_chicken[j].second - house[i].second;
			closer = min(closer, x + y);
		}
		ret += closer;
	}
	return ret;
}

void go(int nxt, int cnt) {
	if (cnt == m) {
		int cur = calc();
		ans = min(ans, cur);
		return;
	}

	for (int i = nxt; i < chicken.size(); i++) {
		choose_chicken.push_back(chicken[i]);
		go(i + 1, cnt + 1);
		choose_chicken.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2) chicken.push_back({ i, j });
		}
	}
	go(0, 0);
	cout << ans;
}