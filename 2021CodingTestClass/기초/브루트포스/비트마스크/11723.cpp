/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 집합 - 11723
풀이 : 비트마스크를 사용한 집합의 
       검사, 추가, 삭제, 토글 하는 방법을 구현하는 문제

	   S에 X가 있는지 검사 = S & (1 << X)
	   S에 X를 추가 = S | (1 << X)
	   S에 X를 삭제 = S & ~(1 << X)
	   S의 X를 토글 = S ^ (1 << X)

	   all의 경우 1부터 20까지 모든 비트가 있다는 뜻이기 때문에
	   반복문을 돌면서 모든 비트를 1로 만들어주면 된다 (추가)
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int num = 0;
	while (n--) {
		string s;
		cin >> s;
		if (s == "add") {
			int k;
			cin >> k;
			num = num | (1 << k);
		}
		else if (s == "remove") {
			int k;
			cin >> k;
			num = num & ~(1 << k);
		}
		else if (s == "check") {
			int k;
			cin >> k;
			if (num & (1 << k)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "toggle") {
			int k;
			cin >> k;
			num = num ^ (1 << k);
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++)
				num = num | (1 << i);
		}
		else {
			num = 0;
		}
	}
}