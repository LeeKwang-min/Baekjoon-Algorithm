/*
작성자 : 이광민
일시 : 2021.07.03
제목 : 16953 - A → B
풀이 : 간단한 재귀적 브루트 포스 문제
       적용 가능한 2가지 연산 모두 현재 수를 크게 만드는 수밖에 없기 때문에
	   재귀를 진행하면서 현재 수가 B보다 커졌다면 무조건 return 시켜주면 된다.

	   주의할 점.
	   A와 B가 최대 10^9 여서 int를 선언하면 될 것 같지만, 그렇지 않다.
	   곱하기 2 연산의 경우 문제가 되지 않지만 수의 뒤에 1을 붙이는 연산에서는 문제가 생긴다.
	   만약 9억이라는 수가 있다고 할 때, 1을 붙이는 연산을 진행하면 91억이 된다. (int의 범위를 벗어나게 된다)
	   그렇기 때문에 int로 선언하면 정상적인 정답을 받지 못하고 long long 형식으로 선언해주어야 한다.

	   재귀적 방식을 사용하지 않는다면 큐를 사용하여 BFS 처럼 조건을 만족할 때만 값을 넣어주며 진행한다.

	   flag 변수를 사용하기 싫다면 ans 변수를 초기값을 주어 생성한 다음 cur과 B가 같을 때 ans 변수를 변경하고 ans가 초기값과 같다면 -1을 출력해주도록 한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long A, B;
bool flag;
vector<int> tmp;

void go(int cnt, long long cur) {
	if (flag) return;
	if (cur > B) return;
	if (cur == B) {
		cout << cnt + 1;
		flag = true;
		return;
	}

	go(cnt + 1, cur * 2);
	go(cnt + 1, cur * 10 + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> A >> B;
	go(0, A);
	if (!flag) cout << -1;
}