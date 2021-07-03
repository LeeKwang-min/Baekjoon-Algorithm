/*
작성자 : 이광민
일시 : 2021.06.30
제목 : 9655 - 돌 게임
풀이 : 조합을 위한 문제라고 해서 조합을 사용해서 풀어보았다(주석 코드)
       하지만, 문제를 풀다보니 N이 짝수라면 무조건 창영이가 이기고
	   홀수라면 무조건 상근이가 이기는 문제였다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n % 2 == 1) cout << "SK";
	else cout << "CY";
}


/*
#include<iostream>
#include<algorithm>

using namespace std;

int n;
bool ans;
bool flag;

void bfs(int cnt, int cur) {
	if (cnt == n) {
		flag = true;
		if (cur % 2 != 0) ans = true;
		else ans = false;
		return;
	}
	if (cnt > n) return;
	if (flag) return;

	bfs(cnt + 3, cur + 1);
	bfs(cnt + 1, cur + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	bfs(0, 0);
	if (ans) cout << "SK";
	else cout << "CY";
}
*/