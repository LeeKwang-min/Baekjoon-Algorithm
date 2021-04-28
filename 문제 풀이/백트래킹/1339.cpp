/*
작성자 : 이상수
일시 : 2021.04.28
제목 : 단어 수학 - 1339
풀이 : 두가지 방법이 존재한다.
       1. 순열
	   2. 다항식 처리

	   내가 푼 방식은 순열 방식이다.
	   (브루트포스 방식인 순열은 시간 제한에 조금 빡빡하게 걸리지만 다항식 방식으로 처리하면 0ms만에도 처리가 가능하다고 한다)

	   우선 주어진 영어 알파벳들을 나누어 어떤 알파벳들이 나왔는가 확인한다.
	   나온 값들을 확인하여 최대 몇개가 있는지 확인하고
	   해당 알파벳들에 최대 숫자인 9부터 감소시켜가며 값을 저장한다.

	   값을 가지고 순열을 만들어가며 최대값을 검사하면 된다.

	   처음 풀이를 하고나서 예제 3번이 정상적인 시간안에 출력되지 않아 고민하다가
	   풀이들과 별반 다른것이 없어서 제출을 하니 통과 되었다 (컴퓨터 사양 문제인것 같다)

	   다항식 처리 방식은 다음과 같다고 한다.
	   ACDEB + GCF = 10000A + 1010C + 100(D + G) + 10E + B + F
	   이를 큰 값을 가지게 되는 값에 9부터 감소시켜가며 적용시키면 되는 그리디로 풀이가 가능하다고 한다.

	   최대 몇개의 알파벳이 있는지와 이를 어떻게 숫자에 매칭할 것인지에 대해 기술하자면

	   1. 최대 몇개의 알파벳이 있는가 -> 내가한 방식도 가능하지만, vector의 erase와 unique를 사용하면 더욱 간단히 처리가 가능하다고 한다.
	   2. 숫자에 매칭 -> 처음에 해쉬 맵을 사용하여 처리하였으나, C++의 문자들은 아스키코드 값에 대칭되어 저장되기 때문에 
	                     이 값들을 256크기의 배열에 m['a'] = 3 으로 저장하면 a에 대응되는 m[97] = 3이 저장된다. 이렇게 처리하면
						 비교적 탐색이 느린 해쉬 맵에 비해 빠르게 처리가 가능하다.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
bool alphabet[26];
vector<vector<char>> words;
char m[256];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<char> word;
		for (int i = 0; i < s.length(); i++) {
			alphabet[s[i] - 'A'] = true;
			word.push_back(s[i]);
		}
		words.push_back(word);
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i]) {
			m[i + 'A'] = cnt;
			cnt++;
		}
	}

	int arr[10];
	int now = 9;
	for (int i = 0; i < cnt; i++) {
		arr[i] = now;
		now--;
	}

	int ans = 0;
	do {
		int totalSum = 0;
		for (int i = 0; i < words.size(); i++) {
			int sum = 0;
			int mul = 1;
			for (int j = words[i].size() - 1; j >= 0; j--) {
				sum += arr[m[words[i][j]]] * mul;
				mul *= 10;
			}
			totalSum += sum;
		}
		if (ans < totalSum) ans = totalSum;
	} while (prev_permutation(arr, arr + cnt));

	cout << ans;
}