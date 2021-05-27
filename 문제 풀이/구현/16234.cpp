/*
작성자 : 이광민
일시 : 2021.05.26
제목 : 인구 이동 - 16234
풀이 : 구현 문제 하지만 BFS를 곁들인
       구현 문제는 항상 오래 걸리지만 재밌다 (풀수 있거든...)

	   국경을 열것인가 말것인가를 정해야 하는것이 우선이고
	   국경을 열었다면 열려있는 국경간에 서로 인구 이동을 해야 한다.

	   각 함수와 변수에 대해 설명을 하자면
	   <변수>
	   people[x][y] => (x,y)국가의 인구 수

	   line[x][y][4] => (x,y)국가의 국경선 개방 여부 -> 상, 우, 하, 좌 순서로 0, 1, 2, 3 인덱스를 가진다.

	   dx, dy[] => BFS탐색용 인접 칸 이동 배열

	   dxs, dys[] => 인구수 탐색용 인접 칸 이동 배열

	   <함수>
	   find_people => 서로 맞닿은 국가간에 인구 수가 L이상 R이하 인지 확인하여 국경을 여는 함수이다.
	                  이 함수는 BFS와 달리 (0,0)에서 시작하여 오른쪽과 아래쪽의 국가만 탐색하며 진행한다.
					  이렇게 진행하며 기준이 되는 국가를 (x,y) 인근 국가를 (dx, dy)라고 했을 때
					  기준 국가의 국경선 인덱스와 인근 국가의 국경선 인덱스를 조건문을 통해 두 국가 모두의 국경선을 개방시켜준다.
	   
	   find_end => 모든 국경선이 닫혀있는지 확인하는 함수로 모두 닫혀있다면 더이상 이동은 없다는 뜻이므로 반복문을 종료시키기 위한 bool 변수를 설정한다.

	   bfs => 2가지 queue가 사용되는데
	          q => bfs 탐색용 큐
			  people_cnt => 탐색을 마치고 평균 인원을 people 배열의 어느곳에 넣어야 하는지 좌표들을 가지고 있는 큐
			  이 두가지 큐를 사용하며
			  먼저 q 큐를 사용하여 국경선이 열려있고 접근한적 없는 국가라면 이동하여 국경선을 닫고 
			  sum_people (국경선이 열린 국가들의 총 합)
			  cnt (총 국가 수)
			  두 값을 증가시켜 평균 값을 만든다.
			  그리고 나서 people_cnt 큐를 사용하여 이동한 국가들에 대해 평균 인원수로 모두 바꿔준다.

	   union_people => 열린 국경선만 파악하기 위해 사용 (bfs와 합치면 복잡해질것 같아 통합 시켰다.)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, l, r;
int people[50][50];
int line[50][50][4];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dxs[] = { 0, 1 };
int dys[] = { 1, 0 };

void find_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int x = i + dxs[k];
				int y = j + dys[k];
				if (x >= n || y >= n) continue;
				int sub_people = people[i][j] > people[x][y] ? people[i][j] - people[x][y] : people[x][y] - people[i][j];
				if (sub_people >= l && sub_people <= r) {
					if (k == 0) {
						line[i][j][k + 1] = true;
						line[x][y][k + 3] = true;
					}
					else { // k = 1
						line[i][j][k + 1] = true;
						line[x][y][k - 1] = true;
					}
				}
			}
		}
	}
}

bool find_end() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (line[i][j][k]) return false;
			}
		}
	}
	return true;
}

void bfs(int a, int b) {
	int sum_people = people[a][b];
	int cnt = 1;
	vector<vector<bool>> chk(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	queue<pair<int, int>> people_cnt;
	q.push({ a, b });
	people_cnt.push({ a, b });
	chk[a][b] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			if (!line[x][y][k]) continue;
			line[x][y][k] = false;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny]) continue;
			q.push({ nx, ny });
			people_cnt.push({ nx, ny });
			chk[nx][ny] = true;
			if (k == 0) {
				line[nx][ny][2] = false;
			}
			else if (k == 1) {
				line[nx][ny][3] = false;
			}
			else if (k == 2) {
				line[nx][ny][0] = false;
			}
			else {
				line[nx][ny][1] = false;
			}
			sum_people += people[nx][ny];
			cnt++;
		}
	}
	//cout << sum_people << ' '  << cnt << '\n';
	int avg_people = sum_people / cnt;
	while (!people_cnt.empty()) {
		auto cur = people_cnt.front();
		people_cnt.pop();
		int x = cur.first;
		int y = cur.second;
		people[x][y] = avg_people;
	}
}

void union_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (line[i][j][k]) bfs(i, j);
			}
		}
	}
}

void show_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << people[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> people[i][j];
	//cout << '\n';
	int answer = 0;
	while (1) {
		find_people();
		bool chk_end = find_end();
		if (chk_end) break;
		union_people();

		//show_people();

		answer++;
	}

	cout << answer;
}