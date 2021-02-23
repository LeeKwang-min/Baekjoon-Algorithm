/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 차이를 최대로 - 10819
풀이 : 주어진 수를 정렬하여 첫번째 순열부터 시작하도록 설정하고
       순열을 순회하면서 주어진 조건에 맞는 식이 최대가 되는 값을 찾으면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int num[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	int maxSum = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) 
			sum += (num[i] > num[i + 1] ? num[i] - num[i + 1] : num[i + 1] - num[i]);
		
		if (maxSum < sum) maxSum = sum;

	} while (next_permutation(num, num + n));

	cout << maxSum;
}