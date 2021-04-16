/*
작성자 : 이상수
일시 : 2021.04.16
제목 : 집합의 표현 - 1717
풀이 : 유니온-파인드를 구현 가능한가 확인하는 문제
       유니온파인드를 사용하여 합하고 서로 연결되어 있는지를 확인하는 문제이다.
*/
#include<iostream>

using namespace std;

int n, m;
int parent[1000001];

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
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	while (m--) {
		int wm, a, b;
		cin >> wm >> a >> b;
		if (wm == 0) unionParent(a, b);
		else {
			if (findParent(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}