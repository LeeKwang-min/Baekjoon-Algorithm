/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.29
���� : 16958 - �ڷ���Ʈ
Ǯ�� : �÷��̵� �ͼ� �˰����� ����Ͽ� Ǯ�̸� �ϴ� �����̴�.
       �÷��̵� �ͼ� �˰��� �ᱹ�� �θ�Ʈ ���� ������ �ش�ȴ�. ��� ��츦 Ž���غ��� ���� ���� ���� ã�� �����̴�.

	   �ڷ���Ʈ�� ������ ���ÿ� �Ұ����� ���ð� �����ϸ� �־��� �� ��ǥ���� ���� 2���� �迭�� ��Ÿ����.
	   ���� ó���� �� �������� �־��� abs(x1 - x2) + abs(y1 - y2)�� �ڷ���Ʈ�� ������ �� ���ö�� �ڷ���Ʈ �ð��� Ȯ���Ͽ� �� ª�� ���� �������� �Ѵ�.

	   �� ������ ������ �ִ� dist�迭�� �÷��̵� �ͼ� �˰����� ������� �ִ� �ð��� ã�Ƴ���
	   m���� a, b���� dist �迭���� ã�� �� ���� ����ϵ��� �Ѵ�.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, t, m;
bool telpo[1001];
int dist[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> t;
	vector<pair<int, int>> xy(n + 1);
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		if (s == 1) telpo[i] = true;
		xy[i] = { x, y };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int x_dist = xy[i].first > xy[j].first ? xy[i].first - xy[j].first : xy[j].first - xy[i].first;
			int y_dist = xy[i].second > xy[j].second ? xy[i].second - xy[j].second : xy[j].second - xy[i].second;
			int tel = 987654321;
			if (telpo[i] && telpo[j]) tel = t;
			dist[i][j] = (x_dist + y_dist) < tel ? (x_dist + y_dist) : tel;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
}