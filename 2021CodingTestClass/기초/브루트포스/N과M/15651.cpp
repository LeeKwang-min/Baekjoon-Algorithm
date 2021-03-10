/*
작성자 : 이상수
일시 : 2021.02.18
제목 : N과 M (3) - 15651
풀이 : 중복을 허용하는 문제이므로
       기존의 중복을 방지하기 위해 썻던 chk 배열을 사용하지 않고 
	   chk배열과 관련된 코드 부분을 모두 지워주면된다.
*/
#include <iostream>

using namespace std;

int n, m;
int arr[8];

void go(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	go(0);
}