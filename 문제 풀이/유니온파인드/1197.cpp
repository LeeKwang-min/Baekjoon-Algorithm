/*
작성자 : 이광민
일시 : 2021.07.01
제목 : 1197 - 최소 스패닝 트리
풀이 : 크루스칼 알고리즘의 개념을 묻는 문제이다.
       크루스칼 알고리즘은 유니온-파인드를 사용하여 최소 스패닝 트리(최소 신장 트리)를 찾는 알고리즘이다.

	   크루스칼 알고리즘 구현법을 안다면 간단하게 해결할 수 있는 문제이다.
	   최소신장트리 문제는 몇몇 대기업 코테 단골 문제라고 하니 잘 파악해두자.

	   외우는것이 아니라 어떤 개념으로 이루어져있고 어떻게 구성되어있는지 이해하고
	   이를 기반으로 코드를 작성할 수 있도록 하자.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v, e;
int parent[10001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

class Edge {
public:
	int node[2];
	int dist;

	Edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}

	bool operator <(Edge &edge) {
		return this->dist < edge.dist;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	vector<Edge> arr;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(Edge(a, b, c));
	}

	sort(arr.begin(), arr.end());

	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].dist;
			unionParent(arr[i].node[0], arr[i].node[1]);
		}
	}
	cout << sum;
}