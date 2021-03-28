/*
작성자 : 이상수
일시 : 2021.03.28
제목 : 탑 - 2493
풀이 : 스택을 2개 사용해서 푸는 문제 (하나만 써도 될거같긴하다)
       첫번째 스택 = 탑들의 높이
	   두번째 스택 = 현재 수신 가능한 탑을 찾는 탑들의 정보와 위치

	   이 두가지를 가지고 풀면 된다.
	   두번째 스택이 핵심 스택이다.
	   두번째 스택의 구조는 stack<pair<int, int>> 로서
	   first = 높이 second = 위치 정보이다.

	   이 두가지르 가지고 새로운 탑의 정보가 들어오면 해당 탑의 높이를
	   현재 탐색중인 탑들의 정보와 비교하여 새로운 탑의 높이가 더
	   높을 동안 두번째 스택을 pop해가면서 값을 비워주고 넣어준다.

	   이렇게 값을 추가하여 첫번째 스택이 모두 빌 동안 
	   두번째 스택에서 나오지 못했다면 이는 수신 가능한 탑이 없다는 뜻이기 때문에
	   모두 0을 넣어주면 된다.
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> arr;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push(tmp);
	}

	vector<int> ans(n + 1, 100);
	int idx = n;
	stack<pair<int, int>> srr;
	srr.push({ arr.top(), idx });
	arr.pop();
	while (!arr.empty()) {
		idx--;
		if (srr.top().first >= arr.top()) {
			srr.push({ arr.top(), idx });
			arr.pop();
		}
		else {

			while (!srr.empty()) {
				int now = srr.top().first;
				if (now >= arr.top()) break;
				ans[srr.top().second] = idx;
				srr.pop();
			}

			srr.push({ arr.top(), idx });
			arr.pop();
		}
	}

	while (!srr.empty()) {
		ans[srr.top().second] = 0;
		srr.pop();
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	
}