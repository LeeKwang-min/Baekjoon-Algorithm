/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 사탕 게임 - 3085
풀이 : 2가지로 나누어 생각하면 된다.
       1. 사탕을 바꾸는 과정
	   2. 최대로 이어진 사탕의 개수

	   1의 경우에는 상,하,좌,우 를 모두 볼 필요가 없이 우, 하 만 확인하면 된다.
	   (왼쪽은 그 전의 값에서 확인을 하기 때문에 할 필요가 없다)
	   확인이 끝나고 나면 사탕의 위치를 원래대로 바꿔주어야 한다.

	   2의 경우 1과 마찬가지로 행과 열을 검사하면 된다.
	   다시 말해 상,하,좌,우를 모두 확인할 필요 없이
	   행과 열로 나누어서 확인하면 된다.

	   행으로 N번
	   열로 N번 
	   나누어 확인을 해주고 그 값을 return 하면 된다.

	   max값을 바꿀 때, 만약 41줄의 else에서만 값을 바꿔주었다면
	   for문이 끝나고 나서 cnt가 증가하다가 끝났을수도 있으므로
	   한번 더 max를 비교해주어야 한다. (48줄)

	   아래의 주석으로 있는 코드는 O(n^4) 풀이이다.
	   하지만, 인접한 칸의 사탕을 바꿔주는 것은 결국 최대 길이의 변화는
	   단 3개의 행과 열에 영향을 준다.
	   모든 경우를 확인하는것은 시간낭비라는 뜻이다.
	   이 처럼 3개의 행만 확인하는 경우는 O(n^3)에 처리 가능하다.

	   어떻게 구현해야 할지 막막하다면 각 값을 종이에 그림으로 그려보자
	   (한번에 이해된다)
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<char>> candy;

int check(int a, int b, int c, int d) {
	int ret = 1;
	for (int i = a; i <= c; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}

	for (int i = b; i <= d; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		vector<char> tmp;
		for (int i = 0; i < line.length(); i++)
			tmp.push_back(line[i]);
		candy.push_back(tmp);
	}

	int maxCandy = check(0,0,n-1,n-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(candy[i][j], candy[i][j + 1]);
				maxCandy = max(maxCandy, check(i,j,i,j+1));
				swap(candy[i][j], candy[i][j + 1]);
			}
			if (i + 1 < n) {
				swap(candy[i][j], candy[i + 1][j]);
				maxCandy = max(maxCandy, check(i,j,i+1,j));
				swap(candy[i][j], candy[i + 1][j]);
			}
		}
	}

	cout << maxCandy;
}

/*
int check() {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
	}
	return ret;
}
*/