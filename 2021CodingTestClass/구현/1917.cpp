/*
작성자 : 이상수
일시 : 2021.03.07
제목 : 정육면체 전개도 - 1917
풀이 : 정육면체의 전개도는 총 11개 밖에 없다고 한다.
       구현문제이다 보니 이 11개의 전개도를 모두 구해서
	   각 경우에 대해 회전 시키고 대칭 시키는 경우를 만들어서 각 경우가 성공하는지
	   확인하면 되는 문제이다.
	   (강의 참조해서 풀었음 코드 = 강의 코드)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> cubes = {
	{"0010",
	 "1111",
	 "0010"},

	{"0100",
	 "1111",
	 "1000"},

	{"0010",
	 "1111",
	 "0100"},

	{"0001",
	 "1111",
	 "1000"},

	{"0001",
	 "1111",
	 "0100"},

	{"11100",
	 "00111"},

	{"1100",
	 "0111",
	 "0010"},

	{"1100",
	 "0111",
	 "0001"},

	{"0010",
	 "1110",
	 "0011"},

	{"0001",
	 "1111",
	 "0001"},

	{"1100",
	 "0110",
	 "0011"}
};
vector<string> mirror(vector<string> &b) {
	vector<string> ans(b.size());
	for (int i = 0; i < b.size(); i++) {
		string temp(b[i]);
		reverse(temp.begin(), temp.end());
		ans[i] = temp;
	}
	return ans;
}
vector<string> rotate(vector<string> &b) {
	vector<string> ans(b[0].size());
	for (int j = 0; j < b[0].size(); j++) {
		for (int i = (int)b.size() - 1; i >= 0; i--) {
			ans[j] += b[i][j];
		}
	}
	return ans;
}
bool check(vector<vector<int>> &a, vector<string> &b, int x, int y) {
	int n = a.size();
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			int nx = x + i;
			int ny = y + j;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (b[i][j] == '0') {
					if (a[nx][ny] == 1) return false;
				}
				else if (b[i][j] == '1') {
					if (a[nx][ny] == 0) return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int t = 3;
	while (t--) {
		int n = 6;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		bool ans = false;
		for (auto &c : cubes) {
			vector<string> cube(c);
			for (int mir = 0; mir < 2; mir++) {
				for (int rot = 0; rot < 4; rot++) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							ans |= check(a, cube, i, j); // 하나라도 true면 true (유지)
						}
					}
					cube = rotate(cube); // 4번 회전
				}
				cube = mirror(cube); // 2번 대칭
			}
		}
		cout << (ans ? "yes" : "no") << '\n';
	}
	return 0;
}