/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 연산자 끼워넣기 (2) - 15658
풀이 : 연산자 끼워넣기 기존 문제에서 연산자가 딱 맞게 주어지는게 아니라
       N-1개 보다 많은 개수가 주어질 수도 있는 문제이다.

	   연산자 끼워넣기 기존 문제와 크게 다른점은 없으며
	   재귀를 사용할 경우 코드 자체는 똑같다.

	   만약 순열을 이용할경우 0과 1을 이용하여
	   포함되어있는지 아닌지 확인한 다음 
	   그 연산자를 사용하고 계산하면 된다.
	   ( 0 0 0 0 1 1 1 1 2 2 2 2 3 3 3 3) -> (0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1)
	   (사용하여 1이 포함된 곳의 연산자 사용)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[12];
vector<int> ans;

void go(int index, int cur, int plus, int minus, int mul, int div) {
	if (index == n) {
		ans.push_back(cur);
		return;
	}

	if (plus > 0) go(index + 1, cur + arr[index], plus - 1, minus, mul, div);
	if (minus > 0) go(index + 1, cur - arr[index], plus, minus - 1, mul, div);
	if (mul > 0) go(index + 1, cur * arr[index], plus, minus, mul - 1, div);
	if (div > 0) go(index + 1, cur / arr[index], plus, minus, mul, div - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int oper[4] = {};
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	go(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
}