/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16922 - 로마 숫자 만들기
풀이 : 이 문제는 조합을 통해 해결하는 문제이다.
       조합 중에서도 '중복 조합' 을 사용해야 한다.
	   중복 조합 = 1, 2, 3 에서 2개 뽑기 -> 1 1, 1 2, 1 3, 2 3 (즉, 중복은 가능하지만 순서는 상관쓰지 않는 것)

	   중복조합을 구하는 방식을 생각하고 풀이하면 간단하게 해결된다.
	   
	   "조합인지 순열인지, 그리고 중복인지 아닌지 잘 생각하자"
	   "조합은 순서를 신경쓰지 않는 것, 순열은 순서까지 신경쓰는 것"
*/
#include<iostream>

using namespace std;

int n;
int ans = 0;
bool num[1001];
int point[4] = { 1, 5, 10, 50 };

void go(int cnt, int now, int nxt) {
	if (cnt == n) {
		if (!num[now]) {
			num[now] = true;
			ans++;
		}
		return;
	}

	for (int i = nxt; i < 4; i++)
		go(cnt + 1, now + point[i], i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	go(0, 0, 0);
	cout << ans;
}