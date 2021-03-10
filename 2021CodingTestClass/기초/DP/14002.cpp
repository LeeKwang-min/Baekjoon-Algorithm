/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 가장 긴 증가하는 부분 수열 4 - 14002
풀이 : 가장 긴 증가하는 부분 수열 문제와 다른 점은 그 수열이 무엇인지도 출력하는 문제이다.
       즉, LIS를 출력하는 문제이다.
	   
	   여러가지 문제가 있겠지만, 내가 푼 방법은
	   다익스트라 알고리즘의 경로찾기와 비슷하게 풀었다.

	   pre[N] = N번째 수를 쓸 때, 해당 수열에서 N번째 수 이전의 값 으로 담아둔다.
	   이 값을 담아두고 나중에 정답 인덱스를 알아내어
	   그 경로를 모두 담고 reverse 해주면 된다.
	   즉, pre[n] = a[n] 앞에 와야 하는 수의 인덱스 
	   역추적 해주면 된다.

	   LIS의 길이 = D[1], ... , D[N]의 최댓값
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int d[1001];
int a[1001];
int pre[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int maxCnt = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && maxCnt < d[j]) {
				maxCnt = d[j];
				pre[i] = j;
			}
		}
		d[i] = maxCnt + 1;
	}

	int ans = 0, idx = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			idx = i;
		}
	}

	vector<int> path;
	while (pre[idx] != 0) {
		path.push_back(idx);
		idx = pre[idx];
	}
	path.push_back(idx);

	cout << ans << '\n';
	reverse(path.begin(), path.end());
	for (auto i : path)
		cout << a[i] << ' ';
}