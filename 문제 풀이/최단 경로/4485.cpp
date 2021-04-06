/*
작성자 : 이상수
일시 : 2021.04.06
제목 : 녹색 옷 입은 애가 젤다지? - 4485
풀이 : 다익스트라 알고리즘의 베이스를 배운게 vector를 통한 연결 값들을 기본으로 배웠다면
       이 문제는 행렬로 주어진 값들에서 특정 좌표 (x, y)에서 (nx, ny)까지의 최소 거리를
	   찾는 문제이다.

	   기존에 알고 쓰던 다익스트라 문제를 조금 변형하여 생각하는 것이 필요하다.
	   기존에 사용하던 vector에서 arr[n].push_back({cost, nxt}) 였고 이를 말로 풀어
	   설명하면 n에서 nxt번 정점으로 갈 때 드는 비용은 cost이다.
	   였지만 이를 행렬에 적용하여
	   (x,y)좌표에서 (nx, ny)로 가는 최단 거리는
	   2개의 2차원 배열을 사용하여 
	   arr[][] => 초기 값들
	   dist[][] => 시작 좌표에서 해당 좌표까지 가는데 드는 비용
	   으로 두고 풀이를 하면 된다.

	   힙의 구조는 pair<int, pair<int, int>>가 된다.
	   ({ cost, { x, y } })

	   이 문제에서는 시작점을 (0, 0) 으로 두고 해당 좌표에서 다른 좌표로 가는 
	   최단 거리를 구하는 다익스트라 알고리즘을 실행하고 최종 목적지인
	   dist[n-1][n-1]을 출력 해주면 된다.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;
int n;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int arr[126][126];
int dist[126][126];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				dist[i][j] = INF;
			}
		}

		dist[0][0] = arr[0][0];
		pq.push({ dist[0][0], {0, 0} });

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			int cost = cur.first, x = cur.second.first, y = cur.second.second;
			if (dist[x][y] != cost) continue;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int ncost = arr[nx][ny];
				if (dist[nx][ny] > cost + ncost) {
					dist[nx][ny] = cost + ncost;
					pq.push({ dist[nx][ny], { nx, ny } });
				}
			}
		}

		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
		t++;
	}
}