/*
작성자 : 이상수
일시 : 2021.03.25
제목 : 카드 - 11652
풀이 : 문제의 범주는 정렬에 해당되는 문제이지만, 나의 풀이는 hash_map을 사용하였다.
       각 값을 key로 넣어 가장 큰 값을 가지는것을 O(n)에 찾도록 하였다.

	   이 문제는 주어지는 값의 범위가 int로 부족하기 때문에
	   long long으로 받아주고 저장하고 출력해야 한다.
*/
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<long long, int> hm;
	for (int i = 0; i < n; i++) {
		long long tmp; // 이 부분에서 int tmp로 선언하여 처음에 문제가 생겼음
		cin >> tmp;	   // 자료형 조심!
		hm[tmp]++;
	}

	long long ans = 0, cnt = 0;
	for (auto i : hm) {
		if (cnt < i.second) {
			ans = i.first;
			cnt = i.second;
		}
		if (cnt == i.second) {
			ans = ans < i.first ? ans : i.first;
		}
	}

	cout << ans;
}