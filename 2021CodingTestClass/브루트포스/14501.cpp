/*
작성자 : 이상수
일시 : 2021.02.19
제목 : 퇴사 - 14501
풀이 : DP를 사용해서 풀 수도 있는 문제이지만, 
       강의에서 배우고 있는 부분이 브루트 포스 이기 때문에 브루트포스로 풀었다.

	   문제의 범위도 최대 15일 까지여서 시간제한에 충분하다.

	   go 함수의 종료 조건을 언제 하면 될까 라는 고민과 실패를 한번씩 했는데,
	   이는 선택하지 않은 경우에서 날 수가 1일씩 증가 되기 때문에
	   만약 퇴사를 하는 날짜가 n보다 클때만 그냥 종료 시키면 되고
	   그렇지 않고 날짜가 n과 같아질때가 무조건 오기 때문에
	   같아지는 날짜에서만 ans 비교를 하고 종료시키면 된다.
	   (마찬가지로 브루트 포스를 선택방법으로 구현하는 경우 종료 조건을 이처럼 구현하면 된다)
*/
#include<iostream>

using namespace std;

int t[16];
int p[16];
int ans = 0;
int n;

void go(int idx, int sum) {
	if (idx > n) return;
	if (idx == n) {
		if (ans < sum) ans = sum;
		return;
	}

	go(idx + t[idx], sum + p[idx]); // 선택한 경우
	go(idx + 1, sum); //선택하지 않은 경우
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	go(0, 0); // n+1일날 퇴사 => 0일부터 시작으로 함수를 시작 = idx가 n이 될 때 종료
	cout << ans;
}