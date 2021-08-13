/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16968 - 차량 번호판 1
풀이 : 주어지는 문자의 길이에 따라 조합을 생각할 때 조합의 카운트 값이 문자의 길이와 같아지면 종료조건으로 삼는다.
       모든 조합을 모아두고 위에서 말한 조건을 만족할 때 정답이 될 수 있는지를 확인하는 방법도 있지만, 조합으로 들어가는 값들을
	   처음부터 골라 받는 방법을 사용하도록 했다.

	   문자가 d 혹은 c인 2가지 경우 뿐이며 
	   d의 경우 숫자 0 ~ 9 까지의 10가지 경우
	   c의 경우 문자 a ~ z 까지의 26가지 경우이다.
	   이 두가지를 따로 문자로 처리하지 않고 숫자로
	   0 ~ 9 (d) 10 ~ 25 (c) 로 처리하였다.

	   현재 넣는 값을 이 전에 어떤 값이 들어갔는지 확인하여 같은 값이 들어가지 않도록 하여 처리한다.
*/
#include <iostream>
#include <string>

using namespace std;

string s;
int ans = 0;
int sel[4];

void go(int cnt) {
	if (cnt == s.length()) {
		ans++;
		return;
	}

	if (s[cnt] == 'd') {
		for (int i = 0; i < 10; i++) {
			sel[cnt] = i;
			if (cnt > 0 && sel[cnt] == sel[cnt - 1]) continue;
			go(cnt + 1);
		}
	}
	else {
		for (int i = 10; i < 36; i++) {
			sel[cnt] = i;
			if (cnt > 0 && sel[cnt] == sel[cnt - 1]) continue;
			go(cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	go(0);
	cout << ans << '\n';
}