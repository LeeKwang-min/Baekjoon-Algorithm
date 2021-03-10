/*
작성자 : 이상수
일시 : 2021.02.18
제목 : N과 M (4) - 15652
풀이 : 비내림차순 (중복을 허용하는 오름차순)
       을 만드는 문제이다.
	   N과 M 문제 2와 3을 합치면 해결 가능한 문제이다.

	   중복을 허용하기 때문에 시작점을 자기 자신으로 하면 된다.
*/
#include<iostream>

using namespace std;

int n, m;
int arr[9];

void bf(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		arr[k] = i;
		bf(k + 1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf(0, 1);
}