/*
작성자 : 이상수
일시 : 2021.02.16
제목 : 날짜 계산 - 1476
풀이 : 1년부터 제한 없이 증가시켜가며 E, S, M 범위에 맞게 변경한다.
       연도를 변경해 가면서 가장 처음 주어진 
	   E, S, M 값과 같아지는 값이 나오면 값을 출력하고 종료한다.

	   시간복잡도는 E, S, M의 조합의 수와 같다
	   이 말은 15 * 28 * 19 = 7980 이므로
	   총 7980번만 반복하면 구해야 하는 연도가 반드시 구해진다.

	   처음 주어진 E, S, M을 -1씩 해주고 구하면 그 값은
	   i%15 = E	  i%28 = S   i%19 = M  으로 구할 수 있다 (답은 +1)
*/
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int e, m, s;
	cin >> e >> s >> m;

	for (int i = 1; ; i++) {
		int ce, cm, cs;
		ce = i % 15 == 0 ? 15 : i % 15;
		cs = i % 28 == 0 ? 28 : i % 28;
		cm = i % 19 == 0 ? 19 : i % 19;

		if (e == ce && s == cs && m == cm) {
			cout << i << '\n';
			break;
		}
	}
}