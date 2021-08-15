/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.30
���� : 16973 - ���簢�� Ż��
Ǯ�� : �⺻���� BFS �������� ���� ��ȭ�� �����̴�.
       ������ BFS ������ �ϳ��� �������� �̵���Ű�� Ȯ���ϴ� ���̿��ٸ�
	   �� ������ �־��� ������ ��� �̵���Ű�� �����̴�.

	   �� �������� �־����� ������ �簢�� ���·� �־�����, �̵��ϴ� ���⿡ ���� Ȯ���ؾ� �ϴ� ���� '�� ��'�� ���Ѵ�.

	   �׷��� ������ BFS�� �̵��ϸ�
	   ���� ���� ���� �ִ��� ������ Ȯ�����ָ� �ȴ�.

	   ������, �̵��ϴ� ��� ��츦 �� Ž������ Ȯ���� �ϰ� �Ǹ� O(n^3)���� n�� ũ�Ⱑ �ִ� 1000�̱� ������ �̴� �ð��ʰ��� �߻��Ѵ�.

	   �־����� ������ �簢���̶�� Ư¡�� ����Ͽ� �� �̵��� ���� �� �پ� ��ȭ�Ǵ� ���鸸 Ȯ�����ָ� �ذ� �����ϴ�.

	   ���� �̵��ϴ� ��� -> x - 1��° �� Ȯ��
	   ���������� �̵��ϴ� ��� -> y + w - 1��° �� Ȯ��
	   �Ʒ��� �̵��ϴ� ��� -> x + h - 1��° �� Ȯ��
	   �������� �̵��ϴ� ��� -> y - 1��° �� Ȯ��

	   �� ��츦 Ȯ���Ͽ� �̵��� �����ϴٸ� ��ǥ�� ť�� �־� Ž���� �����ϸ� �ȴ�.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, h, w;
int Sx, Sy, Fx, Fy;
int arr[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ Sx, Sy });
	chk[Sx][Sy] = true;
	dist[Sx][Sy] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= m + 1) continue;
			if (chk[nx][ny]) continue;
			bool wall = false;
			if (k == 0) {
				for (int j = y; j < y + w; j++)
					if (arr[nx][j] == 1) {
						wall = true;
						break;
					}
			}
			else if (k == 1) {
				if (ny + w - 1 > m) wall = true;
				else {
					for (int i = x; i < x + h; i++)
						if (arr[i][ny + w - 1] == 1) {
							wall = true;
							break;
						}
				}
			}
			else if (k == 2) {
				if (nx + h - 1 > n) wall = true;
				else {
					for (int j = y; j < y + w; j++)
						if (arr[nx + h - 1][j] == 1) {
							wall = true;
							break;
						}
				}
			}
			else {
				for(int i = x; i < x + h; i++)
					if (arr[i][ny] == 1) {
						wall = true;
						break;
					}
			}

			if (wall) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	cin >> h >> w >> Sx >> Sy >> Fx >> Fy;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = -1;

	bfs();
	cout << dist[Fx][Fy];
}