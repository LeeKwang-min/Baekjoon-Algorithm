/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 배열 돌리기 3 - 16935
풀이 : 항상 느끼지만 구현 문제는 쌩 노가다라서 한 문제 풀고나면 눈이 아프다...
       배열을 돌리고 처리하는 문제이다.

	   그림을 그려가면 좌표를 비교하면 간단하게 처리 되지만 
	   주의할 점은 상하, 좌우 반전과 달리
	   90도 회전, 순서 변경등은 그 값들이 바뀔 위험이 있기 때문에 
	   따로 배열을 두고 사용해야 한다.

	   그 외에는 딱히 어렵진 않고 시간이 좀 걸리는 문제이다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m, r;
int arr[101][101];

void first() {
	for (int i = 0; i < n / 2; i++) 
		for (int j = 0; j < m; j++) 
			swap(arr[i][j], arr[n - i - 1][j]);
}

void second() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m / 2; j++) 
			swap(arr[i][j], arr[i][m - 1 - j]);
}

void third() {
	int tmp[101][101];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[j][n - 1 - i] = arr[i][j];

	swap(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void fourth() {
	int tmp[101][101];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[m-1-j][i] = arr[i][j];

	swap(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void fifth() {
	int tmp[101][101];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i][j + m / 2] = arr[i][j];
	
	for (int i = 0; i < n / 2; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i + n / 2][j] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i][j - m / 2] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i - n / 2][j] = arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void sixth() {
	int tmp[101][101];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i + n / 2][j] = arr[i][j];

	for (int i = 0; i < n / 2; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i][j - m / 2] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i - n / 2][j] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i][j + m / 2] = arr[i][j];

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
		int cal;
		cin >> cal;
		switch (cal) {
		case 1:
			first();
			break;
		case 2:
			second();
			break;
		case 3:
			third();
			break;
		case 4:
			fourth();
			break;
		case 5:
			fifth();
			break;
		case 6:
			sixth();
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}