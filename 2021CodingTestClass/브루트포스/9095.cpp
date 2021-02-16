/*
작성자 : 이상수
일시 : 2021.02.16
제목 : 1, 2, 3 더하기 - 9095
풀이 : 1, 2, 3을 사용하여 n을 만드는 것이기 때문에
       1, 2, 3 까지는 직관적으로 구하기 쉽다.

	   그 이후에는 다음과 같이 생각하면 쉽다.
	   4 = 1 + 3, 2 + 2, 3 + 1
	   5 = 1 + 4, 2 + 3, 3 + 2
	   6 = 1 + 5, 2 + 4, 3 + 3
	   
	   즉, 4로 예를들면 
	   3을 만드는 경우의 수에 1을 더하면 4가 되고
	   2를 만드는 경우의 수에 2를 더하면 4가 되고
	   1을 만드는 경우의 수에 3을 더하면 4가 된다.

	   이처럼 이전의 경우의 수에 +1 +2 +3을 하면 각 경우의 수에 해당하며
	   이를 값으로 가지면 된다.
*/
#include<iostream>
#include<vector>

using namespace std;

int plus[4] = { 0,1,2,3 };
int cnt[11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cnt[0] = 0; cnt[1] = 1; cnt[2] = 2; cnt[3] = 4;
	for (int i = 4; i < 11; i++)
		cnt[i] = cnt[i - 3] + cnt[i - 2] + cnt[i - 1];

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << cnt[n] << '\n';
	}
}