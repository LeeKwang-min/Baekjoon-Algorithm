/*
작성자 : 이상수
일시 : 2021.03.12
제목 : N번째 큰 수 - 2075
풀이 : 우선순위 큐를 사용하는 문제
       우선순위 큐를 사용하여 슬라이딩 윈도우를 구현하면 된다.
	   min heap을 구현하여 가장 상단의 n개를 입력 받아 큐에 담는다.
	   이 값을 담은 순간 힙의 top은 n번째로 큰 수이다.

	   이 후에 n개씩 값을 입력 받으며
	   총 2n개의 힙에서 n개를 제외해주면 또 다시 n번째 큰 수가 top에 오게 된다.

	   이 과정을 반복 해주면 된다.
*/
#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		for (int k = 0; k < n; k++) pq.pop();
	}

	cout << pq.top();
}