/*
작성자 : 이상수
일시 : 2021.04.01
제목 : 카드 합체 놀이 - 15903
풀이 : 우선순위 큐를 사용하면 간단하게 해결되는 문제이다.
       최소 힙을 구성하여 힙에 저장되어있는 값 중 가장 작은 값 2가지를 
	   꺼내어 서로 더한 다음 값을 2번 푸쉬하여 저장해주면 된다.

	   이렇게 진행하면서 그 값이 int 범위를 넘어갈 수 있기 때문에
	   int가 아닌 long long형을 사용해주면 된다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (k--) {
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();
		pq.push(first + second);
		pq.push(first + second);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}