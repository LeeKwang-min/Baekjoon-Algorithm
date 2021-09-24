/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.28
���� : ���̷��� - 2606
Ǯ�� : �׷��� ������ DFS, BFS ���� �س���... �� ��Ծ���...
       �׷��� �ٽ� �����ؼ� 2���� ������� �����ߴ�.

	   ���� �������� DFS�� BFS�̴�.

	   DFS�� ��� ���� ��忡�� �� �� �ִ� �ϳ��� ������ ���Ͽ� �̵��ϸ�
	   BFS�� ��� ���� ��忡�� �� �� �ִ� ��� ������ ������ ���� �̵��Ѵ�.

	   ������ ��� �� ��κ��� �׷��� ������ BFS�� Ǯ�̰� �����Ͽ� BFS�� ���ַ�
	   ���θ� �߾���. �׷��� dfs�� stack�� ����� ������ ���� �ָ��Ͽ� 
	   ���� ã�� ���Ҵ�.

	   BFS���� queue�� stack���� �ٲٴ� �� ����� �޶����°� ����.

	   stack�� queue�� �ڷᱸ�� ���̷� ����
	   stack�� ��� ���� �� ���� �Ʒ��� �򸮱� ������ DFS�� ������ �����ϴ�.
	   (��ŷ���� �˰��� ����Ʈ ����)

	   �����ϰ� BFS�� DFS�� ���鼭 cnt ���� �����ϰ� ���� �����ָ� �Ǵ� �����̴�.

	   ���� ���������� ���ִ°� �߿��Ѱ� ����.... (�ݼ�)
���ѻ��� : -50 <= a, b, c <= 50
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool chk[101];
int arr[101][101];
int n, m;
int cnt;

void dfs(int num) {
	chk[num] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && arr[num][i] == 1) {
			cnt++;
			dfs(i);
		}
	}
}

void dfs_stack(int num) {
	chk[num] = 1;
	stack<int> s;
	s.push(num);
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		for (int i = 1; i <= n; i++) {
			if (!chk[i] && arr[x][i] == 1) {
				s.push(i);
				chk[i] = 1;
				cnt++;
			}
		}
	}
}

void bfs(int num) {
	chk[num] = 1;
	queue<int> q;
	q.push(num);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!chk[i] && arr[x][i] == 1) {
				q.push(i);
				chk[i] = 1;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	dfs_stack(1);
	cout << cnt;
}