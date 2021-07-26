/*
작성자 : 이광민
일시 : 2021.07.01
제목 : 2252 - 줄 세우기
풀이 : 위상정렬을 복습하기 가장 좋은 문제. 이미 풀었던 문제를 복습한 내용이다.
       위상정렬을 수행하며 그 결과를 출력해주자.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int inDegree[32001];
vector<int> arr[32001];

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
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	vector<int> result;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		result.push_back(x);
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
}