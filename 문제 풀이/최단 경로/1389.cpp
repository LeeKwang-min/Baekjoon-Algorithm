/*
작성자 : 이상수
일시 : 2021.02.03
제목 : 케빈 베이컨의 6단계 법칙 - 1389
풀이 : 플로이드 알고리즘으로 풀이가 가능하다.
       문제를 이해하는 것이 중요하다.
	   플로이드 문제의 대부분이 최소값을 찾고 그래프 상의 직접적으로 이어지지 않은 것을 찾는 것이다.

	   플로이드 문제를 풀면서 느낀점이 서로 연결되지 않은 부분에 대해서는
	   아주 큰 값(987654321)을 주고 최소값으로 처리 해버리면 따로 조건문을 정하지 않아도 쉽게
	   풀이가 가능하다.

	   굳이 머리 아프게 조건문을 넣지 않고 바로 큰 값으로 초기화 하여 간단하게 처리하자
	   (987654321 + n 과 987654321을 비교하면 987654321이 더 작아서 배열에 들어가기 때문에,
			마지막에 987654321인 부분만 0으로 처리 해주면 된다.)
*/
#include <iostream>

using namespace std;

int n, m;
int budy[101][101];

int main() {
	cin >> n >> m;
	while (m--) {
		int f1, f2;
		cin >> f1 >> f2;
		budy[f1][f2] = 1;
		budy[f2][f1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (budy[i][j] == 0)
				budy[i][j] = 987654321;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (budy[i][j] > budy[i][k] + budy[k][j]) 
					budy[i][j] = budy[i][k] + budy[k][j];
					
			}
		}
	}

	int maxCnt = 987654321;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (budy[i][j] == 987654321) continue;
			sum += budy[i][j];
		}
		if (maxCnt > sum) {
			maxCnt = sum;
			answer = i;
		}
	}

	cout << answer << '\n';
}