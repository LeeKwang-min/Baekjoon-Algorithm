/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 부분수열의 합 - 1182
풀이 : 기존의 문제와 풀이가 다르다.
       부분 수열의 합은 계속해서 바뀌기 때문에 지금 s와 합이 같다고 하더라도
	   다음 수열로 넘어가다보면 다른 수열로 똑같은 합이 나올수도 있다.

	   그렇기 때문에 탐색을 종료하는 조건은
	   탐색을 주어진 수 끝까지 했을때로 해야 하며
	   끝까지 탐색하면서 s와 합이 같다면 정답을 늘려준다.
	   (이 경우는 합을 유지하면서 다음으로 넘어가는 경우가 있기 때문에 가능하다)

	   모르겠으면 비트마스크 사용하자.
*/
#include<iostream>

using namespace std;

int n, s;
int arr[21];
int ans = 0;

void go(int t, int sum) {
	if (t == n) {
		if (sum == s) ans++;
		return;
	}

	go(t + 1, sum + arr[t]);
	go(t + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	go(0, 0);
	if (s == 0) ans--;
	cout << ans;
}