/*
작성자 : 이상수
일시 : 2021.01.30
제목 : 가운데를 말해요 - 1655
풀이 : 우선순위 큐를 2개 사용해서 처리하는 문제이다.
       옛날 제출 중 시간 초과로 풀지 못한 이력이 있어 확인해보니
	   매 입력마다 sort를 진행했는데 시간 제한이 0.1초여서 통과가 안되는게 당연했다.

	   문제의 풀이 개념은 다음과 같다.
	   2개의 우선순위 큐를 
	   하나는 최대 힙
	   하나는 최소 힙을 구현한다.

	   최대 힙의 모든 원소는 최소 힙의 모든 원소보다 작게 설정하며

	   최대 힙의 크기는 최소 힙의 크기보다 1보다 크거나 같도록 설정한다.

	   크기를 맞추다 보면 처음 말한 조건이 위배되는 경우가 생기는데,
	   우선 push를 한 다음
	   이 경우 최소 힙의 가장 큰 값은 최대 힙의 가장 큰 값보다 크기 때문에
	   이 두 값을 swap 해주도록 하자.

	   중간 값을 구하는 우선순위 큐 문제였다.

	   익혀두자 많이 쓰일듯 하다
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> lpq; // 최소힙
	priority_queue<int, vector<int>, less<int>> gpq; // 최대힙
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (gpq.size() > lpq.size()) lpq.push(a);
		else gpq.push(a);

		if (!gpq.empty() && !lpq.empty()) {
			if (gpq.top() > lpq.top()) {
				int n1 = gpq.top();
				int n2 = lpq.top();
				gpq.pop();
				lpq.pop();
				lpq.push(n1);
				gpq.push(n2);
			}
		}
		cout << gpq.top() << '\n';
	}
}