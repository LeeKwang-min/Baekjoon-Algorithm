/*
작성자 : 이광민
일시 : 2021.06.10
제목 : 1913 - 달팽이
풀이 : 달팽이 배열 문제... 나를 힘들게 했던 기억들이 떠오르지만 풀어보았다.
       홀수의 n이 들어올 때 배열의 값을 주어진 조건에 맞춰 저장하는 방식이다.

	   n에 따른 각 값은
	   1 1 2 2 3 3 4 4 ... n
	   Ex) 
	   n = 5
	   1 1 2 2 3 3 4 4 5
	   
	   n = 3
	   1 1 2 2 3

	   와 같이 처리된다.
	   각 수의 정의는 x와 y좌표값의 증감이며
	   순서는 x와 y가 돌아가며 적용된다.
	   즉
	   n = 5
	   x y x y x y x y x

	   n = 3
	   x y x y x

	   그리고 증감은
	   -1 +1   +2 -2   -3 +3 ...
	   즉 (-, +) -> (+, -) -> (- +) -> ...

	   이를 따라가며 값을 채우고 출력 후 찾고자 하는 값의 좌표를 출력해주면 된다.
*/
#include <iostream>

using namespace std;

int arr[1000][1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x = n / 2, y = n / 2;
	int cnt = 1;
	int xcnt = 1, ycnt = 1;
	int xa = -1, ya = 1;
	while (1) {
		for (int i = 0; i < xcnt; i++) {
			arr[x][y] = cnt;
			x += xa;
			cnt++;
		}
		if (cnt == n * n + 1) break;
		for (int i = 0; i < ycnt; i++) {
			arr[x][y] = cnt;
			y += ya;
			cnt++;
		}
		xcnt++; ycnt++;
		xa *= -1;
		ya *= -1;
	}

	int mx, my = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
			if (arr[i][j] == m) {
				mx = i;
				my = j;
			}
		}
		cout << '\n';
	}
	cout << mx + 1 << ' ' << my + 1;
}