/*
작성자 : 이상수
일시 : 2021.04.14
제목 : 나무 자르기 - 2805
풀이 : 이분탐색을 사용하여 풀이하는 문제
       일반적으로 이분탐색을 사용하며 언제 st와 en 값을 바꿔주어야 하는지 
	   확인하며 작성하면 된다.

	   sum이 m보다 작다 == 더 많이 잘라야 한다 -> mid값을 낮춰야 한다.
	   sum이 m보다 크다 == 더 적게 잘라도 된다 -> mid값을 높여도 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	long long st = 1, en = arr[n - 1];
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if(arr[i] > mid)
				sum += (arr[i] - mid);

		if (sum < m) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << en;
}