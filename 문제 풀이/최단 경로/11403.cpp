/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.03
���� : ��� ã�� - 11403
Ǯ�� : �÷��̵� �ͼ� ��� �������� ���� �����̴�. 
       11404�� ����� �����ε� 11404�� ������ �����ٸ�
	   �� ������ ������ �ִ��� �������� �Ǵ��ϴ� ��������.
*/
#include <iostream>

using namespace std;

int n;
int line[101][101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			line[i][j] = b;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (line[i][j] == 1) continue;
				if (line[i][k] == 1 && line[k][j] == 1)
					line[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << line[i][j] << ' ';
		}
		cout << '\n';
	}
}