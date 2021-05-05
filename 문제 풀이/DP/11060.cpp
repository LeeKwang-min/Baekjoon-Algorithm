/*
작성자 : 이상수
일시 : 2021.05.05
제목 : 점프 점프 - 11060
풀이 : 1차원 배열 안에서 A[i] 이하의 건너뛰기를 통해 A[N]까지 가는 최소 이동 횟수를 찾는 문제
       DP를 이용하여 풀이하면 된다.

	   DP[N] = N번째 위치로 가는데 걸리는 최소 점프 횟수
	   라고 한다면 
	   DP[N] = MIN(DP[n-1] + 1, DP[n-2] + 1, DP[n-3] + 1, ... DP[n - arr[n]]) 으로 볼 수 있다.
	   순차 탐색을 진행하면서 N의 최대는 1000이고 arr[n]의 최대는 100이기 때문에
	   모든 탐색을 진행하여도 100,000으로 충분히 시간안에 해결이 가능하다.

	   조건문의 확인을 잘 하고 생각하자
	   1. if (cnt[i] == -1) continue; -> 처음 반복에서 갈 수 없는 곳을 탐색할 경우 탐색하지 않도록 한다.
	   2. if (cnt[i + j] != -1) continue; -> 이미 탐색을 진행했다는 것은 더 최소의 경우가 있다는 말이기 때문에 탐색을 진행하지 않는다.
*/
#include<iostream>

using namespace std;

int n;
int arr[1001];
int cnt[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[i] = -1;
	}
	cnt[1] = 0;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == -1) continue;
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > n) break;
			if (cnt[i + j] != -1) continue;
			cnt[i + j] = cnt[i] + 1;
		}
	}

	cout << cnt[n];
}