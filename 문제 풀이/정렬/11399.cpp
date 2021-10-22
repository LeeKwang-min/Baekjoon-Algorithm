/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.27
���� : ATM - 11399
Ǯ�� : �������� ���� �� ���� ������ ó�� �ϴ� ������� ó���ϸ� �ȴ�.
���ѻ��� : 
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