/*
작성자 : 이상수
일시 : 2021.03.27
제목 : 접미사 배열 - 11656
풀이 : string의 substr과 algorithm의 sort를 이용하면 간단하게 풀리는 문제
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	vector<string> arr;
	for (int i = 0; i < s.length(); i++) 
		arr.push_back(s.substr(i, s.length()));

	sort(arr.begin(), arr.end());
	for (string i : arr)
		cout << i << '\n';
}