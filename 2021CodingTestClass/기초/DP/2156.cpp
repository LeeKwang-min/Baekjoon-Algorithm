/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 포도주 시식 - 2156
풀이 : D[N][K] = N번째 잔을 마셨을 때 연속해서 K번 마셨을 경우의 최대값
       이 문제는 점화식을 조금 꼬아서 생각해야 한다.
	   
	   D[N][0] = N번째를 마시지 않음
	   D[N][1] = N번째를 마심 하지만 N-1번째는 마시지 않음
	   D[N][2] = N번째를 마셨고 N-1번째도 마셨음

	   이렇게 처리한 다음 
	   N번째에서 가장 많은 값은 0 1 2 중 최대값이다.

	   이를 1차원 DP로 풀려면
	   0번 연속 마셨다 = A[N]을 마시지 않음 = D[N-1]
	   1번 연속 마셨다 = A[N-1]을 마시지 않았다 = D[N-2] + A[N]
	   2번 연속 마셨다 = A[N-2]를 마시지 않았다 = D[N-3] + A[N-1] + A[N]
	   이 된다.
	   이 3가지의 최대값이 정답이 되고
	   최종적으로 1차원 DP로 풀 수 있다.

	   이친수 문제때와 같이 (1과 01로 보는 경우)
	   2차원을 1차원으로 풀 수 있는것들이 있다.
	   시야를 넓히는게 중요하다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[10001][3];
int p[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	d[1][1] = p[1];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + p[i];
		d[i][2] = d[i - 1][1] + p[i];
	}

	int ans = 0;
	for (int i = 0; i < 3; i++)
		ans = max(ans, d[n][i]);
	cout << ans;
}