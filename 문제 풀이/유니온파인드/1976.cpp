/*
작성자 : 이상수
일시 : 2021.04.17
제목 : 여행 가자 - 1976
풀이 : 유니온 파인드를 사용하여 풀이한 문제
       문제의 설명에서 해당 문제는 BFS, DFS로도 풀 수가 있다고 한다
	   (주어지는 간선 정보가 행렬 그래프 형식으로 주어지기 때문에 가능하다)

	   행렬로 주어지는 정보들을 서로 합쳐주고 (Union)
	   마지막 여행 경로를
	   0 - 1 // 1 - 2 // 2 - 3 // ...
	   로 서로 같은 집합에 속해있는지 확인(Find)해주면 되는 문제이다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, m;
int parent[201];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) unionParent(i, j);
		}
	}

	vector<int> res(m);
	for (int i = 0; i < m; i++)
		cin >> res[i];

	bool chk = true;
	for (int i = 0; i < res.size() - 1; i++) {
		if (!findParent(res[i], res[i + 1])) {
			chk = false;
			break;
		}
	}

	if (chk) cout << "YES";
	else cout << "NO";
}