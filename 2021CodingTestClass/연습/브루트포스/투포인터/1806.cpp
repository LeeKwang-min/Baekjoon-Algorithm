/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 부분합 - 1806
풀이 : 투포인터로 문제를 따라가면 합이 주어진 값 이상이 될 경우에
       그 수열의 길이가 최소인 값을 찾는 문제

	   투포인터 구현을 하면 간단하게 해결이 되며
	   구하지 못한다면 그 값은 초기값인 100001이 나오게 되므로
	   이 경우만 예외처리를 해주면 된다.
*/

#include<iostream>

using namespace std;

int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, en = 0;
	int sum = 0, ans = 100001;
	while (1) {
		if (sum > s) sum -= arr[st++];
		else if (en == n) break;
		else sum += arr[en++];

		if (sum >= s && ans > en - st) {
			ans = en - st;
		}
	}
	if (ans == 100001) ans = 0;
	cout << ans;
}