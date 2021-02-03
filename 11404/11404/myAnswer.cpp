/*
작성자 : 이상수
일시 : 2021.02.03
제목 : 플로이드 - 11404
풀이 : 플로이드 와샬 문제의 구현을 할 줄 아느냐를 묻는 문제
       그래프를 그려서 구현하면 된다.
	   단, 문제에서 주어지는 간선이 하나가 아닐 수 있기 때문에
	   값을 넣어줄 때 해당 간선이 초기값이 아니라면 두 간선 중 비용이 작은 값을 선택하자

	   그 뒤로 간선이 없다면 값을 매우 크게 잡아서 따로 조건문 처리를 하지 않고 처리 되도록 할 수 있다.
	   출력 해 줄때는 조건문으로 0으로 출력 해 주어야 한다.
*/
#include <iostream>

using namespace std;

int arr[101][101];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] != 0) arr[a][b] = arr[a][b] > c ? c : arr[a][b];
		else arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) arr[i][j] = 987654321;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || i == k || k == j) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 987654321)
				cout << 0 << ' ';
			else
				cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}