/*
작성자 : 이상수
일시 : 2021.04.18
제목 : 전력난 - 6497
풀이 : 크루스칼 알고리즘을 사용하여 최소 신장 트리의 비용을 구하는게 아니라
       최소 신장 트리를 만들었을 때 기존 비용보다 얼마나 절약이 되는지 구하는 문제
	   즉, 처음 입력을 받을 때 모든 거리의 합을 구해두고
	   최소 신장 트리의 비용을 구한 다음 두가지를 빼주면 답이 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[200001];

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
	while (1) {
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		for (int i = 1; i <= m; i++)
			parent[i] = i;

		vector<Edge> arr;
		int total = 0;
		for (int i = 0; i < n; i++) {
			int a, b, dist;
			cin >> a >> b >> dist;
			total += dist;
			arr.push_back(Edge(a, b, dist));
		}
		sort(arr.begin(), arr.end());
		int sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (!findParent(arr[i].node[0], arr[i].node[1])) {
				sum += arr[i].dist;
				unionParent(arr[i].node[0], arr[i].node[1]);
			}
		}

		cout << total - sum << '\n';
	}
}