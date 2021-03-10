/*
작성자 : 이상수
일시 : 2021.02.16
제목 : 테트로미노 - 14500
풀이 : 브루트포스이면서 구현력을 보는 문제
       최대 500 * 500칸에서 총 경우의 수 19가지를 검사하는 문제이기 때문에
	   브루트 포스로 모든 경우의수를 확인하면 되는 간단한 문제이다.

	   다만... 엄청나게 노가다를 해야 한다...
	   (그림 그리고 좌표 적어두고 구현하면 쉽다)
*/
#include<iostream>
#include<algorithm>

using namespace std;

int point[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> point[i][j];
		}
	}

	int totalPoint = 0;
	// ㅁㅁㅁㅁ 가로
	for (int i = 0; i < n; i++) { // 가로
		for (int j = 0; j < m - 3; j++) { // 세로
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i][j + 3];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁㅁㅁ 세로
	for (int i = 0; i < n - 3; i++) {
		for (int j = 0; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 3][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁ
	// ㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i][j + 1] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁ
	// ㅁ
	// ㅁㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ㅁ
	//   ㅁ
	// ㅁㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁ
	//   ㅁ
	//   ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁ
	// ㅁ
	// ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j] + point[i + 2][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁㅁ
	//     ㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁㅁ
	// ㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//     ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 2; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 1][j - 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ㅁ
	// ㅁㅁ
	//   ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁ
	// ㅁㅁ
	// ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j - 1] + point[i + 1][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁㅁ
	//   ㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j - 1] + point[i + 1][j] + point[i][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁ
	// ㅁㅁ
	//   ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ㅁ
	// ㅁㅁ
	// ㅁ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ㅁㅁ
	//   ㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ㅁㅁ
	// ㅁㅁ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j - 1] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	cout << totalPoint;
}