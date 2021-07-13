/*
작성자 : 이광민
일시 : 2021.07.01
제목 : 16945 - 매직 스퀘어로 변경하기
풀이 : 문제를 정확히 읽고 파악하자...
       주어진 배열을 최소한으로 변경하여 '매직 스퀘어'를 만드는 문제이다.
	   매직 스퀘어의 정의를 정확히 파악하지 않아서 해매었는데,

	   매직 스퀘어란 N X N 크기의 배열에 1 ~ N^2까지의 수가 "하나씩" 있으며 행, 열, 대각선의 수의 합이 모두 같은 배열을 매직 스퀘어라고 한다.
	   수가 하나씩 들어있다는것을 파악하지 않고 풀다가 많은 문제가 생겼고 이를 파악하고 나서
	   순열을 사용하여 풀이 하였다.

	   순열을 처리하기 위해 입력받는 배열과 순열을 위한 배열 모두 1차원 배열을 사용하였다.

	   각 처리에 대해 매직 스퀘어가 맞는지 확인하는 함수와 값의 이동에 대한 최소값을 찾는 함수를 선언하여 정리하였다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int arr[9];
int ch[9];
int ans = 987654321;

int calc() {
	int ret = 0;
	for (int i = 0; i < 9; i++) {
		int diff = arr[i] - ch[i];
		if (diff < 0) diff = -diff;
		ret += diff;
	}
	return ret;
}

bool chk() {
	int sum = ch[0] + ch[1] + ch[2];
	if (sum != (ch[3] + ch[4] + ch[5])) return false;
	if (sum != (ch[6] + ch[7] + ch[8])) return false;
	if (sum != (ch[0] + ch[3] + ch[6])) return false;
	if (sum != (ch[1] + ch[4] + ch[7])) return false;
	if (sum != (ch[2] + ch[5] + ch[8])) return false;
	if (sum != (ch[0] + ch[4] + ch[8])) return false;
	if (sum != (ch[2] + ch[4] + ch[6])) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 9; i++)
			cin >> arr[i];

	for (int i = 0; i < 9; i++)
		ch[i] = i + 1;

	do {
		if (chk()) {
			int cur = calc();
			ans = min(ans, cur);
		}

	} while (next_permutation(ch, ch + 9));

	cout << ans;
}