/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 로또 - 6603
풀이 : 기초 강의때 풀었던 것을 다시 한번 풀어본 문제
       풀이가 그때와 동일하기 때문에 생략

	   주석 - next_permutation 사용
	   go - 브루트포스 재귀 조합
	   go2 - 브루트포스 재귀 선택
*/
#include<iostream>

using namespace std;

int arr[14];
int num[7];

void go(int n, int t, int st) {
	if (t == 6) {
		for (int i = 0; i < 6; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < n; i++) {
		num[t] = arr[i];
		go(n, t + 1, i + 1);
	}

}

void go2(int n, int t, int st) {
	if (t == 6) {
		for (int i = 0; i < 6; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	if (st >= n) return;

	num[t] = arr[st];
	go2(n, t + 1, st + 1);
	go2(n, t, st + 1);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		go2(n, 0, 0);
		cout << '\n';
	}
}





/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> num(n + 1);
		for (int i = 0; i < n; i++)
			cin >> num[i];

		vector<int> ans;
		for (int i = 0; i < n - 6; i++)
			ans.push_back(0);

		for (int i = 0; i < 6; i++)
			ans.push_back(1);

		vector<vector<int>> numbers;
		do {
			vector<int> tmp;
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i] == 1) tmp.push_back(num[i]);
			}
			numbers.push_back(tmp);
		} while (next_permutation(ans.begin(), ans.end()));

		sort(numbers.begin(), numbers.end());

		for (int i = 0; i < numbers.size(); i++) {
			for (int j = 0; j < numbers[i].size(); j++)
				cout << numbers[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}
*/