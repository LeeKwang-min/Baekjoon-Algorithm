/*
작성자 : 이상수
일시 : 2021.03.04
제목 : 숨바꼭질 4 - 13913
풀이 : bfs의 경로를 추적하는 방법
       역추적을 사용하면 풀이가 가능하다.
	   
	   평소 방식은 vector를 사용하여 저장 후 출력 해주었으나

	   stack을 사용하여 reverse를 사용하지 않거나

	   재귀함수를 통해 처리가 가능하다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;
int dist[200001];
bool chk[200001];
int pre[200001];
queue<int> q;

void print(int p) {
	if (p != n) {
		print(pre[p]);
	}
	cout << p << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x - 1 >= 0 && chk[x-1] == false) {
			q.push(x - 1);
			chk[x - 1] = true;
			pre[x - 1] = x;
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 <= 200000 && chk[x + 1] == false) {
			q.push(x + 1);
			chk[x + 1] = true;
			pre[x + 1] = x;
			dist[x + 1] = dist[x] + 1;
		}

		if (x * 2 <= 200000 && chk[2 * x] == false) {
			q.push(x * 2);
			chk[x * 2] = true;
			pre[x * 2] = x;
			dist[x * 2] = dist[x] + 1;
		}
	}

	cout << dist[k] << '\n';
	// 재귀함수인 print 함수로 대체 가능
	/*
	vector<int> path;
	int x = k;
	while (x != n) {
		path.push_back(x);
		x = pre[x];
	}
	path.push_back(x);
	reverse(path.begin(), path.end());
	for (auto i : path)
		cout << i << ' ';
	*/
	print(k);
}