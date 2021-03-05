/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 배열 돌리기 1 - 16926
풀이 : 구현 문제인데 달뱅이배열이랑 비슷하다.
       sx와 sy의 값은 0,0 에서 시작하여 순회를 마치고 배열 안쪽으로 들어갈 때
	   1씩 커진다. 값이 순회를 할 때 바뀌는것이 아닌가 싶어 값을 따로 지정해야 하나
	   했지만, 순회를 하다보면 결국은 처음의 값으로 돌아오게 되어있다.
	   즉, 따로 값을 바꾸거나 지정할 필요는 없다.

	   처음엔 N-1번 M-1번씩 반복하며 그 다음은 N-3, M-3 씩 2씩 증가하며 감소한다.
	   이 값이 n과 m보다 클때까지만 하면 된다.

	   간단하지만 파악이 힘든 구현문제이다.
*/
#include<iostream>

using namespace std;

int n, m, r;
int arr[301][301];

void rotation() {
	int tmp[301][301];
	int miner = 1;
	int sx = 0, sy = 0;
	while (n > miner && m > miner) {
		for (int i = 0; i < n - miner; i++) {
			tmp[sx + 1][sy] = arr[sx][sy];
			sx++;
		}
		for (int i = 0; i < m - miner; i++) {
			tmp[sx][sy + 1] = arr[sx][sy];
			sy++;
		}
		for (int i = 0; i < n - miner; i++) {
			tmp[sx - 1][sy] = arr[sx][sy];
			sx--;
		}
		for (int i = 0; i < m - miner; i++) {
			tmp[sx][sy - 1] = arr[sx][sy];
			sy--;
		}
		miner += 2;
		sx++; sy++;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (r--) {
		rotation();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}