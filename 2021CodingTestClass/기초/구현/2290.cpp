/*
작성자 : 이상수
일시 : 2021.03.07
제목 : LCD Test - 2290
풀이 : 구현문제
       각 숫자를 디스플레이에 나타낸다고 할 때
	   각 부분을 숫자로 나타내어 표시되는 순서에 맞춘다.
	   그렇게 하고나면
	   상단 -> 상좌 -> 상우 -> 중단 -> 하좌 -> 하우 -> 하단 순서로 출력됨을 알 수 있다.

	   이에 맞춰 각 숫자가 해당 부분이 표시되는지를 나타내는 num 배열을 사용하여
	   값으로 가지고 있고 
	   표시해야 하는 숫자를 길이s에 맞게 공백과 |, - 를 주어가며 풀이하면 된다.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int s;
	string n;
	cin >> s >> n;

	bool num[10][7] = { {1,1,1,0,1,1,1}, // 0
						{0,0,1,0,0,1,0}, // 1
						{1,0,1,1,1,0,1}, // 2
						{1,0,1,1,0,1,1}, // 3
						{0,1,1,1,0,1,0}, // 4
						{1,1,0,1,0,1,1}, // 5
						{1,1,0,1,1,1,1}, // 6
						{1,0,1,0,0,1,0}, // 7
						{1,1,1,1,1,1,1}, // 8
						{1,1,1,1,0,1,1}  // 9 
	};
	
	vector<int> numbers;
	for (int i = 0; i < n.length(); i++) {
		int num = n[i] - '0';
		numbers.push_back(num);
	}

	// 0번째 (상단 출력)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][0] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';

	// 1, 2번째 (상단 좌, 상단 우 출력)
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < numbers.size(); i++) {
			if (num[numbers[i]][1] == 1) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; k++) cout << ' ';

			if (num[numbers[i]][2] == 1) cout << '|';
			else cout << ' ';

			cout << ' ';
		}
		cout << '\n';
	}

	// 3번째 (중단 출력)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][3] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';

	// 4, 5번째 (하단 좌, 하단 우 출력)
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < numbers.size(); i++) {
			if (num[numbers[i]][4] == 1) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; k++) cout << ' ';

			if (num[numbers[i]][5] == 1) cout << '|';
			else cout << ' ';

			cout << ' ';
		}
		cout << '\n';
	}

	// 6번째 (하단 출력)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][6] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';
}