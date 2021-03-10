/*
작성자 : 이상수
일시 : 2021.03.04
제목 : 이모티콘 - 14226
풀이 : 어떠한 분기를 선택 하는가 하지 않는가에 따라 이동하는 정점이 달라지는 문제이다.
       문제를 봤을 때 표면적인 문제의 풀이는 1차원 배열을 사용한 DP나 BFS 문제이지만,
	   이 문제는 
	   "화면에 표시되는 이모티콘의 개수" 
	   와
	   "클립 보드에 복사되어있는 이모티콘의 개수"
	   를 가지고 풀어야 하는 2차원 문제라고 할 수 있다.

	   즉, 결국 최종 결과는 화면에 표시되는 이모티콘의 개수이지만, 
	   그 과정에서 클립보드에 몇개가 있는지가 다르기 때문이다.

	   화면 = S  클립보드 = C 라고 하고 현재 (S, C) 정점에 있다고 할 때
	   1. 복사 = (S, C) -> (S, S) 로 이동한다 볼 수 있고
	   2. 붙여넣기 = (S, C) -> (S+C, C) 이며
	   3. 삭제 = (S, C) -> (S-1, C) 가 된다.

	   가장 처음 화면에 표시되는 이모티콘은 1개이고
	   클립보드에 복사되어있는 이모티콘의 개수는 0개라고 했으니
	   (1, 0)에서 시작하면 된다.

	   그 후 BFS를 돌면서 처리하면 되며
	   DP로도 풀 수가 있다.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int s, c;
int cnt[2001][2001];
bool chk[2001][2001];
queue<pair<int, int>> q; // first = 화면, second = 클립보드

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	q.push({ 1, 0 });
	chk[1][0] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		if (x < 1000 && chk[x][x] == false) {
			q.push({ x,x });
			chk[x][x] = true;
			cnt[x][x] = cnt[x][y] + 1;
		}

		if (x + y <= s && chk[x + y][y] == false) {
			q.push({ x + y, y });
			chk[x + y][y] = true;
			cnt[x + y][y] = cnt[x][y] + 1;
		}

		if (x - 1 >= 0 && chk[x - 1][y] == false) {
			q.push({ x - 1, y });
			chk[x - 1][y] = true;
			cnt[x - 1][y] = cnt[x][y] + 1;
		}
	}

	int ans = 987654321;
	for (int i = 0; i < 2001; i++)
		if (chk[s][i]) ans = min(ans, cnt[s][i]);
		

	cout << ans;
}