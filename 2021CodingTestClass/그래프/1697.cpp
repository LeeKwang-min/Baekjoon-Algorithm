/*
작성자 : 이상수
일시 : 2021.03.04
제목 : 숨바꼭질 - 1697
풀이 : 1차원 배열에서 bfs 탐색을 진행하는 문제이다.
       일반적인 bfs 문제와 똑같으며 2차원 좌표를 1차원에서 진행한다고 생각하면 된다.
	   이동 방법이 3가지가 있기 때문에 이 3가지 방법에 대해 진행하면 된다.

	   범위는 최대 10만 까지 갈 수 있기때문에
	   그 두배인 20만으로 잡아주는것이 좋다.
*/
#include<iostream>
#include<queue>

using namespace std;

int dist[200001];
bool chk[200001];
int n, k;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int nx;
		nx = now - 1;
		if (nx >= 0 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}

		nx = now + 1;
		if (nx < 200000 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}

		nx = now * 2;
		if (nx < 200000 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}
	}

	cout << dist[k];
}