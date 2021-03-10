/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 부분수열의 합 - 14225
풀이 : 모든 부분수열을 돌면서 나오는 값들을 chk 배열의 인덱스로 보고 true로 바꿔주고
       마지막 탐색에서 chk[i]가 false인 값이 나오면 출력해주고 종료한다.
	   (범위 : 1 ~ 2000001) (200만인 이유 -> n최대 = 20, arr[n] 최대 = 100000)
*/
#include<iostream>

using namespace std;

int n;
int arr[21];
bool chk[2000001];

void go(int i, int sum) {
	if (i == n) {
		chk[sum] = true;
		return;
	}

	go(i + 1, sum + arr[i]);
	go(i + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	go(0, 0);
	for (int i = 1; ; i++) {
		if (chk[i] == false) {
			cout << i;
			break;
		}
	}
}