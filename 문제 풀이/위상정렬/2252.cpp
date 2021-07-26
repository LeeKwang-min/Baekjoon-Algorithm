/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.01
���� : 2252 - �� �����
Ǯ�� : ���������� �����ϱ� ���� ���� ����. �̹� Ǯ���� ������ ������ �����̴�.
       ���������� �����ϸ� �� ����� ���������.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int inDegree[32001];
vector<int> arr[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	vector<int> result;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		result.push_back(x);
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
}