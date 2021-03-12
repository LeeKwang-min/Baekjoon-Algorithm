/*
작성자 : 이상수
일시 : 2021.03.12
제목 : 가르침 - 1062
풀이 : 모든 단어의 시작이 anta이고 끝이 tica 이기 때문에
       무조건적으로 a, n, t, i, c 5가지는 배워야 한다.
	   그렇기 때문에 만약 k가 5보다 작다면 단 하나의 단어도 읽지 못하기 때문에
	   0을 출력 해주고 종료하면 된다.

	   그 외에는 입력으로 주어지는 각 단어들을
	   anta와 tica를 제외한 배울 수 있는 철자 종류를 만들어 빼낸 다음

	   처음 k개에서 5개를 배웠으니 5개를 제외하고 나머지를 계산하도록 한다.
	   여기서 k가 뽑힌 철자의 수보다 크다면 이는 현재 단어의 모든 철자를 배울 수 있다는
	   말이기 때문에 n을 출력해주고 종료하도록 한다.

	   그 다음은 총 배울 수 있는 모든 철자를 
	   0과 1로 이루어진 수열의 조합을 통해 
	   각 단어중 k개를 배웠을 때 익힐 수 있는 가장 큰 단어 수를 골라내면 된다.
*/
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	if (k < 5) {
		cout << 0;
		return 0;
	}

	unordered_map<char, int> hm;
	hm['a'] = 1;
	hm['n'] = 1;
	hm['t'] = 1;
	hm['i'] = 1;
	hm['c'] = 1;
	k = k - 5;

	vector<string> word;
	vector<char> tmp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s = s.substr(4);
		s = s.substr(0, s.length() - 4);
		word.push_back(s);
		for (int j = 0; j < s.length(); j++) {
			if (hm[s[j]] == 0) {
				tmp.push_back(s[j]);
				hm[s[j]] = 1;
			}
		}
	}

	if (tmp.size() < k) {
		cout << n;
		return 0;
	}

	for (int i = 0; i < tmp.size(); i++)
		hm[tmp[i]] = 0;

	vector<int> zo;
	for (int i = 0; i < tmp.size() - k; i++) {
		zo.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		zo.push_back(1);
	}

	int ans = 0;
	do {
		for (int i = 0; i < zo.size(); i++) {
			if (zo[i] == 1) {
				hm[tmp[i]] = 1;
			}
		}

		int cnt = 0;
		for (int i = 0; i < word.size(); i++) {
			bool chk = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (hm[word[i][j]] == 0) {
					chk = false;
					break;
				}
			}
			if (chk) cnt++;
		}
		if (ans < cnt) ans = cnt;

		for (int i = 0; i < zo.size(); i++) {
			if (zo[i] == 1) {
				hm[tmp[i]] = 0;
			}
		}


	} while (next_permutation(zo.begin(), zo.end()));

	cout << ans;
}

