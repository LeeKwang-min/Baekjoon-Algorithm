/*
작성자 : 이광민
일시 : 2021.06.02
제목 : 16235 - 나무 재테크
풀이 : 삼성 S직군 기출 문제라고 한다.
       문제를 정리하면 다음과 같다.
	   
	   1. 땅은 N X N 크기 이며 (1,1) ~ (n,n)까지이다.
	   2. 모든 땅의 양분은 5에서 시작한다.
	   3. M개의 나무를 구매하여 심으며 한칸의 땅에 여러개의 나무가 존재할 수 있다.
	   4. 봄, 여름, 가을, 겨울로 과정이 진행된다.

	   봄 : 나무의 나이만큼 양분을 먹고 나이가 1증가 한다.
	        단, 나무가 여러개라면 나이가 적은 나무부터 양분을 먹는다.
			나이만큼의 양분을 먹지 못하면 죽는다.
	   여름 : 봄에 죽은 나무들이 땅의 양분이 된다 (죽은 나무의 나이 / 2)
	   가을 : 땅의 나무들의 나이가 5의 배수라면 자신을 기준으로 8방향에 나이가 1인 나무를 번식한다.
	   겨울 : 땅에 A배열 만큼의 양분을 추가한다.

	   여름, 가을, 겨울의 구현은 간단하게 처리된다 (간단하다)

	   하지만, 봄의 경우 나는 다음과 같은 과정을 거쳐 풀게 되었는데
	   1. 우선순위 큐를 사용하여 처리
	   2. 벡터에서 정렬을 사용하여 처리
	   3. 덱을 사용

	   1번의 경우 시간초과로 통과하지 못했고
	   2번의 경우 풀이는 했지만 시간이 제한시간에 비하면 조금 촉박했다.

	   1번이 실패한 이유는 다음과 같다고 한다.
	   우선순위 큐에 특정 값을 삽입하면 매번 정렬이 발생하고 내 코드 구현상 임시 벡터에 값을 받아서 다시 큐에 넣기 때문에 2번의 정렬이 일어나서 시간 초과가 일어난다고 한다.

	   2번의 경우 1번의 2중 정렬을 1번만 진행하도록 하는 구현을 통해 통과가 되었다

	   하지만 3번의 풀이를 검색을 통해 확인한 결과 덱을 사용하면 2번보다 훨씬 효율적인 방식이 가능했다.
	   덱의 자료구조 특성은
	   앞(front) 뒤(back)에서 pop과 push가 가능하다는 특징이 있는 자료구조이다.
	   그렇기 때문에 만약 나무의 나이를 처음부터 오름차순으로 정렬되도록 덱을 사용한다면 정렬이 없어도 올바른 구현이 가능하다는 뜻이된다.

	   한칸의 땅에 나무들의 나이가 (3, 4, 5) 라면
	   총 3번만 반복하도록 size를 받아와서 반복문을 돌며 front부터 pop을 해준다. 그리고
	   - 양분을 먹을 수 있는 나무는 나이를 증가시키고 덱의 뒤로 넣어준다.
	   - 양분을 먹지 못하는 나무는 죽은 나무에 포함시키고 덱에 다시 넣어주지 않는다.

	   이 과정을 통해 나무들의 나이 순서는 유지되고 살아있는 나무들만 그대로 탐색된다.

	   여기서 하나 배운것은 "size를 받아와서 반복문을 도는 것" 이다.
	   충분히 알고있었고 알 수 있는 것이지만, 덱 자료구조에서 유용하게 쓰이는 기술인것 같으니 알아두면 좋을것 같다.

	   (추가로 3번보다 훨씬 좋은 방식으로 구현한 사람의 코드를 참고할 수 있었다.
	    그 분의 코드는 추가로 탐색을 중간에 종료하고 남은 값을 모두 죽은 나무에 넣거나 가을에 처리할 값들을 미리 spring_to_summer 함수에서 저장을 하는 식으로 구현하셨다.)

		(아래 주석 코드 -> 2번 // 본 코드 -> 3번 // 1번 코드는 시간초과로 삭제)
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m, k;
int a[11][11];
int food[11][11];
deque<int> trees[11][11];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring_to_summer() {
	vector<pair<pair<int, int>, int>> dead_tree;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			int it = trees[i][j].size();
			while(it--) {
				int age = trees[i][j].front();
				trees[i][j].pop_front();
				if (age <= food[i][j]) {
					food[i][j] -= age;
					trees[i][j].push_back(age + 1);
				}
				else {
					dead_tree.push_back({ {i, j}, age });
				}
			}
		}
	}

	for (int i = 0; i < dead_tree.size(); i++) {
		auto cur = dead_tree[i];
		int x = cur.first.first;
		int y = cur.first.second;
		int z = cur.second;
		food[x][y] += z / 2;
	}
}

void autumn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
						trees[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += a[i][j];
		}
	}
}

int count_tree() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += trees[i][j].size();
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			food[i][j] = 5;

	while (k--) {
		spring_to_summer();
		autumn();
		winter();
	}

	int ans = count_tree();
	cout << ans;
}


/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int a[11][11];
int food[11][11];
vector<int> trees[11][11];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring_to_summer() {
	vector<pair<pair<int, int>, int>> dead_tree;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			vector<int> tmp;
			sort(trees[i][j].begin(), trees[i][j].end());
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] <= food[i][j]) {
					tmp.push_back(trees[i][j][k] + 1);
					food[i][j] -= trees[i][j][k];
				}
				else {
					dead_tree.push_back({ {i, j}, trees[i][j][k] });
				}
			}
			trees[i][j].clear();
			for (int k = 0; k < tmp.size(); k++) {
				trees[i][j].push_back(tmp[k]);
			}
		}
	}

	for (int i = 0; i < dead_tree.size(); i++) {
		auto cur = dead_tree[i];
		int x = cur.first.first;
		int y = cur.first.second;
		int z = cur.second;
		food[x][y] += z / 2;
	}
}

void autumn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
						trees[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += a[i][j];
		}
	}
}

int count_tree() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += trees[i][j].size();
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			food[i][j] = 5;

	while (k--) {
		spring_to_summer();
		autumn();
		winter();
	}

	int ans = count_tree();
	cout << ans;
}
*/