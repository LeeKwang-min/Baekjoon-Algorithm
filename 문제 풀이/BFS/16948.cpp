/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.04
���� : 16948 - ���� ����Ʈ
Ǯ�� : ü�� ���� �̵� ��Ŀ� ���� Ư�� ��ǥ���� �ٸ� ��ǥ���� �̵��� �������� �Ұ������� Ȯ���ϴ� �����̴�.
       �Ϲ������� dx, dy �迭�� �����ϰ� ���� BFS�� �������ָ� �ȴ�.

	   �⺻ dist�� ���� -1�� �θ� �Ŀ� ���� �Ұ����� ��쿡 ���� ���� ó���� ���� �ʿ䰡 ��������.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int dist[201][201];
bool chk[201][201];
int r1, c1, r2, c2;

int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = -1;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ r1, c1 });
	chk[r1][c1] = true;
	dist[r1][c1] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	init();
	bfs();
	cout << dist[r2][c2];
}