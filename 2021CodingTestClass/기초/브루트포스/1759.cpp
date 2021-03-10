/*
작성자 : 이상수
일시 : 2021.02.19
제목 : 암호 만들기 - 1759
풀이 : N과 M (2)와 매우 유사한 문제이다.
       N과 M 문제를 풀 때 재귀함수를 통해 풀었기 때문에 
	   똑같이 재귀함수로 풀이한다.

	   조건이 몇가지 있는데
	   주의할 것은 
	   암호는 최소 한 개의 모음, 최소 두 개의 자음으로 구성되어 있다는 것이다.
	   이걸 만족할 때만 암호로 사용 가능하기 때문에

	   chk 함수를 사용하여 이를 만족할 때만 출력해주도록 한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int l, c;
vector<char> pw;
char arr[16];

bool chk(string s) {
	int aeiou = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			aeiou++;
	}
	if (aeiou >= 1 && s.length() - aeiou >= 2) return true;
	else return false;
}
// 경우의 수로 작성한 함수
// 사용 가능한 알파벳의 길이가 26이라면 사용이 불가능하다.
void go(int cnt, int st) {
	if (cnt == l) {
		string tmp = "";
		for (int i = 0; i < l; i++)
			tmp += arr[i];
		if (chk(tmp)) cout << tmp << '\n';
		return;
	}

	for (int i = st; i < pw.size(); i++) {
		arr[cnt] = pw[i];
		go(cnt + 1, i + 1);
	}
}

// 선택을 기준으로 작성한 함수
void go_sel(int cnt, int idx) {
	if (cnt == l) {
		string tmp = "";
		for (int i = 0; i < l; i++)
			tmp += arr[i];
		if (chk(tmp)) cout << tmp << '\n';
		return;
	}

	if (idx >= pw.size()) return; // 이 부분이 필요하다.
	arr[cnt] = pw[idx];
	go_sel(cnt + 1, idx + 1);
	go_sel(cnt, idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;
		pw.push_back(a);
	}
	sort(pw.begin(), pw.end());
	go_sel(0, 0);
}