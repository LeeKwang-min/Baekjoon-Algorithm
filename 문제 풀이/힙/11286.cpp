/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.30
���� : ���� �� - 11286
Ǯ�� : �Ϲ������� �켱���� ť�� �����ؼ� ó���ϴ� �� �Ȱ�����,
       greater�� less�� �ƴ϶� ������ ������ �񱳸� �������� ����Ǿ�� �ϱ� ������
	   ���� ������ ���־�� �Ѵ�.

	   �Ϲ� sort���� �Լ��ʹ� �޸� 
	   �켱���� ť�� �� �κп��� ����ü�� ���� �Ѵ�.
	   �� ���� ����� �Ʒ� cmp�� ������
	   operator() (�Ű� ����) �� ���� �����ؾ� �Ѵ�.
	   �� �� �����ϰ� ��� �ص���.
���ѻ��� :
*/
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		int c, d;
		c = a;
		d = b;
		if (a < 0) c = a * (-1);
		if (b < 0) d = b * (-1);
		
		if (c == d) {
			return a > b;
		}

		return c > d;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, cmp> pq;
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


/*
	�켱���� ť �񱳹� ���� ���
	struct cmp{
		bool operator() (int a, int b){
			return a < b;
		}
	};

	�� ����
	cmp �κ��� ����� ���� �̸����� �����̸�

	operator()�� ��� ����ü�� ������ ����� ���� �ǹ��̴�.

	operator() (�Ű�����) ���� �������.
*/