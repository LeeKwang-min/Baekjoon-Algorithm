/*
작성자 : 이상수
일시 : 2021.01.27
제목 : 신나는 함수 실행 - 9184
풀이 : 문제에서 시키는 대로 구현하면 간단하다
	   범위는 -50 부터 50까지지만, 
	   3개의 인수 중 하나라도 1보다 작거나 20보다 크면 해당 값을 특정 값으로
	   처리 하라는 말이 있기 때문에 실질적인 범위는
	   1 ~ 20 까지가 된다.
	   이 점을 생각하여 동적 프로그래밍으로 처리하면 간단하게 해결 가능하다.
제한사항 : -50 <= a, b, c <= 50
*/

#include <iostream>

using namespace std;

int arr[21][21][21];

int main() {
	int a, b, c;
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			arr[0][i][j] = 1;
			arr[i][0][j] = 1;
			arr[i][j][0] = 1;
		}
	}

	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			for (int k = 1; k < 21; k++) {
				if (i < j && j < k) {
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				}
				else {
					arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
				}
			}
		}
	}

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		if (a < 1 || b < 1 || c < 1)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << '\n';
		else if(a > 20 || b > 20 || c > 20)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[20][20][20] << '\n';
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << '\n';
	}

}