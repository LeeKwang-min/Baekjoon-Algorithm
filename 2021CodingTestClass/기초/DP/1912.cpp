/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 연속합 - 1912
풀이 : 이 전까지의 합을 이용할 것인지 말것인지를 정하면 간단하게 처리가 가능하다.
       
	   현재 숫자와 
	   이전까지의 최대 합 + 현재 숫자를 비교하여
	   더 큰 수를 선택하면 된다.

	   현재부터 시작하는 연속된 수열의 합 VS 이전까지의 최대 합인 연속된 수열의 합에 지금 수를 더한
	   두 값을 비교하여 최대를 넣어주면 된다.

	   D[N] = N번째 수로 끝나는 가장 큰 연속합
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[100001];
int a[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	int ans = -1000 * 100000;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans;
}