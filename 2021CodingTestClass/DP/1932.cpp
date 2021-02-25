/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 정수 삼각형 - 1932
풀이 : D[N][K] = N번째 K번째 수를 썼을 때 최대 합
       이라고 두고 생각하면
	   K의 크기에 따라 
	   D[N][K] = MAX(D[N-1][K-1], D[N-1][K]) + P[N][K]
	   가 된다.
	   여기서 
	   D[N-1][K-1]는 K-1 >= 0 일 때만        
	   D[N-1][K]는 K < N 일 때만 시행한다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[501][501];
int p[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> p[i][j];

	d[0][0] = p[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j - 1 >= 0) d[i][j] = max(d[i][j], d[i - 1][j - 1]);
			if (j < i) d[i][j] = max(d[i][j], d[i - 1][j]);
			d[i][j] += p[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[n - 1][i]);
	cout << ans;
}