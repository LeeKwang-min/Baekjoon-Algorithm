// http://blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221240353788&categoryNo=128&parentCategoryNo=0&viewDate=&currentPage=4&postListTopCurrentPage=&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=4
// https://www.youtube.com/watch?v=WR5U_oWwf54

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, m, st, fn;
int inDegree[10001], result[10001], c[10001];
vector<Edge> a[10001]; // 시작점 -> 도착점
vector<Edge> b[10001]; // 도착점 -> 시작점

void topologySort() {
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if (result[y.node] <= y.time + result[x])
				result[y.node] = y.time + result[x];

			if (--inDegree[y.node] == 0) q.push(y.node);
		}
	}

	int count = 0;
	q.push(fn);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			if (result[y] - result[x.node] == x.time) {
				count++;
				if (c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}

	cout << result[fn] << '\n' << count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, node, time;
		cin >> x >> node >> time;
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(x, time));
		inDegree[node]++;
	}
	cin >> st >> fn;
	topologySort();
}