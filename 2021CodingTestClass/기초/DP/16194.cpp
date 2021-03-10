/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 카드 구매하기 2 - 16194
풀이 : D[N] = N개의 카드를 구매하고자 할 때, 지불해야 하는 가장 작은 금액

	   D와 P를 가지고 생각을 하면
	   D[N]은 이미 N개를 구매하기 위해 최소로 지불해야 하는 금액이기 때문에
	   구매 가능한 카드의 개수는 1 ~ N개 까지 가능하므로
	   모든 N에 대해서
	   D[N-1] + P[1]
	   D[N-2] + P[2]
	   ...
	   D[0] + P[N]
	   들을 비교하여 가장 작은 값을 정답으로 넣어주면 된다.

	   즉
	   D[N] = MIN(D[N], D[N-K] + P[K]) 가 된다.
*/
#include<iostream>

using namespace std;

int n;
int d[1001];
int p[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	d[1] = p[1];

	for (int i = 2; i <= n; i++) {
		d[i] = p[i];
		for (int j = i - 1; j > 0; j--) {
			d[i] = d[i] > d[i - j] + p[j] ? d[i - j] + p[j] : d[i];
		}
	}
	cout << d[n];
}