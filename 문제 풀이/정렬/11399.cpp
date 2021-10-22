/*
작성자 : 이상수
일시 : 2021.01.27
제목 : ATM - 11399
풀이 : 오름차순 정렬 후 가장 빠르게 처리 하는 사람부터 처리하면 된다.
제한사항 : 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> arr) {
	int answer = 0;
	int pre = 0;
	sort(arr.begin(), arr.end());

	for (auto i : arr) {
		pre += i;
		answer += pre;
	}
		

	return answer;
}

int main() {
	vector<int> line;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		line.push_back(a);
	}
	cout << solution(line) << '\n';
}