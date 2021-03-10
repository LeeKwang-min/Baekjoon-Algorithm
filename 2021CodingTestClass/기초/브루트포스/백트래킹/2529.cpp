/*
작성자 : 이상수
일시 : 2021.02.21
제목 : 부등호 - 2529
풀이 : 최대 10개의 숫자를 10자리에 넣는 방법은
       10! = 3628800 이므로 브루트포스로 충분히 가능하다.

	   내가한 풀이는 브루트포스를 두번이나 돌기 때문에 (최대 최소를 따로 구현하여)
	   만약 범위가 더 커지면 문제가 된다. (아래 주석처리된 코드)

	   이를 해결하기 위해서 한번의 브루트포스 안에 0부터 9까지의 숫자를 체크하는 법을 알면 된다.
	   내가 놓친 부분이 go 함수에서 반복문을 돌 때, 0 ~ n+1까지만 처리를 해버렸는데
	   이렇게 되면 작은 수부터 n개만 보기 때문에 문제가 된다.
	   이를 방지하기 위해 본 코드의 go처럼 0 ~ 10 까지 처리하면 된다.

	   내 코드는 정수형 배열에 값을 넣어두고 값을 가져와서
	   to_string 함수를 매번 사용하는데 이렇게 되면 시간이 더 오래 걸린다.

	   go에 처음부터 빈 문자열을 넘겨주어 문자열을 기준으로 처리하면
	   더 빠르고 간단하게 처리 가능하다.

	   여기서 더 빠르게 처리하고 싶다면,
	   반복문을 돌 때, chk[i]만 true일 때 건너뛰는게 아니라
	   현재 저장되어 있는 마지막 숫자와 이번에 넣을 숫자를 부등호로 미리 비교하여
	   이를 만족할 때만 처리하도록 하면 된다.

	   다시말해 good(char x, char y, char op) 라는 함수가 있을 때,
	   x = 숫자1 y = 숫자2 op = 부등호 일 때 이를 이용하여
	   반복문의 0 ~ 9 까지 숫자를 현재 저장된 숫자들과 비교하여 
	   위 함수가 참일 때만 수를 집어넣고 재귀를 반복하도록 하면 된다.
	   (엄청 빨라진다 198ms -> 12ms   매우 빨라지기 때문에 백트래킹이 있으면 좋다)
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> sign;
bool chk[10];
int num[10];
int num2[10];
int n;
string min_ans = "", max_ans = "";

bool chk_sign() {
	for (int i = 1; i < n + 1; i++) {
		if (sign[i - 1] == '<') {
			if (num[i - 1] > num[i]) return false;
		}
		else {
			if (num[i - 1] < num[i]) return false;
		}
	}
	return true;
}

string ret_str() {
	string tmp = "";
	for (int i = 0; i < n + 1; i++)
		tmp += to_string(num[i]);
	return tmp;
}

void go(int k) {
	if (k == n + 1) {
		if (chk_sign()) {
			string tmp = ret_str();
			if (min_ans == "") min_ans = tmp;
			else {
				if (min_ans > tmp) min_ans = tmp;
			}
			if (max_ans == "") max_ans = tmp;
			else {
				if (max_ans < tmp) max_ans = tmp;
			}
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		num[k] = i;
		go(k + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		sign.push_back(c);
	}

	go(0);
	//go_max(0);
	cout << max_ans << '\n' << min_ans;
}


// 폐기 코드
/*
bool chk_sign2() {
	for (int i = 1; i < n + 1; i++) {
		if (sign[i - 1] == '<') {
			if (num2[i - 1] > num2[i]) return false;
		}
		else {
			if (num2[i - 1] < num2[i]) return false;
		}
	}
	return true;
}

string ret_str2() {
	string tmp = "";
	for (int i = 0; i < n + 1; i++)
		tmp += to_string(num2[i]);
	return tmp;
}




void go(int k) {
	if (k == n + 1) {
		if (chk_sign()) {
			string tmp = ret_str();
			if (min_ans == "") min_ans = tmp;
			else {
				if (min_ans > tmp) min_ans = tmp;
			}
		}
		return;
	}

	for (int i = 0; i < n + 1; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		num[k] = i;
		go(k + 1);
		chk[i] = false;
	}
}



void go_max(int k) {
	if (k == n + 1) {
		if (chk_sign2()) {
			string tmp = ret_str2();
			if (max_ans == "") max_ans = tmp;
			else {
				if (max_ans < tmp) max_ans = tmp;
			}

		}
		return;
	}

	for (int i = 9; i > 9 - n - 1; i--) {
		if (chk[i]) continue;
		chk[i] = true;
		num2[k] = i;
		go_max(k + 1);
		chk[i] = false;
	}
}
*/