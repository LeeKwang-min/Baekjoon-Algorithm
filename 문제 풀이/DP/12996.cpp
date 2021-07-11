/*
작성자 : 이광민
일시 : 2021.07.06
제목 : 12996 - Acka
풀이 : 문제의 정확학 정의를 파악하는데 더욱 오래 걸린 문제.
       총 3명이서 혼자 부르거나 2명이서 부르거나 3명이서 부르는 각 경우를 정해보면 총 7가지의 경우가 나온다.
	   이 문제에서 "앨범 A, B가 있다고 할 때 이 앨범들에 참여한 사람이 다른 곡이 있다면 두 앨범은 다른 앨범이다" 라고 한다.
	   a, b, c 3명이 있다고 가정할 때
	   1. a가 혼자서 부르는 경우
	   2. b가 혼자서 부르는 경우
	   3. c가 혼자서 부르는 경우
	   4. a, b가 부르는 경우
	   5. a, c가 부르는 경우
	   6. b, c가 부르는 경우
	   7. a, b, c가 부르는 경우
	   총 7가지 경우를 가질 수 있다.

	   7가지 각 경우에 대해 만약 불러야 하는 곡의 개수가 n개라고 할 때
	   각 곡에 대해 모든 경우를 계산할 수 있다.

	   DP[S][a][b][c] = 곡이 S곡 남아 있고 A가 불러야 할 노래가 a개, B가 b개, C가 c개 남았을 때 경우의 수
	   라고 할 수 있다.
	   S개의 곡을 모두 불러야 하기 때문에 S가 0이 되었을 때가 메인이 된다.
	   문제에서 주어진 a, b, c 모두 충족을 해야하기 때문에
	   S, a, b, c 모두 0이 되는 경우만 처리하면 된다.
	   위 7가지 경우를 점화식에 대입하여 처리한 다음 
	   정답을 처리해주면 된다.

	   중복의 발생이 발생하기 때문에 DP를 사용하여 중복을 방지해주고
	   초기값을 -1로 주어 혼동이 생기지 않도록 한다. (초기값의 경우 그렇게 부르지 못한다 라는 0을 가지는 경우도 있기 때문에 -1로 해주어야 한다.)
*/
#include<iostream>
#include<cstring>

using namespace std;

const int mod = 1e9 + 7;
long long dp[51][51][51][51];

int go(int s, int d, int k, int h) {
	if (s == 0) {
		if (d == 0 && k == 0 && h == 0) return 1;
		else return 0;
	}

	if (d < 0 || k < 0 || h < 0) return 0;

	long long &ret = dp[s][d][k][h];
	if (ret != -1) return ret;

	ret = 0;
	ret += go(s - 1, d - 1, k, h);
	ret += go(s - 1, d, k - 1, h);
	ret += go(s - 1, d, k, h - 1);
	ret += go(s - 1, d - 1, k - 1, h);
	ret += go(s - 1, d - 1, k, h - 1);
	ret += go(s - 1, d, k - 1, h - 1);
	ret += go(s - 1, d - 1, k - 1, h - 1);
	ret %= mod;
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int s, d, k, h;
	memset(dp, -1, sizeof(dp));
	cin >> s >> d >> k >> h;
	cout << go(s, d, k, h) << '\n';
}