/*
작성자 : 이상수
일시 : 2021.03.07
제목 : 배열 복원하기 - 16967
풀이 : 구현문제
       자기 자신을 위치만 이동하여 덧붙여 합을 늘리는 방식이기 때문에
	   이동한 만큼의 범위에 대해서만 신경을 써주면 된다.

	   값이 바뀌었다는 것은 자기 자신과의 합이 더해졌다는 뜻이며

	   이를 반대로 생각하면 이동한 만큼의 범위가 된다면
	   기존의 값을 빼주면 원래의 값으로 돌아오게 된다.
*/
#include<iostream>

using namespace std;

int h, w, x, y;

int a[301][301];
int b[600][600];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> x >> y;

	for (int i = 0; i < h + x; i++)
		for (int j = 0; j < w + y; j++)
			cin >> b[i][j];

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			a[i][j] = b[i][j];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i - x < 0 || j - y < 0) continue;
			a[i][j] -= a[i - x][j - y];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}