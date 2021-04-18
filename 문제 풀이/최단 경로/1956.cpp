/*
작성자 : 이상수
일시 : 2021.04.18
제목 : 운동 - 1956
풀이 : 플로이드 와샬 알고리즘을 사용하는 문제
       내가 플로이드 와샬 문제를 풀 때 항상 놓치는 부분
	   1. 처음 자기 자신 (arr[i][j]에서 i == j일 때)의 비용은 0이다.
	   2. 값을 비교할 때에는 i와 j가 같은지를 확인하지 "않는다."
	   
	   위 방식이 반드시 되어야 하는것은 아니지만 (이부분은 다시 개념확립하자)

	   이 문제는 플로이드 와샬 알고리즘을 통해 최단 경로를 구한 다음
	   "최소 비용을 가지는 사이클 거리" 를 구하는 문제이다.
	   즉, 특정 N1에서 출발하여 다시 N1으로 돌아오는 경우에서
	   사이클은 다른 하나의 곳을 갔다가 다시 나에게로 돌아오면 사이클이기 때문에

	   마지막 값 구하기에서 2중 반복문을 통해
	   i에서 출발하여 다시 i로 돌아오는 최소 비용을 찾으면 된다.
*/
#include<iostream>
#include<vector>

using namespace std;

const int INF = 987654321;
int v, e;
long long arr[401][401];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;

	
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}
	
	/*
	for (int i = 1; i <= v; i++) 
		for (int j = 1; j <= v; j++) 
			arr[i][j] = INF;
	*/

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	long long ans = INF;
	
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (ans > arr[i][j] + arr[j][i]) ans = arr[i][j] + arr[j][i];
		}
	}
	
	/*
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) {
				if (ans > arr[i][j]) ans = arr[i][j];
			}
		}
	}
	*/
	if (ans == INF) cout << -1;
	else cout << ans;
}