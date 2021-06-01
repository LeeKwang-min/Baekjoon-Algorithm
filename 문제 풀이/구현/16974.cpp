/*
작성자 : 이광민
일시 : 2021.05.28
제목 : 16974 - 레벨 햄버거
풀이 : 난이도가 실버3인것을 보고 재귀적 구현을 통해 문자열 처리를 하면 풀릴 줄 알았다.
       하지만, 이 문제는 재귀적 구현을 문자열로 구분없이 처리해버리면 
	   2^50으로 대략 117년이 걸린다... (추가로 용량도 1000TB가 필요하다고 한다.)

	   그렇기 때문에 단순 재귀 구현이 아닌 추가로 처리가 필요한 구현이다. (주석 처리된 string 함수가 잘못 처리한 예)

	   햄버거를 만드는 방식은
	   번 + (L-1버거) + 패티 + (L-1버거) + 번 이다.
	   D[N] = 레벨 N버거의 총 재료 수
	   P[N] = 레벨 N버거의 패티 수
	   라고 두고
	   go(n, x) 라는 n번째 레벨에서 x개를 먹었을 때 먹는 패티의 개수 라는 함수를 사용할 때

	   다음과 같은 정리가 가능하다
	   go함수의 주 포인트는 x에 달려있다.
	   n이 0이라면 x의 값이 0 또는 1로 구분지어 예외처리가 가능하지만
	   n이 0이 아닌 상수라면 x의 값에 따라 구분지어 진다.

	   "번 + (L-1버거) + 패티 + (L-1버거) + 번" 에서
	   1. 번 ---> (x == 1) ---> 먹는 패티 수 = 0
	   2. 번 + (L-1버거) ---> (1 < x <= D[n-1] + 1) ---> 먹는 패티 수 = go(n-1, x-1)    (이미 1개를 먹었고 n-1단계의 버거에서 패티를 먹으면 되기 때문)
	   3. 번 + (L-1버거) + 패티 ---> (x == D[n-1] + 2) ---> 먹는 패티 수 = P[n-1] + 1
	   4. 번 + (L-1버거) + 패티 + (L-1버거) ---> (D[n-1] + 2 < x <= 2*D[n-1] + 2) ---> 먹는 패티 수 = P[n-1] + 1 + go(n-1, x-2-D[n-1]) (번, n-1재료 수, 패티 를 이미 먹었기 때문)
	   5. 번 + (L-1버거) + 패티 + (L-1버거) + 번 ---> (x == 2*D[n-1] + 3) ---> 먹는 패티 수 = 2*P[n-1] + 1

	   이를 처리하여 long long 타입으로 값을 받아 출력하면 해결된다.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long d[51]; // 총 재료의 수
long long p[51]; // 패티의 수

long long go(int n, long long x) {
	if (n == 0) {
		if (x == 0) return 0;
		else return 1;
	}
	if (x == 1) return 0;
	else if (x > 1 && x <= d[n - 1] + 1) return go(n - 1, x - 1);
	else if (x == 2 + d[n - 1]) return p[n - 1] + 1;
	else if (x > 2 + d[n - 1] && x <= 2 * d[n - 1] + 2) return p[n - 1] + 1 + go(n - 1, x - 2 - d[n - 1]);
	else return 2 * p[n - 1] + 1;
}
/*
string burger(int level) {
	if (level == 0) return "P";
	string cur_burger = "B";
	cur_burger += burger(level - 1);
	cur_burger += "P";
	cur_burger += burger(level - 1);
	cur_burger += "B";
	return cur_burger;
}
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, x;
	cin >> n >> x;
	d[0] = 1;
	for (int i = 1; i <= n; i++)
		d[i] = 2 * d[i - 1] + 3;
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = 2 * p[i - 1] + 1;
	long long ans = go(n, x);
	cout << ans;
}