/*
작성자 : 이상수
일시 : 2021.01.30
제목 : 최소 힙 - 1927
풀이 : 우선순위 큐 선언한 다음 최대 힙을 구현해야 하기 때문에 less로 비교해서 저장한다.
	   문제의 시간이 매우 작은 모양이다.
	   ios_base와 cin.tie를 해주지 않으면 시간초과가 발생한다.
	   외우고 적어주자

	   11279번 문제도 같은 문제이며 lsee를 greater로 바꿔주면 된다.
제한사항 :
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(a);
		}
	}
}