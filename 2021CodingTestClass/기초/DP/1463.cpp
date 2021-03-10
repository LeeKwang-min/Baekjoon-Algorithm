/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 1로 만들기 - 1463
풀이 : 점화식을 말로 표현해 보면
       D[N] = N을 3가지 공식을 이용하여 1로 만드는 최소 횟수
	   
	   처음 접근한 방법은
	   D[N] = max(D[N/3], D[N/2], D[N-1]) 이였으나
	   이는 나누어 떨어질 때만 처리한다는 공식을 어기기도 하고
	   실제로 값을 넣으면서 Bottom-Up 방식으로 확인해보니 틀렸었다.

	   그래서 나누어 떨어질 때만 확인하는 방식을 사용하며
	   다시 확인해보니 맞아서 점화식을 찾을 수 있었다.

	   즉 D[N] = max(D[N/3], D[N/2], D[N-1]) + 1 
	    (단, N이 3으로 나누어 떨어질 때만 N/3 , N이 2로 나누어 떨어질 때만 N/2를 확인)
	   이 최종 점화식이 된다.
*/
#include<iostream>

using namespace std;

int d[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	d[0] = 0; d[1] = 0; d[2] = 1; d[3] = 1;
	for (int i = 4; i <= n; i++) {
		int minCnt = 1e9;
		if (i % 3 == 0 && minCnt > d[i / 3]) minCnt = d[i / 3];
		if (i % 2 == 0 && minCnt > d[i / 2]) minCnt = d[i / 2];
		if (minCnt > d[i - 1]) minCnt = d[i - 1];
		d[i] = minCnt + 1;
	}
	cout << d[n];
}