/*
작성자 : 이광민
일시 : 2021.06.23
제목 : 2422 - 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
풀이 : 조합 문제. 
       섞어서 먹으면 안되는 것들의 종류가 M개 있는데 이 M개가 10000개이기 때문에 이 모든것을 항상
	   탐색을 하기에는 너무 오랜 시간이 걸린다. 그렇기 때문에
	   bool chk[a][b] => 값이 true이면 a와 b를 섞으면 안된다.
	   와 같이 정의하여 한번에 탐색하도록 한다.
	   이 외에는 각 값들의 조합을 구하고 
	   총 3개의 아이스크림을 가지고 서로의 관계를 파악하기 위해
	   01, 02
	   10, 12
	   20, 21 
	   의 관계를 파악하여 값 중에 하나라도 true가 있다면 카운트를 증가시키지 않도록 한다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ans = 0;
bool chk[201][201];
int sel[3];

void go(int nxt, int cnt) {
	if (cnt == 3) {
		if (chk[sel[0]][sel[1]] || chk[sel[0]][sel[2]]) return;
		if (chk[sel[1]][sel[0]] || chk[sel[1]][sel[2]]) return;
		if (chk[sel[2]][sel[0]] || chk[sel[2]][sel[1]]) return;
		ans++;
		return;
	}

	for (int i = nxt; i <= n; i++) {
		sel[cnt] = i;
		go(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		chk[a][b] = true;
	}
	go(1, 0);
	cout << ans;
}