/*
작성자 : 이상수
일시 : 2021.03.06
제목 : 경사로 - 14890
풀이 : 구현문제
       
	   구현해야 하는 점
	   1. 인접한 칸의 높이가 다를 때 높이 차이 
	   2. 인접한 칸의 높이가 다를 때 길이가 L인 경사로를 놓을 수 있는지
	   3. 이미 경사로가 놓여진곳은 아닌지

	   이 3가지를 각각 고려한 것이 go함수의 각 부분이다.
	   높이 차이가 1이 넘는지 확인해주고

	   현재칸이 더 높은 경우 와 더 낮은 경우를 비교하여 구현하면 되며

	   지금 검사하는 조건에서 만족하지 못하는 조건이 나온다면 
	   이는 지나갈수없는 길이 된다.
	   왜냐하면, 당장 검사하는 곳은 높이 차이가 나서 경사로 없이는 이동하지 못하는데
	   조건을 만족하지 못하면 경사로를 놓지 못하기 때문이다.

	   각 조건을 만족하는 구현을 해주면 된다.

	   상황 1. p[i] > p[i - 1]
	       ㅁ
	   ㅁ  ㅁ
	   i-1  i

	   상황 2. p[i] < p[i - 1]
	   ㅁ
	   ㅁ  ㅁ
	   i-1  i
*/
#include<iostream>
#include<vector>

using namespace std;

int n, l;
vector<vector<int>> path;
int arr[101][101];

bool go(vector<int> p) {
	vector<bool> chk(n, false);

	for (int i = 1; i < n; i++) {
		if (p[i - 1] != p[i]) {
			int diff = p[i] > p[i - 1] ? p[i] - p[i - 1] : p[i - 1] - p[i];
			if (diff > 1) return false;
		}
		if (p[i] > p[i - 1]) {
			for (int j = 1; j <= l; j++) {
				if (i - j < 0) return false;
				if (p[i - j] != p[i - 1]) return false;
				if (chk[i - j]) return false;
				chk[i - j] = true;
			}

		}
		else if (p[i] < p[i - 1]) {
			for (int j = 0; j < l; j++) {
				if (i + j >= n) return false;
				if (p[i + j] != p[i]) return false;
				if (chk[i + j]) return false;
				chk[i + j] = true;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++)
			tmp.push_back(arr[i][j]);
		path.push_back(tmp);
	}

	for (int j = 0; j < n; j++) {
		vector<int> tmp;
		for (int i = 0; i < n; i++)
			tmp.push_back(arr[i][j]);
		path.push_back(tmp);
	}

	int ans = 0;
	for (int i = 0; i < path.size(); i++) {
		if (go(path[i])) ans++;
	}

	cout << ans;
}