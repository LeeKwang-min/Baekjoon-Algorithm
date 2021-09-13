/*
�ۼ��� : �̱���
�Ͻ� : 2021.09.13
���� : ġ�� - 2636
Ǯ�� : BFS�� ����Ͽ� ġ� ��� ��µ� �ɸ��� �ð��� ���ϴ� ����
       ġ� ������ �����ϸ� �ش� ���۰� �ܺ� �Ѹ��� ��� ������ �������� ���� �߿��� �����̿���.
	   ����� ������ ����.
	   �־����� ������ �Ѹ� (0, 0), (0, 1), ... �� �׻� ��ĭ���� ġ� ���� �� ���ٴ� ������ ����ϸ� �����ϰ� �ذ��� �����ϴ�.
	   (0,0)�� �׻� ��ĭ�̱� ������ �ش� ��ǥ�� �־� �Ѹ��� ���� ���ϸ� �ȴ�.
	   1. �Ѹ� (�ܺ� ����) ������ ã�´� -> air[x][y]���� 0�̶�� �ܺ� ����, -1�̶�� ġ�� Ȥ�� ����
	   2. ġ� �ִ°��� Ȯ���ϸ� ��, ��, ��, ���� air ���� 0�̶�� �ش� ġ� ���δ�.
	   3. ġ� ���� �� ġ���� ������ ���ϰ� ���� �ð��� �ش��ϴ� ��� ġ� �쿴�ٸ� �ð��� ������Ų��.
	   4. �� ������ �ݺ��Ѵ�.

	   �־��� ������ �� ã�ƺ��� �� ������ �� �̿�����.
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101];
bool chk[101][101];
int air[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
int sec = 0;
int ans = 0;
int cnt = 0;

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			chk[i][j] = false;
			air[i][j] = -1;
		}
			
}

void bfs(int x, int y) {
	init();
	queue<pair<int, int>> q;
	q.push({ x, y });
	chk[x][y] = true;
	air[x][y] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cx = cur.first;
		int cy = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] == 1) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			air[nx][ny] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) cnt++;
		}
	}

	while (cnt > 0) {
		bfs(0, 0);
		ans = cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (air[nx][ny] == 0) {
							arr[i][j] = 0;
							cnt--;
							break;
						}
					}
				}
			}
		}
		sec++;
	}

	cout << sec << '\n' << ans;
}