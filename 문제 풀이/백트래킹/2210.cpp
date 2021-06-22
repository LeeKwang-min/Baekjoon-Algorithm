/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 2210 - 숫자판 점프
풀이 : 5 X 5 크기의 판에서 각 점을 시작점으로 하여 모든 점에서 시작점을 두고 가능한 모든 수를 구한다.
       SET 자료구조를 사용하여 값들을 key로 저장하여 최종적으로 set 자료구조의 크기를 출력하도록 한다.

	   범위를 벗어나는 경우를 주의하자 (>=를 >로 써서 한참을 틀렸다...)
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int A[5][5];
int sel[6];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
set<int> V;

int calc() {
	int ret = 0;
	int mul = 100000;
	for (int i = 0; i < 6; i++) {
		ret += sel[i] * mul;
		mul /= 10;
	}
	return ret;
}

void go(int cnt, int x, int y) {
	if (cnt == 6) {
		int num = calc();
		V.insert(num);
		return;
	}
	sel[cnt] = A[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		go(cnt + 1, nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> A[i][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(0, i, j);
		}
	}
	
	cout << V.size() << '\n';
}