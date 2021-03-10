/*
작성자 : 이상수
일시 : 2021.02.18
제목 : N과 M (1) - 15649
풀이 : 재귀함수를 사용한 순서를 찾는 브루트포스 문제
       재귀함수를 사용하여 깊이(순서)를 따라 진행하며
	   종료조건이 만족되면 출력 해주고 종료하도록 하면 된다.

	   따로 조건이 없이 모든 순서를 나타내면 되는 문제이기 때문에
	   일반적으로 구현하면 된다.
*/
#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool chk[9];

void bf(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		arr[k] = i;
		chk[i] = true;
		bf(k + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf(0);
}