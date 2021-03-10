/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 소수의 연속합 - 1644
풀이 : 에라토스테네스의 체를 사용하여 빠른 소수를 찾아 
       소수들을 벡터에 담아두고 그 벡터를 사용하여
	   투 포인터를 구현하면 되는 문제이다.

	   이 문제에서 최대값으로 주어지는 정수는
	   400만인데, 에라토스테네스의 체에서 
	   j의 시작값을 i * i를 하게 되면 범위가 너무 커지게 되서 문제가 생긴다.
	   조금 비효율적이더라도 j의 시작값을 i * 2로 두자 (큰 차이는 없다 그냥 이렇게 두자)
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	vector<bool> prime(n + 1);
	vector<int> arr;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) continue;
		arr.push_back(i);
		for (int j = i * 2; j <= n; j += i) {
			prime[j] = true;
		}
	}

	int st = 0, en = 0;
	long long sum = 0, cnt = 0;
	while (1) {
		if (sum > n) sum -= arr[st++];
		else if (en == arr.size()) break;
		else sum += arr[en++];

		if (sum == n) cnt++;
	}

	cout << cnt;
}