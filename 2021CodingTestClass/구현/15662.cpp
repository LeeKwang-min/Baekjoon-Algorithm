/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 톱니바퀴 (2) - 15662
풀이 : 톱니바퀴 문제와 유사한데 톱니바퀴의 수가 가변적이다.
       최대 1000개 까지 주어지며 이 경우는 해당 톱니바퀴보다 
	   작은번호, 큰번호로 나누어 주면 간단하게 해결된다.

	   (톱니바퀴 1번 문제에서도 이렇게 풀면 되었다)
	   4가 n으로 바뀌고
	   선택된 톱니바퀴보다 1작은 톱니번호 부터 선택된 톱니바퀴와 작아지며 비교하고
	   선택된 톱니바퀴보다 1 큰 톱니번호 부터 선택된 톱니바퀴와 커지며 비교하면 된다.
	   (작아지며 -> num-1 ~ 1)
	   (커지며 -> num-1 ~ n-1)
	   
	   이 후에는 톱니바퀴 1번 문제와 똑같다.
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int gear[1001][8];
int n, k;

void turn_right(int arr[]) {
	int tmp = arr[7];
	for (int i = 7; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;
}

void turn_left(int arr[]) {
	int tmp = arr[0];
	for (int i = 0; i < 7; i++)
		arr[i] = arr[i + 1];
	arr[7] = tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			gear[i][j] = s[j] - '0';
	}

	cin >> k;
	while (k--) {
		int num, lr;
		cin >> num >> lr;

		int chk[1001];
		for (int i = 0; i < n; i++) chk[i] = 0;

		chk[num - 1] = lr;
		for (int i = num-1; i > 0; i--) {
			if (gear[i][6] == gear[i - 1][2]) break;
			else chk[i - 1] = chk[i] * -1;
		}
		for (int i = num-1; i < n; i++) {
			if (gear[i][2] == gear[i + 1][6]) break;
			else chk[i + 1] = chk[i] * -1;
		}


		for (int i = 0; i < n; i++) {
			if (chk[i] == 1) turn_right(gear[i]);
			else if (chk[i] == -1) turn_left(gear[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (gear[i][0] == 1) 
			ans++;
	}

	cout << ans;
}
