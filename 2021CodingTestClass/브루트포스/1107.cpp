/*
작성자 : 이상수
일시 : 2021.02.16
제목 : 리모컨 - 1107
풀이 : 2가지 관점에서 풀이를 진행 할 수 있다.
       우선 리모컨의 조작 횟수는
	   숫자버튼 조작 횟수 + (+, -)버튼 조작 횟수이다.
	   
	   가장 먼저 현재 번호(100)에서 이동하고자 하는 번호로 
	   +나 -만 눌러서 가는 경우를 초기값으로 둔다.

	   그 다음 2가지 관점으로
	   1. 이동할 채널 C를 정하고 이동 가능한지 확인하여 처리
	   2. 고장나지 않은 버튼으로 이동 가능한 채널 C를 만들어서 처리
	   두 관점의 시간 복잡도는 같으나 2번의 경우 구현이 복잡하기 때문에 1번을 선택

	   처음 내 풀이는 2번의 관점이였으나 브루트포스로 모든 경우의 번호를 만들지 않고
	   바꾸고자 하는 채널의 길이에 맞춰 처리하여 오답이 나왔다.

	   1번으로 처리할 경우 채널이 0번부터 50만번 채널까지 있으므로
	   이 범위의 채널에 가장 적은 횟수로 이동하는 방법은
	   0 ~ 100만 번 사이에 있다.
	   왜 100만번 이냐면 50만1번 에서 50만으로 가는게 더 가까울 수 있기 때문이다.
	   이 말을 다시 하면 0 ~ 50만 ~ 100만 으로 나눠서 볼 수 있다는 뜻이다.
	   그러므로 100만을 최대 범위로 둔다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

bool error[10];

int chk(int num) { // 해당 번호로 이동 가능한지 불가능한지 파악하여 이동 가능하다면 숫자의 길이를 반환
	if (num == 0) {
		if (!error[num]) return 1;
		else return 0;
	}

	int cnt = 0;
	while (num > 0) {
		if (error[num % 10]) return 0;
		cnt++;
		num /= 10;
	}

	return cnt;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	while (m--) {
		int en;
		cin >> en;
		error[en] = true;
	}

	int cur = 0;
	if (n == 100) {
		cout << 0;
		return 0;
	}
	cur = n > 100 ? (n - 100) : (100 - n);

	for (int i = 0; i <= 1000000; i++) {
		int cnt = chk(i);
		if (cnt < 1) continue;
		cnt += n > i ? n - i : i - n;
		cur = min(cur, cnt);
	}
	
	cout << cur;
}