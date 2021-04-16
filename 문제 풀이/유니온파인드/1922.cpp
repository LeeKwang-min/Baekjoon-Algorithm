/*
작성자 : 이상수
일시 : 2021.04.16
제목 : 네트워크 연결 - 1922
풀이 : 유니온 파인드를 사용하는 알고리즘인 "크루스칼 알고리즘" 문제
       큰 틀은 유니온 파인드와 다르지 않다.
	   
	   1. 주어진 간선들의 비용을 오름차순으로 정렬한다.
	   2. 가장 적은 비용의 노드들부터 연결한다.
	   3. 단, 사이클이 생기지 않도록 한다.

	   여기서 
	   2번은 정렬 후에 unionParent를 실행하면 되며
	   3번은 findParent의 결과가 거짓일 때만 진행하면 해결된다.

	   유니온 파인드를 알면 간단하게 이해 가능한 알고리즘이며
	   이 문제는 크루스칼 알고리즘을 알면 간단하게 해결 가능한 문제이다.

	   주석 -> 클래스로 노드와 간선정보 저장 (자체적으로 비교 함수까지 가능(operator))

	   본문 -> 나에게 익숙한 벡터 사용 (vector, func)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[1001];
vector<pair<pair<int, int>, int>> arr; // (a -> b) = dist

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

bool func(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	/*
	vector<Edge> arr;
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back(Edge(a, b, dist));
	}

	sort(arr.begin(), arr.end());
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].distance;
			unionParent(arr[i].node[0], arr[i].node[1]);
		}
	}
	*/

	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back({ {a, b}, dist });
	}
	sort(arr.begin(), arr.end(), func);
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].first.first, arr[i].first.second)) {
			sum += arr[i].second;
			unionParent(arr[i].first.first, arr[i].first.second);
		}
	}

	cout << sum;
}