/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16917 - 양념 반 후라이드 반
풀이 : 브루트포스를 풀 때 너무 조합, 재귀에 연연하지 말자.
       이 문제 또한 처음부터 주어진 경우의 수를 모두 돌면서
	   반반을 시키는 경우, 반반을 n개 시키는 경우로 나누어 볼 수 있다.

	   반반을 2n마리 샀다면
	   양념은 x-n마리가 필요하고
	   후라이드는 y-n마리가 필요하다.

	   반반을 많이 사다보면 양념과 후라이드가 필요 없는 경우가 생기는데 
	   이 경우에는 구매하지 않는다는 것이기 때문에 0을 주도록 처리한다.

	   각 경우에 맞게 가격을 곱하고 더해서 모든 경우를 탐색하며 최소값을 구해주면 된다.

	   "재귀와 조합에 너무 연연하지 말자"
	   "직관적 풀이가 가능한 문제라면 직관적으로 풀자"
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b >> c >> x >> y;
	int ans = 987654321;
	for (int i = 0; i < 100001; i++) {
		int cur = (2 * i * c) + (max(0, (x - i) * a)) + (max(0, (y - i) * b));
		ans = min(ans, cur);
	}

	cout << ans;
}