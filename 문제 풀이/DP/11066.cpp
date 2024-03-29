/*
작성자 : 이광민
일시 : 2021.06.11
제목 : 11066 - 파일 합치기
풀이 : 정말 어렵다... 도저히 못 풀거 같아서 해답보고 거의 따라 쳤다...

       이제 이해를 해보자

	   DP[i][j] = 파일 i부터 j까지 합쳤을 때 최소 비용
	   '연속'된 파일을 '2개씩'합쳐서 최종 파일로 만든다.
	   이 말은 범위를 나눠서 보면 된다는 말이다.

	   A1 A2 A3 A4 A5 라는 파일 5개가 있을 때
	   이를 합쳐서 최종 파일로 만들었다면
	   (A1 A2 A3 A4 A5) 가 있을 것이며 이 전의 상태는 총 4가지가 생긴다
	   1. (A1) (A2 A3 A4 A5)
	   2. (A1 A2) (A3 A4 A5)
	   3. (A1 A2 A3) (A4 A5)
	   4. (A1 A2 A3 A4) (A5)

	   즉, i부터 j까지 있다고 할 때
	   (i, k) + (k+1, j)가 된다는 것이다.
	   ====================================== 여기까지는 이해 완료 =======================================

	   그렇다면
	   DP[i][j] = DP[i][k] + DP[k+1][j]가 되며 추가로 'A[i] ~ A[j] 까지의 구간합' 이 필요하다고 한다 (이 부분을 이해하지 못함)

	   최종적으로 점화식은 다음과 같다.
		DP[i][j] = DP[i][k] + DP[k+1][j] + 'A[i] ~ A[j] 까지의 구간합'

		구간합을 더하는 이유는 파일의 비용이 파일의 크기와 같으며 i부터 j까지의 합은 파일의 크기 합이기 때문이라고 한다.

		정확하게는 이해하지 못했다. 

		
		=====================================================================================================

		구간 합을 더하는 이유는 다음과 같다.
		우선 Bottom-Up 방식을 생각할 때 아래부터 차곡차곡 값이 쌓이게 된다.
		이 때, 베이스를 생각해보면
		D[a][a]는 자기 자신이 그대로 값이 된다.
		즉, 동적 배열의 값에는 그때그때 자신이 합치는데 필요한 값들의 합을 가지고 가게 되는것이고

		이를 다시 말하면
		40 30 30 50 에서
		(40) (30 30 50) 을 합친다고 하면 이는 범위가 1~4가 되고
		점화식으로 나타낼 때 구간합은
		1 ~ 4의 합이 되어 150이 된다. (어떻게 합했는지를 보는게 아니라 마지막 단계에서 1~4 파일을 합칠때 필요한 데이터 값이다)
		
		정말 어려웠다...
		점화식이 깔끔하게 나오지 않으면 특정 값에서의 최소, 최대 비용이 아니라
		'구간'으로 나타낼 수도 있다는것을 기억하자.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int d[501][501];
int a[501];

int go(int i, int j) {
	if (i == j) return 0;

	if (d[i][j] != -1) return d[i][j];

	int &ans = d[i][j];
	
	int sum = 0;
	for (int k = i; k <= j; k++)
		sum += a[k];

	for (int k = i; k < j; k++) {
		int tmp = go(i, k) + go(k + 1, j) + sum;

		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				d[i][j] = -1;

		cout << go(1, n) << '\n';
	}
}