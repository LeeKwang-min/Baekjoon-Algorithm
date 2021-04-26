/*
작성자 : 이상수
일시 : 2021.04.23
제목 : Strongly Connected Component - 2150
풀이 : SCC의 개념을 묻는 문제이다.
       정말 어렵다... 개념 자체가 어렵고 간단하게 표현하면
	   사이클을 구하는 문제인데 사이클을 구하는게 정말 어려웠던것 처럼
	   SCC의 개념도 정말 어렵다.

	   공부가 매우 많이 필요하며 
	   영상을 주기적으로 확인하여 익혀두자 (언제 어떻게 쓰일지 모르는게 알고리즘이니까...)

	   헷갈리는것
	   1. d배열의 의미
	   2. id의 쓰임
	   
	   아마도 이 2가지를 알게되면 문제는 없을것 같다.
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int v, e;
int id, d[10001]; // 각 노드마다 고유한 번호를 할당 받도록한다.
vector<int> arr[10001];
vector<vector<int>> SCC;
bool finished[10001]; // 해당 노드의 dfs가 끝났는지 확인하는 배열
stack<int> s;

int dfs(int x) {
	d[x] = ++id; // 가장 처음 부모로 설정이된 값
	s.push(x);

	int parent = d[x]; // 처음의 부모값은 자기 자신
	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << ' ';
		cout << "-1\n";
	}
}