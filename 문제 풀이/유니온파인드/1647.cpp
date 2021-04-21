/*
작성자 : 이상수
일시 : 2021.04.17
제목 : 도시 분할 계획 - 1647
풀이 : 크루스칼 알고리즘을 사용하여 최소 신장 트리(MST)를 만드는 문제
       이 문제에서는 주어진 트리를 2개의 트리로 나누어서 처리해야 한다는 문제가 있다.
	   
	   주어진 트리를 2개의 트리로 나누어서 2개의 트리에서의 간선들이 최소합은?
	   이 문제를 처음 보고 조금 고민을 했다.
	   하지만, 생각보다 고민거리가 되지 않았다.

	   우선 최소 신장 트리로 주어진 트리들을 정리하면
	   "최소 비용을 가지는 하나의 트리로 묶인다"
	   그 다음 이 하나의 트리는 사이클이 없는 하나의 간선들로만 이루어진 트리이며
	   이 트리에서 하나의 간선을 제거한다는 것은
	   "두개의 트리로 나누어진다 라는 뜻이다"
	   이렇듯 최소 비용을 원하기 때문에 
	   하나의 MST로 만들어 주고 연결 과정에서
	   가장 비싸게 연결된 간선 하나를 제거하면 2개의 트리로 나뉜
	   최소 비용이 나온다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[100001];

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	vector<Edge> arr;
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back(Edge(a, b, dist));
	}
	sort(arr.begin(), arr.end());
	int sum = 0;
	int minus;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].dist;
			minus = arr[i].dist;
			unionParent(arr[i].node[0], arr[i].node[1]);
			//cout << arr[i].node[0] << " -> " << arr[i].node[1] << '\n';
		}
	}
	cout << sum - minus;
}