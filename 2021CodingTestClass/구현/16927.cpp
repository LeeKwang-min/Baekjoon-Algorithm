/*
작성자 : 이상수
일시 : 2021.03.05
제목 : 배열 돌리기 2 - 16927
풀이 : 배열 돌리기 1 과 같은 문제인데, 몇번 회전시키는지가 다르다.
       이 문제에서 주어지는 최대 r(회전 횟수)은 10억번이며
	   이를 모두 돌리게 되면 시간초과가 생긴다.

	   배열 돌리기 1에서 어떻게 처리할지 생각해본 방법은
	   주어지는 r을 지금 돌리고자 하는 배열의 길이로 나누어 그 나머지만큼만 돌리는 방식이다.

	   이 방법이 최종 정답이기도 한데, 내가 처음 구현한 배열 돌리기 1에서 이 방법을 사용하면
	   각 테두리의 길이별로 다르게 하기도 해야 하고 조금 복잡하게 구현해야 하며
	   이 때 매 반복마다 tmp와 arr의 값을 바꿔줘야 하기 때문에 시간초과가 예상된다.

	   강의를 통해 풀이를 배웠다.
	   풀이는 다음과 같다.

	   배열에서 가장 바깥쪽 값들을 0번째 그룹이라 치고
	   이 값들을 문제에서 돌려야되는 방향 순서대로 1차원 배열에 담는다.
	   이렇게 각 그룹의 값들을 1차원 배열에 담아 두고 다음으로 넘어간다.

	   1차원 배열이 다음과 같다면
	   1 2 3 4 5 
	   1번 회전 = 2 3 4 5 1
	   2번 회전 = 3 4 5 1 2
	   3번 회전 = 4 5 1 2 3
	   ...
	   즉 n번 회전을 하면 n번째 인덱스가 0번째에 오게 된다.

	   이 점을 사용하여 문제를 풀도록 한다.

	   1차원 배열에 담는 순서가 가장 중요하며 
	   헷갈리지 않도록 잘 정리하여 담아야 한다.

	   그리고 나서 idx를 사용하여 idx번째 수를 차례대로 배열에 대입한다.

	   idx = n번째 수 -> n+1번째 수 -> ... -> 범위를 넘으면 0 (나머지 연산을 통해)

	   group 벡터에는 담은 순서대로 들어있기 때문에 
	   넣을때와 똑같은 순서로 배열에 담으면 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[301][301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	vector<vector<int>> groups;
	int groupn = min(n, m) / 2;
	
	for (int k = 0; k < groupn; k++) {
		vector<int> group;
		for(int j = k; j<m-k; j++) 
			group.push_back(arr[k][j]);

		for (int i = k + 1; i < n - k; i++)  
			group.push_back(arr[i][m - 1 - k]);

		for (int j = m - 2 - k; j >= k; j--)
			group.push_back(arr[n - 1 - k][j]);

		for (int i = n - 2 - k; i >= k + 1; i--)
			group.push_back(arr[i][k]);

		groups.push_back(group);
	}

	for (int k = 0; k < groupn; k++) {
		int len = groups[k].size();
		int idx = r % len;

		for (int j = k; j < m - k; j++, idx = (idx + 1) % len)
			arr[k][j] = groups[k][idx];

		for (int i = k + 1; i < n - k; i++, idx = (idx + 1) % len)
			arr[i][m - 1 - k] = groups[k][idx];

		for (int j = m - 2 - k; j >= k; j--, idx = (idx + 1) % len)
			arr[n - 1 - k][j] = groups[k][idx];

		for (int i = n - 2 - k; i >= k + 1; i--, idx = (idx + 1) % len)
			arr[i][k] = groups[k][idx];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}