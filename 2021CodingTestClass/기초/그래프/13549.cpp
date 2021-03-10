/*
작성자 : 이상수
일시 : 2021.03.04
제목 : 숨바꼭질 3 - 13549
풀이 : BFS문제인데 총 3가지 풀이방법이 있다
       (내 풀이는 정확한지는 모르겠으나 문제에서 통과가 되었다)

	   이 문제의 핵심은 순간이동의 처리에 있다. 값의 변화가 없기 때문에 값이 변하는 다른 곳들 보다 먼저 처리가 되어야 하기 때문이다.

	   1. 큐 하나 사용
	    내 풀이이다. 순간이동을 먼저 처리해야 한다면 기존의 BFS 처리에서 순간이동 부분인 x * 2 부분만 잘 처리하면 되지 않을까라는 생각에 해당 부분을 
		BFS의 가장 앞으로 옮겨서 처리해 보았다. 이렇게 처리하니 통과가 되었다.
		정확히 생각해보면 이는 틀린 풀이라고 생각이 되는데 문제에서 처리가 되었으니 맞는것인지도 모르겠다.

	   2. 큐 두개 사용
	    현재 값 큐와 다음 값 큐를 두어 순간이동에 대해서는 모두 현재 값 큐에 넣고 값이 증가하는 곳들에 대해서는 다음 큐 값에 넣어주고 처리하도록 한다.
		이렇게 진행하면 첫번째 큐와 두번째 큐를 계속 바꿔주며 처리해야 하고 마지막에 첫번째 큐에 두번째 큐를 대입하는 방식을 사용하면 두 큐가 모두 비었을 때 탐색을 종료하게 된다.

	   3. 덱 사용
	    덱은 앞, 뒤에서 pop, push를 할 수 있기 때문에 덱을 사용하면 편하게 처리가 가능하다. (큐보다 시간도 빠르다)
		값이 변하지 않는 순간이동에 대해서는 덱의 front에 push 해주고 값이 변하는 이동에 대해서는 덱의 back에 push 해주면 된다.
		이렇게 처리하면 덱의 앞에는 현재 값들이 모이고 덱의 뒤에는 다음 값들이 모이기 때문이다.

		이처럼 BFS를 처리할 때 가중치가 1만 있는게 아니라 "가중치가 0과 1이 함께 있을 경우" 덱을 사용하면 편하게 처리 가능하다. 
*/
#include<iostream>
#include<queue>
#include<deque>

using namespace std;

int dist[200001];
bool chk[200001];
int n, k;
queue<int> q;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	dq.push_back(n);
	chk[n] = true;
	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();

		if (x * 2 <= 100000 && chk[x * 2] == false) {
			dq.push_front(x * 2);
			chk[x * 2] = true;
			dist[x * 2] = dist[x];
		}

		if (x - 1 >= 0 && chk[x - 1] == false) {
			dq.push_back(x - 1);
			chk[x - 1] = true;
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 <= 100000 && chk[x + 1] == false) {
			dq.push_back(x + 1);
			chk[x + 1] = true;
			dist[x + 1] = dist[x] + 1;
		}
	}

	cout << dist[k];
}

/*
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x * 2 <= 200000 && chk[x * 2] == false) {
			q.push(x * 2);
			chk[x * 2] = true;
			dist[x * 2] = dist[x];
		}

		if (x - 1 >= 0 && chk[x - 1] == false) {
			q.push(x - 1);
			chk[x - 1] = true;
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 <= 200000 && chk[x + 1] == false) {
			q.push(x + 1);
			chk[x + 1] = true;
			dist[x + 1] = dist[x] + 1;
		}
	}
*/