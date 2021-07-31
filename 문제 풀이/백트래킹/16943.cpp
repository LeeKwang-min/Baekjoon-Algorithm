/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16943 - 숫자 재배치
풀이 : 최대 숫자가 10^9이며 자릴수로 따지면 9자리이다.
       그렇기 때문에 각 숫자들의 모든 순열을 따져보고 결과를 도출해도 충분히 가능한 시간이다.

	   A의 자릿수를 벡터에 역순으로 저장한다.
	   이 벡터로 수열을 만들고 이 값이 B보다 작은지 확인한다.
	   역순으로 저장했기 때문에 1자리수가 인덱스 0에 저장되어 있다. 
	   while문을 통해 값을 처리하면 된다.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int A, B, ans = -1;
int sel[11];
bool chk[11];
vector<int> v;

int num() {
	if (sel[v.size() - 1] == 0) return -1;
	int ret = 0;
	int mul = 1;
	for (int i = 0; i < v.size(); i++) {
		ret += mul * sel[i];
		mul *= 10;
	}
	if (ret < B) return ret;
	return -1;
}

void go(int cnt) {
	if (cnt == v.size()) {
		int cur = num();
		if (cur != -1) ans = max(ans, cur);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (chk[i]) continue;
		chk[i] = true;
		sel[cnt] = v[i];
		go(cnt + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> A >> B;
	int tmpA = A;
	while (tmpA != 0) {
		v.push_back(tmpA % 10);
		tmpA /= 10;
	}
	
	go(0);
	cout << ans;
}