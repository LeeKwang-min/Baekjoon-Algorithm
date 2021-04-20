/*
작성자 : 이상수
일시 : 2021.04.18
제목 : 사이클 게임 - 20040
풀이 : 유니온 파인드를 사용하면 간단하게 풀리는 문제
       주어진 순서대로 진행하면서 서로 같은 부모 노드를 가지면
	   그 즉시 반복문을 종료하고 값을 가져오면 되는 문제이다.
*/

#include<iostream>

using namespace std;

int parent[500001];

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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (findParent(a, b)) {
			ans = i + 1;
			break;
		}
		unionParent(a, b);
	}
	cout << ans;
}