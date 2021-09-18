/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.08
���� : 17086 - �Ʊ� ��� 2
Ǯ�� : ������ ��Ȯ�� Ȯ���ϰ� ��������
       ���� ����� ���� �Ÿ��� �����Ÿ���� �����Ͽ� �ظ� ����
	   �� ������ ���� �Ÿ��� �ƴ�
	   '��ĭ'���� '���� ����� ���' ������ �Ÿ��� �������� �䱸�ϴ� �����Ÿ��� �ȴ�.

	   ��, ��ĭ�鿡�� �����Ͽ� ��� �������� �Ÿ��� ���ϰ� �� �� ���� ���� ���� ���� ����
	   �� �� �߿��� ���� ū ���� �����ָ� ������ �ȴ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[51][51];
bool chk[51][51];
int dist[51][51];
vector<pair<int, int>> xy;

int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };

void bfs(int curx, int cury) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 0;
			chk[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	q.push({ curx, cury });
	chk[curx][cury] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny });
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

void show() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				xy.push_back({ i, j });
		}
	sort(xy.begin(), xy.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				int min_ans = 987654321;
				for (int k = 0; k < xy.size(); k++) {
					int diff = dist[xy[k].first][xy[k].second];
					if (min_ans > diff) min_ans = diff;
				}
				if (min_ans != 987654321 && min_ans > ans) ans = min_ans;
			}
		}
	}
	cout << ans;
}