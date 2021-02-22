/*
작성자 : 이상수
일시 : 2021.02.22
제목 : 이전 순열 - 10973
풀이 : 순열을 구하는 기본적인 문제
	   prev_permutation 함수를 사용하여 구현하였으며
	   직접 함수를 구현한 코드는 Permutation.cpp에 있다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int a[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (prev_permutation(a, a + n)) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else {
		cout << -1;
	}
}