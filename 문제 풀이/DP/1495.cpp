/*
작성자 : 이광민
일시 : 2021.05.28
제목 : 1495 - 기타리스트
풀이 : 처음 생각 방향을 잘못잡아 오래걸린 문제
       처음 생각한 DP 구현 방식은 이 전의 값에서 현재 볼륨 조절 값을 빼고 더해서 항상 최대 값을 저장하면 된다고 생각했다.
	   하지만, 가장 마지막에 최대 볼륨을 재생 시키고 마지막 이전까지의 볼륨을 0을 만들 수 있다면 이는 0을 만들고 마지막에 최대로 올리는 것이 정답이다. (시작 : 2  볼륨 : 1 1 5 인 경우)

	   그렇기 때문에 최대값을 저장하는 것이 아니라 가능한 모든 경우를 처리하는것이 올바르다.

	   즉, 베이스 값은 d[0][s-v[i]]와 d[0][s+v[i]]를 참으로 만들고 나머지 볼륨들을 조절하면 된다.

	   착각한 점
	   1. 볼륨의 조절은 n과 m사이의 볼륨이 아니라 n과 m으로 가능하다. (현재 볼륨에서 빼고 더한 값으로 조절이 가능하다)
	   2. 볼륨을 조절하지 못하는 경우도 생긴다 -> -1을 출력 (문제를 끝까지 잘 읽자 -> 0퍼센트에서 체크하는 부분이 이 경우 처음에 처리해주지 않아서 정상적으로 진행이 불가능했다.)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, m;
int v[101];
bool d[101][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	if (s - v[0] >= 0) d[0][s - v[0]] = true;
	if (s + v[0] <= m) d[0][s + v[0]] = true;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (d[i - 1][j]) {
				if (j - v[i] >= 0) {
					d[i][j - v[i]] = true;
				}
				if (j + v[i] <= m) {
					d[i][j + v[i]] = true;
				}
			}
		}
	}

	int answer = -1;
	for (int i = m; i >= 0; i--) {
		if (d[n - 1][i]) {
			answer = i;
			break;
		}
	}
	cout << answer;
}