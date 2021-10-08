/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.30
���� : �ִ� �� - 11279
Ǯ�� : �켱���� ť ������ ���� �ִ� ���� �����ؾ� �ϱ� ������ less�� ���ؼ� �����Ѵ�.
       ������ �ð��� �ſ� ���� ����̴�.
	   ios_base�� cin.tie�� ������ ������ �ð��ʰ��� �߻��Ѵ�.
	   �ܿ�� ��������

	   1927�� ������ ���� �����̸� lsee�� greater�� �ٲ��ָ� �ȴ�.
���ѻ��� :
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, less<int>> pq;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(a);
		}
	}
}