/*
작성자 : 이광민
일시 : 2021.07.08
제목 : 10564 - 팔굽혀펴기
풀이 : 문제의 정의 자체는 금방 풀었고, 점화식을 잘못 세워서 조금 헤맨 문제

       문제에서 말하는것 처럼 
	   총 N번의 팔굽혀펴기를 할 때 최대 점수는 몇 점인가를 알아내야 한다.

	   이를 생각하여 처음 생각한 풀이 방식은
	   "DP[N] = 총 N번의 팔굽혀펴기를 할 때 최대 점수" 로 점화식을 세웠다.
	   이를 바텀 업 방식의 점화식으로 적용시켜
	   DP[i + DP[i] + arr[j]] = max(DP[i + DP[i] + arr[j]], DP[i] + arr[j]) 와 같이 정의하였다.

	   하지만, 현재 확인하고있는 횟수의 최대 점수가 무조건 최고 점수를 가지고 있다고 해서 찾고자 하는 값의 최대 점수를 찾을 수 없었다.
	   그렇기 때문에 각 횟수에서 가능한 모든 점수를 확인하고 가능한 점수 중에서 가장 큰 점수를 출력해주어야 정확한 정답으로 처리된다.


	   이를 반영하여 점화식을 다음과 같이 바꾸었다.
	   DP[count][point] = count번의 팔굽혀 펴기를 할 때 point점을 딸 수 있는가 없는가 (bool 배열)
	   점화식을 바꾸고 나서 바텀 업 방식에서 탑 다운 방식으로 바꾸어 재귀함수를 통해 구현하였다.

	   재귀함수를 진행하는 식은 위에서 정의한 식들과 거의 똑같다.

	   하나 더 실수한 것이 있는데, 바로 점수에 대한 범위를 어디까지 잡아야 하는지이다.
	   처음에 최대 20점까지의 점수가 들어온다고 하여 200으로 설정하였으나 올바른 방법이 아니었고, 
	   횟수가 최대 5000번이기 때문에 이에 맞춰 정의해주어야 한다. 
	   (간단하게 20점을 10번만 획득했다 가정하고 계산해보아도 740번의 팔굽혀펴기에 200점의 점수를 가진다.)
	   (넉넉하게 N과 같은 최대 점수를 주었다)
*/
#include<iostream>
#include<cstring>

using namespace std;

int t, n, m;
bool dp[5001][5001];
int arr[11];

void go(int point, int count) {
	if (count > n) return;
	if (dp[count][point]) return;
	dp[count][point] = true;

	for (int i = 0; i < m; i++)
		go(point + arr[i], count + point + arr[i]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(dp, false, sizeof(dp));

		for (int i = 0; i < m; i++)
			cin >> arr[i];

		go(0, 0);

		int ans = -1;
		for (int i = 0; i <= n; i++)
			if (dp[n][i]) ans = i;

		cout << ans << '\n';
	}
}