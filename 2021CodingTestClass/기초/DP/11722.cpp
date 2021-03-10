/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 가장 긴 감소하는 부분 수열 - 11722
풀이 : 가장 긴 증가하는 부분 수열 문제에서
       a[i]와 a[j]를 비교하는 부분의 부등호만 반대로 해주면 된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1001];
int d[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);

	cout << ans;
}