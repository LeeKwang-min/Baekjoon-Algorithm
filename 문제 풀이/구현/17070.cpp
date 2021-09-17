/*
작성자 : 이광민
일시 : 2021.06.25
제목 : 17070 - 파이프 옮기기 1
풀이 : 문제에서 각 파이프의 방향에 따라 어떻게 이동이 가능한지 모두 나와있고 그 경우는 
       다 해도 7가지밖에 되지 않는다. 각 경우에 따라 모든 경우를 처리하고 
	   주어진 범위를 벗어나지 않는지와 빈공간이여야 하는곳이 벽이진 않는지 모두 확인하도록 한다.

	   진행 방향이 오른쪽과 대각선 뿐이기 때문에 돌아도는 경우가 없다. 
	   그렇기 때문에 이미 왔던곳을 다시 방문하는 경우에 대해서는 생각할 필요가 없다.

	   범위와 벽만 확인해서 모든 케이스를 확인하고 정답을 추출하면 된다.
*/
#include<iostream>

using namespace std;

int n, ans = 0;
int arr[17][17];

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

void go(int x, int y, int dist) { // x, y, 방향(0=가로, 1=세로, 2=대각선)
	if (x == n && y == n) {
		ans++;
		return;
	}
	
	if (dist == 0) {
		if (y + 1 < n + 1 && arr[x][y + 1] != 1) go(x, y + 1, 0);
		if (x + 1 < n + 1 && y + 1 < n + 1 && arr[x + 1][y + 1] != 1 && arr[x][y + 1] != 1 && arr[x + 1][y] != 1) go(x + 1, y + 1, 2);
	}
	else if (dist == 1) {
		if (x + 1 < n + 1 && arr[x + 1][y] != 1) go(x + 1, y, 1);
		if (x + 1 < n + 1 && y + 1 < n + 1 && arr[x + 1][y + 1] != 1 && arr[x][y + 1] != 1 && arr[x + 1][y] != 1) go(x + 1, y + 1, 2);
	}
	else {
		if (y + 1 < n + 1 && arr[x][y + 1] != 1) go(x, y + 1, 0);
		if (x + 1 < n + 1 && arr[x + 1][y] != 1) go(x + 1, y, 1);
		if (x + 1 < n + 1 && y + 1 < n + 1 && arr[x + 1][y + 1] != 1 && arr[x][y + 1] != 1 && arr[x + 1][y] != 1) go(x + 1, y + 1, 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	go(1, 2, 0);
	cout << ans;
}