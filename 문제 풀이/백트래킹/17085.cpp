/*
작성자 : 이광민
일시 : 2021.07.02
제목 : 17085 - 십자가 2개 놓기
풀이 : 주어진 격자에서 십자가를 2개 놓을 수 있는 방법을 구하는 문제이다.
       n과 m이 최대 15이기 때문에 최대 6중 반복문까지 사용 가능하다.

	   그렇기 때문에 브루트 포스로 모든 경우를 확인하도록 한다.

	   처음 풀이 방식은
	   좌표 상의 두 점을 정하고 그 두점을 기준으로 
	   생성 가능한 십자가의 최대 크기를 구해 정답을 비교하는 식으로 하였다.

	   하지만, 이렇게 진행하자 2개의 십자가가 붙어있는 경우 십자가의 크기를 줄여야 최대 값이 나오는 경우가 있는데,
	   최대 크기를 구하기 때문에 무조건 최고 크기의 십자가를 구해버리는 문제가 발생했다.

	   이를 막기 위해 다른 방식으로 푼 것이 아래의 방법이다.

	   처음 푼 방식과 새로운 방식 모두 동일한 과정이 존재하는데, 그 방식은
	   첫번째 선택한 좌표에서 십자가를 놓는데 사용한 좌표들을 체크하는 것이다.

	   첫번째 십자가에서 사용된 좌표라면 두번째 좌표에서는 사용하지 못하기 때문에 이를 체크하여 
	   두번째 십자가의 크기를 구할 때 침범하지 않도록 처리한다.

	   첫번째 십자가의 크기를 결정할 때, 만약 최대 n까지 길이 증가가 가능하다면,
	   첫번째 방식은 한번에 n까지 모두 늘려서 확인을 하였고, 두번째 방식은 1부터 n까지 차례대로 늘려가며 2번째 십자가의 크기를 측정하였다.

	   첫번째 좌표에서 사용하였다고 처리한 좌표들을 #이 아닌 다른 문자로 변경하고 이 과정이 끝나고 나서
	   새로운 첫번째 좌표를 처음부터 다시 선택하기 위해 변경한 좌표들을 다시 #으로 모두 바꿔주어야 한다.

	   이렇게 두 십자가의 크기를 구하고 최종적으로 가장 큰 크기의 곱을 구해 출력한다.
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
char arr[16][16];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	int ans = 0;
	
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (arr[x1][y1] != '#') continue;
			for (int k = 0; ; k++) {
				if (x1 - k < 0 || x1 + k >= n) break;
				if (y1 - k < 0 || y1 + k >= m) break;
				if (arr[x1 - k][y1] != '#' || arr[x1 + k][y1] != '#') break;
				if (arr[x1][y1 - k] != '#' || arr[x1][y1 + k] != '#') break;
				arr[x1 - k][y1] = '*'; arr[x1 + k][y1] = '*';
				arr[x1][y1 - k] = '*'; arr[x1][y1 + k] = '*';
				for (int x2 = 0; x2 < n; x2++) {
					for (int y2 = 0; y2 < m; y2++) {
						for (int k2 = 0; ; k2++) {
							if (x2 - k2 < 0 || x2 + k2 >= n) break;
							if (y2 - k2 < 0 || y2 + k2 >= m) break;
							if (arr[x2 - k2][y2] != '#' || arr[x2 + k2][y2] != '#') break;
							if (arr[x2][y2 - k2] != '#' || arr[x2][y2 + k2] != '#') break;
							int area = (1 + k * 4) * (1 + k2 * 4);
							if (ans < area) ans = area;
						}
					}
				}
			}

			for (int k = 0; ; k++) {
				if (x1 - k < 0 || x1 + k >= n) break;
				if (y1 - k < 0 || y1 + k >= m) break;
				if (arr[x1 - k][y1] != '*' || arr[x1 + k][y1] != '*') break;
				if (arr[x1][y1 - k] != '*' || arr[x1][y1 + k] != '*') break;
				arr[x1 - k][y1] = '#'; arr[x1 + k][y1] = '#';
				arr[x1][y1 - k] = '#'; arr[x1][y1 + k] = '#';
			}
		}
	}

	cout << ans;
}