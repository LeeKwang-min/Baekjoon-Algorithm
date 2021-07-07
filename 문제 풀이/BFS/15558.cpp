/*
작성자 : 이광민
일시 : 2021.07.03
제목 : 15558 - 점프 게임
풀이 : BFS를 통해 주어진 격자에서 이동이 가능한지 확인하는 문제
       1차원 배열이 2개 주어진다. 하지만, 두 배열 사이를 왔다 갔다 해야 하기 때문에
	   더욱 간편하게 코드를 작성하기 위해 2차원 배열로 두 배열을 합쳐서 사용하였다.

	   BFS를 탐색하며 다음 이동이 주어진 범위 밖으로 나갈 수 있는지를 확인하여 가능하다면 1을 불가능하다면 0을 출력해주면 된다.
	   가능 하다면(범위를 넘어간다면) BFS탐색의 큐가 비기 전에 해당 값이 나올 것이고
	   불가능 하다면 큐가 빌때까지 범위를 벗어나는 값이 나오지 않을 것이다.
	   이 점을 사용하여 정답을 출력해주면 된다.

	   N초마다 N번째 칸이 사라진다고 나온다. 이를 처리하기 위해
	   N초에 특정 칸 i번째에 갔다면 해당 칸으로 이동한 시간은 N초이며 이 시간의 증가는 
	   이동을 마친 이후이다. 그렇기 때문에 이동 = 큐에 삽입 이기 때문에 
	   큐에 삽입할 때 몇초에 해당 칸으로 이동했는지를 함께 저장해준다.

	   이렇게 진행하며 범위를 벗어나는 경우가 있는지 없는지 탐색한다.

	   BFS의 기초는 반복 방문 여부 점검이다. -> 실수한 부분이다. (기초적인것을 까먹지 말고 항상 문제를 잘 파악하자)
*/


#include<iostream>
#include<string>
#include<queue>

using namespace std;

int n, k;
bool arr[2][100001]; // false = 0 = 위험 / true = 1 = 안전
bool chk[2][100001];

bool bfs() {
	queue<pair<int, pair<int, int>>> q; // <초, 무슨 줄, 몇번째 칸> 줄 => 0 = 왼, 1 = 오
	q.push({ 0, { 0, 0 } });
	chk[0][0] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int sec = cur.first;
		int line = cur.second.first;
		int x = cur.second.second;
		if (x + 1 >= n || x + k >= n) return true;

		if (sec < x + 1 && !chk[line][x + 1] && arr[line][x + 1] == 1) {
			q.push({ sec + 1, { line, x + 1 } });
			chk[line][x + 1] = true;
		}
		if (sec < x - 1 && !chk[line][x - 1] && arr[line][x - 1] == 1) {
			q.push({ sec + 1, { line, x - 1 } });
			chk[line][x - 1] = true;
		}
		int nxt_line = line == 1 ? 0 : 1;
		if (sec < x + k && !chk[nxt_line][x + k] && arr[nxt_line][x + k] == 1) {
			q.push({ sec + 1, { nxt_line, x + k } });
			chk[nxt_line][x + k] = true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '1') arr[0][i] = 1;
		if (s2[i] == '1') arr[1][i] = 1;
	}

	if (bfs()) cout << 1;
	else cout << 0;
}