/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 일곱 난쟁이 - 2309
풀이 : 주어진 경우의 수가 9로 매우 작기 때문에 브루트 포스를 진행하면 된다.
       7명 키의 합이 100이라는 말은 9명의 합에서 2명을 뺐을 때 100이 되면 그 두명이
	   잘못된 난쟁이라는 뜻이므로
	   모든 난쟁이의 합에서 2중 반복문을 돌아 100이 되는 경우를 찾아 출력해주면 된다.

	   9명중 2명을 찾는 경우이므로 
	   9C2 로 9 * 8 / 2 = 36이다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> height;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int h;
		cin >> h;
		height.push_back(h);
		sum += h;
	}
	sort(height.begin(), height.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << height[k] << '\n';
				}
				return 0;
			}
		}
	}
}