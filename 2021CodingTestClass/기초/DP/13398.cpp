/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 연속합 2 - 13398
풀이 : 가장 긴 바이토닉 수열 문제와 비슷한 개념으로 풀면 된다.
       어떤 수열이 있을 때 특정 수를 제외했을 때 가장 큰 수라는 것은
	   
	   어떤 수로 끝나는 최대 합과
	   어떤 수에서 시작하는 최대 합 부분
	   두 합이 가장 큰 것을 찾으면 된다.

	   다시 말해 i번째를 지운다고 가정하면

	    i-1   i   i+1
		을 (i-1번째에서 끝나는 최대 합) + (i+1번째에서 시작하는 최대 합)
		의 값이 가장 큰 값을 찾으면 된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int ed[100001];
int sd[100001];
int a[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ed[0] = a[0];
	for (int i = 1; i < n; i++) 
		ed[i] = max(a[i], ed[i - 1] + a[i]);
	
	sd[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		sd[i] = max(a[i], sd[i + 1] + a[i]);

	int ans = 100000 * -1000;
	for (int i = 0; i < n; i++)
		ans = max(ans, ed[i]);

	for (int i = 1; i < n - 1; i++)
		ans = max(ans, ed[i - 1] + sd[i + 1]);

	cout << ans;
}