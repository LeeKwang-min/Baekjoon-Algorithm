/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 가장 긴 바이토닉 부분 수열 - 11054
풀이 : 바이토닉 수열이 가장 긴 것은
       특정 지점에서 구한
	   LIS의 길이와
	   LDS의 길이를 더한 값이 가장 큰 지점이 그 정답이다.

	   우선 가장 긴 증가하는 부분수열을 구해주고

	   다음으로 가장 긴 감소하는 부분수열을 구하면 된다.

	   단, 기존에 풀었던 방식은
	   D[N] = N번째에서 "끝나는" LIS, LDS 였지만

	   이 문제를 풀기 위해서는 
	   D[N] = N번째에서 "시작하는" LDS를 구해야 한다.

	   왜냐하면 LIS에서 끝나지 않고 다시 감소하는 부분도 있어야 하는데
	   N에서 끝나는 방식의 점화식으로 처리하면 바이토닉 수열을 구할 수 없기 때문이다.

	   이를 위한 아이디어는 다음과 같다
	   기존 1 ~ N 순서로 보던 것과 달리
	   N ~ 1 로 역순으로 확인하는 방식이다.
	   역순으로 확인하며
	   N에서 시작하는 가장 긴 감소 수열 이라는 말은
	   A[N-?] > A[N] 인 부분을 찾아야 한다.

	   N-? 를 i로 두고
	   N - ? + 1 ~ N까지를 j로 둔 다음
	   a[i] > a[j] 인 부분을 찾아 기존과 같이 처리하면 된다.

	   보는 방식을 바꾸어 처리하는 방법이다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int ld[1001];
int sd[1001];
int a[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		ld[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				ld[i] = max(ld[i], ld[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		sd[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				sd[i] = max(sd[i], sd[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, ld[i] + sd[i]);

	cout << ans - 1;
}