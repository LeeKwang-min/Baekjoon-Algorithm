/*
작성자 : 이상수
일시 : 2021.02.21
제목 : 맞춰봐
풀이 : 총 21개의 숫자를 최대 10개의 자리에 중복으로 집어 넣을 수 있는 문제이다.
       즉, 총 경우의 수는 21^10 으로 약 16조이다. (브루트 포스 불가)

	   이를 위해 푸는 방법은 다음과 같다.

	   sign[i][j] = num[i]부터 num[j]까지의 합이기 때문에
	   sign[i][i] = num[i]의 부호와 같다 (자기 자신까지의 합이기 때문에)

	   이를 응용하여 
	   chk함수와 같이 k번째 숫자까지 값을 넣었다면
	   [k][k] + [k][k-1] + [k][k-2] + ... 와 같이 진행하면서
	   주어진 누적합과 부호가 서로 다르다면 false를 넘겨 해당 값에는 더이상 
	   재귀를 진행하지 않도록 한다.

	   이와 같이 각 조건에 맞는 경우에만 재귀를 진행하고 (백트래킹)
	   첫번째로 정답이 되는 것이 나온다면 바로 exit(0); 을 호출하여 종료한다.

	   핵심 아이디어
	   1. num[k]의 부호는 sign[k][k]의 부호와 같다.
	   2. 누적합을 돌면서 주어진 부호와 일치하지 않을 경우에는 재귀를 진행할 필요가 없다.
*/
#include<iostream>

using namespace std;

char sign[11][11];
int num[11];
int n;

bool chk(int k) {
	int sum = 0;
	for (int i = k; i >= 0; i--) {
		sum += num[i];
		if (sign[i][k] == '0' && sum != 0) return false;
		if (sign[i][k] == '+' && sum <= 0) return false;
		if (sign[i][k] == '-' && sum >= 0) return false;
	}
	return true;
}

void go(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			cout << num[i] << ' ';
		exit(0);
	}

	for (int i = -10; i < 11; i++) {
		num[k] = i;
		if (chk(k)) go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++) 
			cin >> sign[i][j];

	go(0);
}