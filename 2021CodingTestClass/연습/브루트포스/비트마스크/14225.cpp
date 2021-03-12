/*
작성자 : 이상수
일시 : 2021.03.12
제목 : 부분수열의 합 - 14225
풀이 : 예전에는 선택적 재귀함수를 통해 풀었는데
       이번에는 비트마스크를 사용하여 풀이를 하였다.

	   주 방식은 똑같다.
	   하지만, 비트마스크보다는 재귀방식이 더 빠르다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool chk[2000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += s[j];
			}
		}
		chk[sum] = true;
	}

	for (int i = 1; ; i++) {
		if (chk[i] == false) {
			cout << i;
			break;
		}
	}
}