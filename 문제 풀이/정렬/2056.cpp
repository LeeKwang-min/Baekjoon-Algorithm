/*
작성자 : 이광민
일시 : 2021.06.29
제목 : 2056 - 작업
풀이 : 예전에 풀었던 스타크래프트 선수 빌딩 문제와 비슷하다.
       위상정렬을 통해 우선시되는 값들을 가져오고 이 값들을 어떤 시간에 맞추어야 하는지를 정해야 한다.

	   2가지 실수를 했다.
	   1. 전역변수로 선언하는것을 주로 하다보니 값의 초기화를 하지 않았다.
	   2. 진입 차수가 0이 될때만 값의 비교를 통해 변화를 주었다.

	   우선 1번부터 확인하면 이건 실수가 맞다. 기본적으로 지역 변수로 선언을 하고 초기화를 거치지 않으면 그 값은 무엇이 될지 모르고
	   그렇기 때문에 정상적인 출력이 이루어질 수가 없다. (어떤 입력이 오는지는 모르겠으나, 초기화를 통해 해결이 가능했다.)

	   2번은 진입차수가 0이되는 시점은 모든 선행 작업이 끝날때이다. 
	   이 말은 다시 말하자면 큐에 어떤 순서로 들어가는지에 따라 진입차수가 0이되는 시점이 달라진다는 말이된다.
	   그렇기 때문에 진입 차수가 0이 되는 시점에만 비교를 진행하면 올바른 값이 오지 않게되고 모든 정점에서 그 값을 비교해주어야 한다.

	   이렇게 진행한 다음 모든 정점의 걸리는 시간인 result에서 가장 오래 걸리는 시간을 구해서 정답으로 출력해주면 된다.
	   (모든 건물을 짓는 것을 완료해야 하기 때문이다.)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int inDegree[10001];
int time[10001];
//int result[10001];
vector<int> g[10001];

int calc() {
	queue<int> q;
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			result[y] = max(result[y], result[x] + time[y]);
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, result[i]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int kn;
		cin >> time[i];
		cin >> kn;
		for (int j = 0; j < kn; j++) {
			int degree;
			cin >> degree;
			inDegree[i]++;
			g[degree].push_back(i);
		}
	}

	cout << calc();
}