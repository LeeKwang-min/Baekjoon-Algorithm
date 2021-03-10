/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 약수 - 1037
풀이 : 주어지는 수들을 모두 vector에 입력 받은 다음 수를 정렬하고
       정렬된 기준으로 가장 작은 수와 가장 큰 수를 곱하면 그 값이 N이 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> arr;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	cout << arr[0] * arr[arr.size() - 1] << '\n';

}