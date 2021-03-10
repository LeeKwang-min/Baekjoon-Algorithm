/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 부분수열의합 - 1182
풀이 : 이 문제는 비트마스크와 재귀를 사용하여 풀이가가능하다.
       
	   비트마스크를 사용한 부분집합을 구하는 것은 매우 유용하니 알아두는것이 좋다
	   (나중에 DP 문제를 풀 때 자주 쓰인다)

	   단 크기가 양수인 (= 공집합은 제외) 집합만 확인하기 때문에
	   i를 1부터 시작하도록 한다.

	   재귀로 푸는 경우는
	   늘상 들어가는 if(k==n) 이 사라지고
	   if(k >= n) 이면 return; 하도록 하면 된다.

	   이 문제는 수가 선택이 되냐 안되냐를 정하는 문제이기 때문에
	   선택을 하는 재귀함수를 구현하면 된다.
	   재귀함수를 돌면서 sum의 값이 s와 같을 때 값을 증가시켜주고 계속 하면 된다.
	   (return이 아닌 이유는 추가적으로 값을 더하고 빼가면서 다시 똑같아질 수 있기 때문에
			끝까지 가봐야 알 수 있다.)
*/
#include<iostream>

using namespace std;

int arr[21];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i &(1 << j)) sum += arr[j];
		}
		if (sum == s) ans++;
	}

	cout << ans;
}