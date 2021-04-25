/*
작성자 : 이상수
일시 : 2021.04.23
제목 : 트리의 부모 찾기 - 11725
풀이 : 트리로 분류되어 있으나 BFS를 통한 그래프 탐색 문제가 된다.
       BFS를 돌면서 처음 방문하는 노드라면 어디서 왔는지 확인하여
	   해당 값을 parent배열에 저장하고 마지막에 출력 해주면 되는 문제이다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
vector<int> arr[100001];
int parent[100001];
bool chk[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	chk[1] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto nxt : arr[x]) {
			if (chk[nxt]) continue;
			parent[nxt] = x;
			q.push(nxt);
			chk[nxt] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}