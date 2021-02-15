/*
작성자 : 이상수
일시 : 2021.01.28
제목 : 바이러스 - 2606
풀이 : 그렇게 열심히 DFS, BFS 공부 해놓고... 또 까먹었다...
       그래서 다시 공부해서 2가지 방법으로 구현했다.

	   정말 기초적인 DFS와 BFS이다.

	   DFS의 경우 현재 노드에서 갈 수 있는 하나의 간선을 택하여 이동하며
	   BFS의 경우 현재 노드에서 갈 수 있는 모든 간선을 포함한 다음 이동한다.

	   예전에 배울 때 대부분의 그래프 문제는 BFS로 풀이가 가능하여 BFS를 위주로
	   공부를 했었다. 그래서 dfs의 stack을 사용한 개념이 조금 애매하여 
	   따로 찾아 보았다.

	   BFS에서 queue를 stack으로 바꾸는 것 말고는 달라지는게 없다.

	   stack과 queue의 자료구조 차이로 인해
	   stack의 경우 먼저 들어간 것이 아래에 깔리기 때문에 DFS의 구현이 가능하다.
	   (바킹독님 알고리즘 사이트 참조)

	   간단하게 BFS나 DFS를 돌면서 cnt 값만 적절하게 증감 시켜주면 되는 문제이다.

	   자주 습관적으로 봐주는게 중요한것 같다.... (반성)
제한사항 : -50 <= a, b, c <= 50
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool chk[101];
int arr[101][101];
int n, m;
int cnt;

void dfs(int num) {
	chk[num] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && arr[num][i] == 1) {
			cnt++;
			dfs(i);
		}
	}
}

void dfs_stack(int num) {
	chk[num] = 1;
	stack<int> s;
	s.push(num);
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		for (int i = 1; i <= n; i++) {
			if (!chk[i] && arr[x][i] == 1) {
				s.push(i);
				chk[i] = 1;
				cnt++;
			}
		}
	}
}

void bfs(int num) {
	chk[num] = 1;
	queue<int> q;
	q.push(num);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!chk[i] && arr[x][i] == 1) {
				q.push(i);
				chk[i] = 1;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	dfs_stack(1);
	cout << cnt;
}