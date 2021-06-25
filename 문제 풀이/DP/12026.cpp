/*
작성자 : 이광민
일시 : 2021.06.23
제목 : 12026 - BOJ 거리
풀이 : D[N] = N번째 블럭으로 가는데 드는 최소 비용
       현재 블럭으로 올 수 있는 방법은 이 전의 블럭의 적힌 알파벳이 알맞을때 이루어진다.

	   그렇기 때문에 항상 이동이 불가능하며
	   현재 블럭을 A[i] 이동하고자 하는 블럭을 A[j]라고 할 때
	   A[i] + 1의 값이 A[j]여야 이동이 가능하다 (B = 0, O = 1, J = 2 저장) (2 -> 0 은 %3을 통해 처리)
	   이 조건을 만족할 때 현재 저장된 값이 없다면
	   이동하고자 하는 값 (이동 하는데 드는 비용 + 현재까지 든 비용) 을 저장하고
	   저장된 값이 있다면 그 값과 새로운 값을 비교하여 더 작은 값을 가져가도록 한다.

	   정답이 없는 경우를 처리하기 위해 모든 D 배열의 값을 -1로 처리해 둔다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[1001];
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'B') arr[i] = 0;
		else if (c == 'O') arr[i] = 1;
		else arr[i] = 2;
	}

	for (int i = 0; i <= n; i++)
		d[i] = -1;
	d[1] = 0;

	for (int i = 1; i <= n; i++) {
		if (d[i] == -1) continue;
		for (int j = i; j <= n; j++) {
			if (arr[j] == (arr[i] + 1) % 3) {
				if (d[j] == -1) d[j] = (j - i) * (j - i) + d[i];
				else d[j] = min(d[j], (j - i) * (j - i) + d[i]);
			}
		}
	}

	cout << d[n];
}