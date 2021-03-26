/*
작성자 : 이상수
일시 : 2021.03.26
제목 : 수 정렬하기 4 - 11931
풀이 : 수를 정렬하여 출력하는 간단한 문제
       sort 내부 3번째 옵션
	   greater<int>() : 내림차순 (큰게 앞으로)
	   less<int>() : 오름차순 (작은게 앞으로)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());
	for (int i : arr)
		cout << i << '\n';
}