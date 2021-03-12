/*
작성자 : 이상수
일시 : 2021.03.12
제목 : 줄 세우기 - 2252
풀이 : 위상정렬 알고리즘이다.
       위상정렬 알고리즘의 방법

	   조건
	   1. 사이클이 없어야 하고
	   2. 방향성 그래프여야 한다

	   큐를 사용한다.
	   방법
	   1. 진입 차수가 0인 모든 정점을 큐에 삽입
	   2. 큐에서 원소를 하나 꺼내서 해당 정점과 연결된 모든 간선 제거
	   3. 제거 과정에서 진입차수가 0이된 정점들 큐에 삽입
	   4. 큐가 빌때까지 반복
		(4 도중 모든 정점을 방문하지 못하고 큐가 빈다면 사이클이 존재한다는 뜻이다.)
	   5. 이 때에 큐에서 빠져나오는 과정이 위상정렬 결과이다.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> arr[32001];
int inDegree[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (auto nxt : arr[x]) {
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}
	
}