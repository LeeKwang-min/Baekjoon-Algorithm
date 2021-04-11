/*
작성자 : 이상수
일시 : 2021.04.11
제목 : 보물 - 1026
풀이 : 가장 낮은수 * 가장 높은 수로 곱해서 합을 더하면 가장 작은 수가 나온다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];

	cout << sum;
}