/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 연산자 끼워넣기 - 14888
풀이 : 숫자는 변하지 않고 연산자의 순서만 바뀌기 때문에
       연산자의 종류만 정해주고 순열을 구해주면 된다.

	   next_permutation을 사용하여 풀었으며
	   재귀 브루트포스를 통해 풀 수도 있다.
	   (재귀로 하는 방법이 더 빠르다)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[12];
vector<int> oper;
vector<int> ans;

void go(int index, int cur, int plus, int minus, int mul, int div) {
	// index = 현재 계산해야 하는 인덱스	cur = index-1번째까지 계산한 결과
	// plus, minus, mul, div = 각 연산자별 사용 가능한 횟수

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

	vector<int> opernum(4);
	for (int i = 0; i < 4; i++)
		cin >> opernum[i];

	/*
	for (int i = 0; i < opernum.size(); i++) {
		for (int j = 0; j < opernum[i]; j++) {
			oper.push_back(i);
		}
	}

	do {
		int now = arr[0];
		for (int i = 1; i < n; i++) {
			if (oper[i - 1] == 0) {
				now = now + arr[i];
			}
			else if (oper[i - 1] == 1) {
				now = now - arr[i];
			}
			else if (oper[i - 1] == 2) {
				now = now * arr[i];
			}
			else {
				if (now < 0) {
					now *= -1;
					now = now / arr[i];
					now *= -1;
				}
				else {
					now = now / arr[i];
				}
			}
		}
		ans.push_back(now);
	} while (next_permutation(oper.begin(), oper.end()));
	*/

	go(1, arr[0], opernum[0], opernum[1], opernum[2], opernum[3]);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
}