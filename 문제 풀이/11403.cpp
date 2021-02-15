/*
작성자 : 이상수
일시 : 2021.02.03
제목 : 경로 찾기 - 11403
풀이 : 플로이드 와샬 사용 가능하지 묻는 문제이다. 
       11404와 비슷한 문제인데 11404가 비용까지 물었다면
	   이 문제는 간선이 있는지 없는지만 판단하는 문제였다.
*/
#include <iostream>

using namespace std;

int n;
int line[101][101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			line[i][j] = b;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (line[i][j] == 1) continue;
				if (line[i][k] == 1 && line[k][j] == 1)
					line[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << line[i][j] << ' ';
		}
		cout << '\n';
	}
}