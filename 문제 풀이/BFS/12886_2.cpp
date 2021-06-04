/*
작성자 : 이광민
일시 : 2021.06.03
제목 : 12886 - 돌 그룹
풀이 : BFS를 사용하여 풀이한 방식
       기존의 풀이와 크게 다른점은 없다.
	   우선 chk배열을 최대 1501잡고 (a, b, c <= 500이기 때문에 500 499 500 이라고 가정하면 최대 1000이 나온다 하지만 넉넉히 잡는다)
	   한 정점을 (a, b, c)라고 할 때 다음으로 갈 수 있는 곳의 위치는 (a+a, b-a, c), (a-b, b+b, c), ... 등 여러개가 나온다.
	   이들을 모두 가정하고 a, b, c가 모두 같을 때 까지 반복하면 되는데, 이 모든 총합이 바뀌지 않기 때문에
	   한 가지를 가만히 두고 계산을 해도 된다.
	   sum = x + y + z = (x+x) + (y-x) + c = x + (y + y) + (c - y) = ...

	   기존의 방식이 DFS로 모든 경우를 확인했다면
	   이 방식은 나올 수 있는(탐색 가능한) 경우의 수를 모두 명시하여 계산하도록 한다.
	   이 과정을 반복하며 x, y, z가 모두 같은 경우가 나오면 그 즉시 1을 리턴하고
	   큐가 모두 빌 때까지 나오지 않으면 0을 리턴한다.

	   처음 풀이와 크게 다른게 없이
	   각 경우를 모두 풀어 썻느냐 반복문으로 처리했느냐 이다.

	   하지만 시간은 이 방식이 훨씬 빠르다
	   (아마도 모든 탐색을 마치고 chk값을 통해 확인하는 방식인 첫번째 방식에 비해서 모두 같은 값이 나오면 그 즉시 탐색을 종료하기 때문에 더 빠른것 같다)
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int sum;
bool chk[1501][1501];

int go(int a, int b, int c) {
	queue < pair<int, pair<int, int>>> q;
	q.push({ a, {b, c} });
	chk[a][b] = 1;
	chk[a][c] = 1;
	chk[b][c] = 1;
	chk[b][a] = 1;
	chk[c][a] = 1;
	chk[c][b] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second.first;
		int z = cur.second.second;
		if (x == y && y == z) return 1;
		if (x < y && !chk[x + x][y - x]) {
			q.push({ x + x, {y - x, z} });
			chk[x + x][y - x] = true;
		}
		if (x < z && !chk[x + x][z - x]) {
			q.push({ x + x, {y, z - x} });
			chk[x + x][z - x] = true;
		}
		if (y < z && !chk[y + y][z - y]) {
			q.push({ x, {y + y, z - y} });
			chk[y + y][z - y] = true;
		}
		if (y < x && !chk[y + y][x - y]) {
			q.push({ x - y, {y + y, z} });
			chk[x - y][y + y] = true;
		}
		if (z < x && !chk[z + z][x - z]) {
			q.push({ x - z, {y, z + z} });
			chk[x - z][z + z] = true;
		}
		if (z < y && !chk[z + z][y - z]) {
			q.push({ x, {y - z, z + z} });
			chk[z + z][y - z] = true;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	cout << go(a, b, c);
}