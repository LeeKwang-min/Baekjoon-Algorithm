/*
작성자 : 이상수
일시 : 2021.03.29
제목 : 스타트링크 - 5014
풀이 : BFS탐색 문제이다.
       1차원 공간에서의 BFS탐색 문제여서 매우 간단한 문제이다.

	   하지만, 기존의 BFS 코드 작성 방식이 이 문제에서는 올바르게 작동하지 않는다.

	   평소 작성 방식은 코드가 만족하지 않으면 continue를 통해 반복문을 진행하는 방식이였다.
	   이 방식은 상, 하, 좌, 우 4가지 방향에 대해서 하나의 반복문을 통해 진행하며
	   이 반복문 안에서 continue를 진행하기 때문에 문제가 되지 않았지만

	   이 문제의 경우 U와 D에 대해 따로 배열을 만들지 않았기 때문에
	   만족하지 않을때 continue를 하게 되면 위의 이동만 확인하고 넘어갈 가능성이 생긴다.

	   이는 잘못된 방식이며 이를 방지하기 위해
	   조건을 만족할 때 큐에 새로운 좌표를 넣는 방식을 사용하면 해결된다.
*/
#include<iostream>
#include<queue>

using namespace std;

int f, s, g, u, d;
int arr[1000001];
int chk[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> f >> s >> g >> u >> d;

	queue<int> q;
	q.push(s);
	chk[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int nxtUp = x + u;
		int nxtDown = x - d;

		if (nxtUp > 0 && nxtUp <= f && chk[nxtUp] == false) {
			q.push(nxtUp);
			chk[nxtUp] = chk[x] + 1;
		}
		
		if (nxtDown > 0 && nxtDown <= f && chk[nxtDown] == false) {
			q.push(nxtDown);
			chk[nxtDown] = chk[x] + 1;
		}
		
	}

	if (chk[g] == 0) cout << "use the stairs";
	else cout << chk[g] - 1;
}