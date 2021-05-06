/*
작성자 : 이상수
일시 : 2021.05.07
제목 : 뮤탈리스크 - 12869
풀이 : DP문제
       DP[A][B][C] = SCV의 3대의 체력이 A, B, C일 때 최소 공격 횟수

	   코드 설명
	   dp(n1, n2, n3) => d[n1][n2][n3]의 값을 구하는 함수 
	   재귀적으로 반복하며 값들을 감소시켜가며 최소 값을 찾는 방식이다.

	   예를들어 dp(10, 10, 10)의 경우 d[10][10][10]을 찾는 즉, 정답을 찾는 함수이다.
	   방식은 다음과 같다.
	   d[10][10][10] = min(d[10][10][10], dp(10-9, 10-3, 10-1) + 1)
	   마지막 재귀함수에 +1을 하는 이유는 현재 상태에서 한번의 공격을 하고 나서 다음 공격을 진행하는
	   즉, 어떠한 방식으로 공격력을 적용하였는지는 몰라도 지금 한번의 공격을 하고 다음 SCV의 체력 상태의 최소 공격 횟수를 찾는 방식이다.

	   함수의 진행은 다음과 같다.
	   d[n1][n2][n3]의 최소 값을 찾기 위해 d[tn1][tn2][tn3]를 찾고
	   d[tn1][tn2][tn3]를 찾아서 return하여 +1 한 값을 넣어주는 방식이다.

	   즉 기존의 작은 기준에서 높은 기준으로 쌓아 올라가는 방식이 아니라
	   높은 기준에서 작은 기준으로 내려가는 방식을 사용한다.
	   
	   함수의 시작부분에서 체력이 끝난(음수인) 경우를 다 체크하기 때문에 
	   이미 값이 존재하거나 체력이 모두 없는 경우 바로 return한다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int nrr[3];
int d[61][61][61];

int dx[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9} };

int dp(int n1, int n2, int n3) {
	if (n1 < 0) return dp(0, n2, n3);
	if (n2 < 0) return dp(n1, 0, n3);
	if (n3 < 0) return dp(n1, n2, 0);

	if (d[n1][n2][n3] != 0) return d[n1][n2][n3];
	if (n1 == 0 && n2 == 0 && n3 == 0) return 0;

	d[n1][n2][n3] = 987654321;
	for (int i = 0; i < 6; i++) {
		int tn1 = n1 - dx[i][0];
		int tn2 = n2 - dx[i][1];
		int tn3 = n3 - dx[i][2];

		d[n1][n2][n3] = min(d[n1][n2][n3], dp(tn1, tn2, tn3) + 1);
	}

	return d[n1][n2][n3];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nrr[i];

	cout << dp(nrr[0], nrr[1], nrr[2]);
}