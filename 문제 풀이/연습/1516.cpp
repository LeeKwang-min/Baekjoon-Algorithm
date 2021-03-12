/*
작성자 : 이상수
일시 : 2021.03.12
제목 : 게임 개발 - 1516
풀이 : 위상정렬 문제
       위상정렬을 사용하기 위해 고려할 점

	   가장 처음 진입 차수가 0인 정점 => 선수 건물이 없다. => 짓는 시간 = 최종 시간
	   그 다음부터는 짓는시간과 전수 건물을 만드는데 걸리는 시간을 합하는 것과 같다
	   (해당 건물을 짓기 위해 우선적으로 지어야 하는 건물들의 총합이므로)

	   그리고 진입차수가 0이 될 때만 짓는 시간을 바꾸어서는 안된다.
	   왜냐하면 
	   1 -> 4 <- 3 이 있다고 하자. (1 -> 3 도 있다)
	   여기서 1 -> 4는 10      
	   3 -> 4는 4 라고 할 때
	   진입차수가 0인 1을 제외할 때 4는 3에서 들어오는 진입 차수가 있기 때문에
	   진입 차수가 0이 아니게 되고 0이 될때만 처리를 하게 되면 
	   4를 짓기 위해 1과 3이 모두 지어지는 시간은 4보다 더 느린 1이 지어지는 10분 뒤인데,
	   4가 진입차수가 0이 되는 시기는 3이 지어질때이다.
	   즉, 이렇게 되면 그 값이 4 + 지어지는 시간이 된다.

	   이 때문에
	   해당 건물을 짓기 위해 우선적으로 지어야 하는 건물들 중에서 가장 오래 걸리는 시간
	    + 특정 건물을 짓기 위해서 걸리는 시간 이 되어야 한다.

		bTime[n] = n번째 건물을 짓는데 걸리는 시간
		res[n] = n번째 건물을 짓기 위해 걸리는 최소 시간

		res[nxt] = max(res[nxt], res[x] + btime[nxt]);
		
		선수 건물 x를 짓기까지 걸리는 시간 + 현재 건물을 짓는데 걸리는 시간
		과
		현재 건물을 짓는데 걸리는 현재 저장된 시간
		을 비교하여
		더 오래 걸리는 것을 골라야 한다.
		예)
		nxt를 짓기 위해 필요한 건물이 1, 2, 3 이 있다고 하고
		1과 2가 지어져서 res[nxt]에 저장되어있을 때
		x가 3이고 nxt가 지어졌다면 
		3이 지어지는데 걸리는 시간 + nxt를 짓는데 걸리는 시간
		과
		1, 2가 지어지고 nxt가 지어지는데 걸리는 시간중
		후자가 더 오래걸린다면 
		원래의 값에 맞추는것이 맞다
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> arr[501];
int inDegree[501];
int res[501];
int btime[501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> btime[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;
			arr[a].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			res[i] = btime[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto nxt : arr[x]) {
			inDegree[nxt]--;

			res[nxt] = max(res[nxt], res[x] + btime[nxt]);
			if (inDegree[nxt] == 0) q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << '\n';
}