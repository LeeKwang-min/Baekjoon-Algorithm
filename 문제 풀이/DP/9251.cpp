/*
작성자 : 이광민
일시 : 2021.06.08
제목 : 9251 - LCS
풀이 : LCS (Logest Common Subsequence) 문제이다.
	   LCS는 크게 2가지가 있는디 마지막 S가 'Subsequence'이냐 'Substring'이냐로 나뉜다.
	   이 문제는 연속하지 않는 부분 문자열을 구하는 문제이다.
	   (Subsequence : 연속하지 않는 부분 문자열 구하기)
	   (Substring : 연속하는 부분 문자열 구하기) ---> 5582번 문제 확인

	   LCS는 유명하기도 하고 대부분의 문자열 문제가 이 알고리즘에서 바뀌어 나오는 경우가 많다고 한다.
	   DP[n][m] = 문자열 A의 n번째, B의 m번째 문자를 사용하였을 때 LCS의 길이

	   위 점화식을 가지고 처리를 할 때 2가지 경우로 나뉜다.
	   1. A[i]와 B[j]가 같을 때
	   2. A[i]와 B[j]가 같지 않을 때

	   두 문자가 같다면 이는 부분 문자열의 일부가 되기 때문에
	   ㅁㅁㅁㅁ i
	   ㅁㅁㅁㅁ j 에서 
	   A[i]와 B[j]의 이전 즉 A[i-1]과 B[j-1]까지의 LCS를 가지고 있는 DP[i-1][j-1] 값에서 +1을 해주면 된다.

	   하지만, 두 문자가 같지 않다면 몇가지를 생각해보아야 한다.
	   A의 i번째를 사용한 경우와 B의 j번째를 사용한 경우로 나뉘게 된다.
	   1. A[i]를 포함한 LCS가 가능할 것이고
	   2. B[j]를 포함한 LCS가 가능할 것이다.

	   1번의 경우 A[i]를 포함하게 되면 B는 B[j-1]까지의 문자열이 될 것이며
	   2번의 경우 B[j]를 포함하게 되면 A는 A[i-1]까지의 문자열이 될 것이다.

	   이를 다시 표현하면
	   DP[i][j-1]과 DP[i-1][j]를 비교하게 되는 것이다. 이 중에서 가장 긴 것을 골라야 하기 때문에
	   두 값중 큰 값을 고르면 된다.

	   ㅁㅁㅁ ㅁ  i
	   ㅁㅁㅁ j-1

	   ㅁㅁㅁ i-1
	   ㅁㅁㅁ ㅁ  j


	   ※ 추가 : 같지 않은 경우는 공백을 넣어 확인하는 것과 같다.
	   D[i-1][j]나 D[i][j-1]에 공백을 채워넣어 그 값을 그대로 가져오는것과 같다.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int d[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
}