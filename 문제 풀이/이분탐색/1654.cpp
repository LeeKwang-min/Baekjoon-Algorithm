/*
작성자 : 이상수
일시 : 2021.04.13
제목 : 랜선 자르기 - 1654
풀이 : 이분탐색을 사용하여 탐색 범위를 줄여야 하는 문제
       기존의 이분탐색 => 해당 위치
	   이 문제에서 이분탐색 => 가장 큰 값

	   이 문제를 풀기 위해서는 이분탐색을 진행하면서
	   반복문을 빠져나올때까지 탐색한 다음 마지막 en을 출력해주면 된다.

	   (중복된 원소가 있는 배열에서 이분탐색을 진행할 때)
	   (가장 앞의 위치 => mid < target)
	   (가장 뒤의 위치 => mid <= target)
	   (https://yu5501.tistory.com/80 -> 잘 정리된 블로그)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k >> n;
	vector<long long> arr(k);
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	long long st = 1, en = arr[k - 1];
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++)
			sum += arr[i] / mid;

		if (sum < n) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << en;
}