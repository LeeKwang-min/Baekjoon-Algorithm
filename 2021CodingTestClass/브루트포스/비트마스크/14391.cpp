/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 종이 조각 - 14391
풀이 : 2차원 배열에 들어가는 값들을 1차원 개념으로 바꾸어 비트마스크를 적용하는 문제이다.
       무조건 종이를 길게 자르는 것이 답이 아니다. (반례가 존재한다)

	   그렇기 때문에 무조건 모든 경우를 해보아야 한다.

	   우서 최대 4 X 4 크기의 종이이기 때문에 
	   최대 길이 16비트를 확인하면 된다.

	   각 경우에 대해 비트마스크를 진행하면 되는데
	   비트가 0인 것은 가로
	   비틑가 1인 것은 세로
	   방향으로 각각 자르는 것들이다.
	   자르는 방법을 모두 다르게 하기 때문에 이 경우에서는 가장 길게 이으면 된다.

	   우선 가로는 행을 기준으로 하기 때문에 n
	        세로는 열을 기준으로 하기 때문에 m
	   을 각각 처리하면 된다.

	   자릿수를 늘려가야 하기 때문에 
	   cur = 0;
	   cur = cur * 10 + number 
	   를 반복문을 통해 진행하면 된다.

	   이 값들을 늘려가다가 방향이 다른 값이 나오면 sum에 값을 더해주고 cur은 0으로 돌려준다.
	   (마지막에 온전히 한쪽 방향으로만 자르다가 끝난 경우가 있을 수 있으므로 한번 더 더해준다)
	   
	   그리고 나서 현재 정답과 비교하여 값이 크면 정답을 바꿔준다.
*/
#include<iostream>
#include<string>

using namespace std;

int n, m;
int arr[4][4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	int maxSum = 0;
	for (int k = 0; k < (1 << (n * m)); k++) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int cur = 0;
			for (int j = 0; j < m; j++) {
				if ((k & (1 << (i * m + j))) == 0) {
					cur = cur * 10 + arr[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int i = 0; i < m; i++) {
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if ((k & (1 << (j * m + i))) != 0) {
					cur = cur * 10 + arr[j][i];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		if (maxSum < sum) maxSum = sum;
	}
	cout << maxSum;
}