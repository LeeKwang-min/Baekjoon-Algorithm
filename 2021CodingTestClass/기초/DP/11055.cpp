/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 가장 큰 증가하는 부분 수열 - 11055
풀이 : 가장 긴 증가하는 부분 수열 문제와 매우 유사하다.
       가장 긴 부분 수열을 찾을 때에는 똑같은 알고리즘에
	   d[i] = max(d[i], d[j] + 1) 이였다.
	   여기서 길이가 아닌 합이기 때문에
	   d[i]에 이때까지의 합을 담아두고
	   d[j] + a[i]로 바꿔주면 간단하게 해결된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1001];
int s[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		s[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				s[i] = max(s[i], s[j] + a[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, s[i]);

	cout << ans;
}