/*
작성자 : 이상수
일시 : 2021.04.16
제목 : 줄 세우기 - 2252
풀이 : 위상정렬 복습
	   위상정렬 하는 방법
	   1. 차수를 설정한다.
	   2. 차수가 0인 노드들을 큐에 넣고 반복문을 실행한다.
	   3. 위상정렬은 사이클이 발생하면 불가능하기에 반드시 모든 노드를 1번 방문하는 
	      총 N번의 반복이 필요하다.
	   4. 큐의 가장 앞의 값을 뺀다
	   5. 해당 값을 정답 벡터에 넣어준다.
	   6. 해당 노드에서 이동 가능한 값들을 확인하여 해당 노드들의 차수를 1씩 감소시키며
	      만약 차수가 0이 되는 노드가 있다면 해당 노드를 큐에 넣는다.
	   7. 이 과정을 반복하여 최종적으로 정답 벡터를 출력해준다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int inDegree[32001];
vector<int> arr[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		ans.push_back(x);

		for (auto nxt : arr[x]) {
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}

	for (int x : ans) cout << x << ' ';
}


