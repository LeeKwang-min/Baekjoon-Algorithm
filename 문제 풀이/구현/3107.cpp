/*
작성자 : 이광민
일시 : 2021.06.10
제목 : 3107 - IPv6
풀이 : 주어진 절차에 따라 처리하면 되는 구현 문제
       자체적으로 처리한 방식과 절차는 다음과 같다.

	   1. 주어진 문자를 :, ::, 문자 로 나누어 split 벡터에 저장한다.
	      C++에는 split 함수가 없기 때문에 구현하였다.
		  (split 함수가 있다고 해도 ::를 처리해주어야 하기 때문에 마찬가지로 후처리가 필요하다)
	   2. split 벡터를 사용하여 ::가 나오기 전(함축되기 전)과 나온 후(함축된 후) 문자의 개수를 센다
	      st_en[0] = ::이 나오기 전 문자의 개수 // st_en[1] = ::이 나온 후 문자의 개수
	   3. 개수를 세며 st 벡터에 :와 ::를 제외한 문자들만 저장한다.
	   4. 2번에서 센 문자 개수들을 기준으로 st_en[0]개 만큼 ans의 앞에서부터 저장 (0, 1, 2, ...)
	   5. 2번에서 센 문자 개수들을 기준으로 st_en[1]개 만큼 ans의 뒤에서부터 저장 (..., 6, 7, 8)
		  (st 크기에 따라 처리해야 하며 그 갯수가 정해져있기 때문에 따로 idx값을 두어 증가시켜가며 처리)
	   6. ans에 저장된 문자들의 길이를 확인하여 길이가 4가 되지 않는다면 부족한 길이만큼 0을 채워 저장된 문자열에 더해준다.
	   7. 출력해주면 끝

	   이 과정을 통해 처리하도록 한다.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	string s = "";
	vector<string> split;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ':') {
			if (s != "") {
				split.push_back(s);
				s = "";
			}

			if (input[i + 1] == ':') {
				split.push_back("::");
				i++;
			}
			else {
				split.push_back(":");
			}
		}
		else {
			s += input[i];
		}
	}
	if (s != "") split.push_back(s);
	
	vector<int> st_en(2, 0);
	vector<string> st;
	int cnt = 0;
	for (string i : split) {
		if (i == ":") continue;
		if (i == "::") cnt++;
		else {
			st_en[cnt]++;
			st.push_back(i);
		}
	}

	vector<string> ans(8, "");
	int idx = 0;
	for (int i = 0; i < st_en[0]; i++) {
		ans[i] = st[idx];
		idx++;
	}
	for (int i = 8 - st_en[1]; i < 8; i++) {
		ans[i] = st[idx];
		idx++;
	}

	for (int i = 0; i < ans.size(); i++) {
		string zero = "";
		for (int j = ans[i].length(); j < 4; j++)
			zero += "0";
		ans[i] = zero + ans[i];
	}

	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << ':';
	}
	cout << ans[ans.size() - 1];
}