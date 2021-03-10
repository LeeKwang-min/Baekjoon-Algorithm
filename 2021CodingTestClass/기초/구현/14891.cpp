/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 톱니바퀴 - 14891
풀이 : 구현문제
       문제 자체는 간단하며 구현하는데 있어 생각할 점이 몇가지 있다.

	   톱니바퀴는 모두 한꺼번에 돌아간다는 것이 중요하며
	   이를 위해 chk 배열을 사용했다.
	   chk[n] = 1 -> 시계 방향 / -1 -> 반시계 방향 / 0 -> 회전하지 않음

	   이를 사용하여 [2]와 [6]을 비교하고 ([2] = 우 [6] = 좌)
	   같다면 더이상 돌지 않으므로 그 뒤의 톱니 바퀴에도 영향을 주지 않도록 break
	   다르다면 값을 이 전 chk에 -1을 곱한 값을 넣어주고 반복문을 이어간다.

	   이렇게 돌고나서 시계방향 회전, 반시계방향 회전을 적용시켜주면 된다.

	   구현은 범위가 항상 매우 중요하다 (잘 보자)
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int gear[4][8];
int k;

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
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			gear[i][j] = s[j] - '0';
	}

	cin >> k;
	while (k--) {
		int num, lr;
		cin >> num >> lr;

		int chk[4];
		for (int i = 0; i < 4; i++) chk[i] = 0;

		if (num == 1) {
			chk[0] = lr;
			for (int i = 0; i < 3; i++) {
				if (gear[i][2] == gear[i + 1][6]) break;
				else chk[i + 1] = chk[i] * -1;
			}
		}

		else if (num == 2) {
			chk[1] = lr;
			if (gear[0][2] != gear[1][6]) chk[0] = chk[1] * -1;

			for (int i = 1; i < 3; i++) {
				if (gear[i][2] == gear[i + 1][6]) break;
				else chk[i + 1] = chk[i] * -1;
			}
		}

		else if (num == 3) {
			chk[2] = lr;
			for (int i = 2; i > 0; i--) {
				if (gear[i][6] == gear[i - 1][2]) break;
				else chk[i - 1] = chk[i] * -1;
			}
			
			if (gear[2][2] != gear[3][6]) chk[3] = chk[2] * -1;
		}

		else {
			chk[3] = lr;
			for (int i = 3; i > 0; i--) {
				if (gear[i][6] == gear[i - 1][2]) break;
				else chk[i - 1] = chk[i] * -1;
			}
		}


		for (int i = 0; i < 4; i++) {
			if (chk[i] == 1) turn_right(gear[i]);
			else if (chk[i] == -1) turn_left(gear[i]);
		}
	}

	int ans = 0;
	int point = 1;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) ans += point;
		point *= 2;
	}

	cout << ans;
}



// 확인용 출력 코드
/*
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++)
				cout << gear[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		cout << gear[0][6] << ' ' << gear[0][2] << '|' << gear[1][6] << ' ' << gear[1][2] << '|' << gear[2][6] << ' ' << gear[2][2] << '|' << gear[3][6] << ' ' << gear[3][2] << '\n';
		cout << num << "번째 톱니 선택 ";
		if (lr == 1) cout << "오른쪽으로 회전 \n";
		else cout << "왼쪽으로 회전 \n";
		cout << '\n';
*/