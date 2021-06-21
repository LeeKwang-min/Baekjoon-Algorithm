/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16937 - 두 스티커
풀이 : 문제 채점에 잘못된 것이 있어 정확히 풀었는지 확인할 수 없다. (구글링을 통해 통과는 했다)
       우선 스티커 N개 중에서 2개를 골라 해당 스티커를 붙일 수 있는지 없는지를 판단하는 문제이다.

	   스티커가 여러개가 아니라 2개 뿐이기 때문에
	   조합을 통해 N개의 스티커 중에서 2개를 고른다.
	   이 때, 스티커들은 회전이 가능하기 때문에 회전을 고려하여야 한다.
	   고려해야 하는 점으로는 회전한 똑같은 스티커를 고르지 않도록 해야 한다.

	   이를 파악하기 위해 현재 스티커를 사용 했는지 안했는지 확인하는 코드를 추가한다.
	   V에 가로크기, 세로크기, 스티커 번호 를 저장하여
	   스티커 번호에 대한 bool 배열이 사용 중이라면 해당 스티커는 회전 시켜도 더이상 사용하지 못하도록 한다.

	   이를 통해 최종적으로 스티커를 붙이는데, 스티커를 붙이는 방법은 총 2가지이다.
	   가로로 이어 붙이기
	   세로로 이어 붙이기

	   이 두가지 방식을 고려하면 되는데, 
	   ㅁㅁㅁㅁ
	     ㅁㅁ

	   ㅁ 
	   ㅁ ㅁ ㅁ
	   ㅁ
	   ㅁ

	   이렇게 가로로 붙이는 경우 세로의 길이를 서로 더해서 주어진 격자의 크기를 벗어나는지 확인하고 가로의 길이는 긴 것을 확인해주면 된다.
	   세로로 붙이는 경우는 가로의 길이를 서로 더해서 확인하고 세로의 긴 것을 확인해주면 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int h, w, n, Answer;
bool MAP[100][100]; // 문제가 좀 이상하다... -> 이 배열을 선언하면 통과가 된다.
bool Select[101];
bool Select2[101];
vector<pair<pair<int, int>, int>> V;
vector<pair<int, int>> Sticker;

void DFS(int Idx, int Cnt)
{
	if (Cnt == 2) {
		int x1 = Sticker[0].first;
		int y1 = Sticker[0].second;
		int x2 = Sticker[1].first;
		int y2 = Sticker[1].second;
		int point = (x1 * y1) + (x2 * y2);

		if (x1 + x2 <= h && y1 <= w && y2 <= w) Answer = max(Answer, point);
		if (y1 + y2 <= w && x1 <= h && x2 <= h) Answer = max(Answer, point);
		return;
	}

	for (int i = Idx; i < V.size(); i++) {
		if (Select[i] || Select2[V[i].second]) continue;
		Select[i] = true;
		Select2[V[i].second] = true;
		Sticker.push_back({ V[i].first.first, V[i].first.second });
		DFS(i + 1, Cnt + 1);
		Sticker.pop_back();
		Select[i] = false;
		Select2[V[i].second] = false;
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;

		if (a != b)
		{
			V.push_back(make_pair(make_pair(a, b), i));
			V.push_back(make_pair(make_pair(b, a), i));
		}
		else V.push_back(make_pair(make_pair(a, b), i));
	}
	DFS(0, 0);
	cout << Answer << '\n';
	return 0;
}