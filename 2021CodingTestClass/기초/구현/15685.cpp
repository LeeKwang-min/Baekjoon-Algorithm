/*
작성자 : 이상수
일시 : 2021.03.06
제목 : 드래곤 커브 - 15685
풀이 : 풀 수 있는 문제였는데 혼자서 문제 똑바로 안읽고 결국 해설을 봐버린 문제...
       혼자서 아무리 종이에 그림을 그려봐도 예시로 주어지는 그림과 달라서
	   어떻게 하면 저렇게 나오는거지...? 라는 생각으로 한시간을 고민하다가 해설을 봤다.

	   처음 내가 생각한 풀이와 크게 다른게 없었고, 그럼에도 저렇게 그림이 그려진다고?
	   라는 생각에 그때서야 다시 문제를 보니
	   처음 주어지는 x,y 가 행,열 이 아니라 열,행 으로 주어지는 문제였다...

	   문제를 똑바로 읽자...

	   풀이는 간단하다 처음 시작점에서 90도 방향으로 꺽어서 1 증가하면 되는 문제인데,
	   기존의 dx dy 배열을 사용하면 간단하게 처리가 가능하며
	   90도 방향으로 회전 후에 이전 세대의 "끝 점"에 맞물리도록 하면 되기에
	   시계방향 90도 전환이 아닌 반시계 방향으로 90도 전환을 하는 것을 하면 된다.

	   지금 풀이는 강의를 통해 알게되었는데
	   1. K-1 세대의 순서를 반대로 담는다 (Ex) K-1 = 1234 ==> K = 1234 4321
	   2. 반대로 담은 방향들을 -90도로 돌린다.

	   와 같이 풀이가 된다고 한다.

	   처음 내가 생각한 방식은
	   0세대 = 1번
	   1세대 = 1번
	   2세대 = 2번
	   3세대 = 4번 
	   씩 증가가 되어 총 횟수가
	   0세대 = 1번
	   1세대 = 2번
	   2세대 = 4번
	   3세대 = 8번
	   이동하면 되기 때문에 시간은 충분한거 같아
	   횟수마다 방향을 전환해가면서 chk값을 바꿀려고 했다.
	   (시간 복잡도는 강의의 풀이가 훨 좋은것 같다)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
bool chk[101][101];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void go(int x, int y, int d, int g) {
	vector<int> ans = { d };
	while (g--) {
		vector<int> tmp;
		for (int i = ans.size() - 1; i >= 0; i--)
			tmp.push_back(ans[i]);
		for (int i = 0; i < tmp.size(); i++)
			tmp[i] = (tmp[i] + 1) % 4;

		for (int i = 0; i < tmp.size(); i++)
			ans.push_back(tmp[i]);
	}

	for (int i = 0; i < ans.size(); i++) {
		int nx = x + dx[ans[i]];
		int ny = y + dy[ans[i]];
		chk[nx][ny] = true;
		x = nx;
		y = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		chk[x][y] = true;
		go(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (chk[i][j] && chk[i][j + 1] && chk[i + 1][j] && chk[i + 1][j + 1]) 
				ans++;
		}
	}

	cout << ans;
}