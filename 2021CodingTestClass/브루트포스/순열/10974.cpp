/*
작성자 : 이상수
일시 : 2021.02.22
제목 : 모든 순열 - 10974
풀이 : 순열을 구하는 기본적인 문제
	   prev_permutation 함수를 do{}while()문을 사용하여 구현하면 된다.

	   기본적으로 n이 10일때 까지만 순열을 이용하여 모든 경우를 확인할 수 있다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int a[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i - 1] = i;

	do {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	} while (next_permutation(a, a + n));
}