/*
작성자 : 이상수
일시 : 2021.02.16
제목 : 카잉 달력 - 6064
풀이 : 문제의 제한이 각 4만씩으로 모든 경우의 수를 검사하면 16억으로 시간 초과가 생긴다.
       이전의 달력 문제와 비슷한 개념이지만, 조금 다르게 생각하면
	   일정 주기마다 1로 바뀌는 특성을 가지는 달력이기 때문에
	   특정 수는 일정하게 나오게 된다.
	   이 원리를 이용하여 모든 M, N을 보는게 아니라
	   M은 고정해두고 N만 보는 방식이다.

	   예를들어 M N x y가 10 12 3 9라면
	   3년 13년 23년 33년 ... 순서로 모두 x는 3이 되기 때문에
	   3부터 시작하여 M을 더해가는 년도만 확인해주면 된다.

	   이를 반복하는 횟수는 M*N과 같은데 그 이유는
	   위 예에서 M*N을 해주면 x와 y는 10 12가 되고
	   그 다음해는 1 1이 되어 다시 처음으로 돌아가기 때문이다.

	   만약 이 안에 정답이 나오지 않는다면 이는 해당하는 년도가 없다는 뜻이다.
*/
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		bool chk = true;
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		for (int i = x; i <= m * n; i+=m) {
			int ny = i % n == 0 ? n : i % n;
			if (ny == y) {
				cout << i << '\n';
				chk = false;
				break;
			}
		}
		if (chk) cout << -1 << '\n';
	}
}