/*
작성자 : 이상수
일시 : 2021.03.26
제목 : 역원소 정렬 - 5648
풀이 : 받는 수가 10^12가 최대이기 때문에 값을 받아서 long long에 저장해야 한다.
       문자열을 입력받아 reverse함수를 통해 해당 문자열을 뒤집고
	   뒤집은 문자열을 stoll을 통해 long long으로 변환하여 벡터에 담아준다.
	   stoll 과정에서 000012 와 같은 값은 자동으로 12가 되기 때문에
	   그냥 정렬을 진행 해주면 된다.

	   값을 저장하고 정렬한 다음 출력해주면 된다.
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> arr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		arr.push_back(stoll(s));
	}

	sort(arr.begin(), arr.end());
	for (auto i : arr)
		cout << i << '\n';
}