/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 수들의 합 2 - 2003
풀이 : 투 포인터 문제 
       투 포인터를 구현할 줄 알면 풀 수 있는 문제이다.
*/
#include<iostream>

using namespace std;

int n, s;
int arr[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, en = 0;
	int sum = 0;
	int cnt = 0;
	while (1) {
		if (sum > s) sum -= arr[st++];
		else if (en == n) break;
		else sum += arr[en++];

		if (sum == s) cnt++;
	}

	cout << cnt;
}