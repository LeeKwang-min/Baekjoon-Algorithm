/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 외판원 순회 2 - 10971
풀이 : 그 유명한 Travelling Salesman Problem(TSP) 문제이다.
       외판원 문제는 한 도시에서 시작하여 다른 모든 도시를 거쳐 "다시 처음의 도시로 돌아오는"
	   최소의 비용 경로를 정하는 문제이다.

	   1번부터 N번까지의 도시가 있고 한 번 갔던 도시로는 다시 갈 수 없는 중복이 없는 수이기 때문에
	   순열을 사용하여 풀면된다.
	   1 2 3 4 도시가 있다면
	   1 2 3 4 경로의 비용을 확인하고 다음 순열인
	   1 2 4 3 경로의 비용을 확인하고 또 다음 것을 확인하는 방식을 사용하면 된다.

	   경로가 있는지 없는지 확인해 주어야 하며
	   마지막 도시를 거쳐 다시 처음의 도시로 돌아오는 것을 추가하여 최소 비용을 계산해주어야 한다.

	   이 문제는 경우의 수로 제한 조건이 중요하다.
	   이 문제의 제한은  2 <= N <= 10 으로
	   모든 순열을 확인하는데 걸리는 시간 복잡도인 
	   O(N * N!) = 10 * 3628800 으로 
	   모든 과정을 확인해 보아도 문제 없다.  (11부터는 불가능하다)

	   ★ 하지만, 외판원 순회 문제의 특성인 시작 도시로 돌아간다는 점을 이용하면
	   시간을 더 빠르게 만들 수 있다. (구현한 코드가 더 빠른 코드이다)

	   외판원 순회의 경우 1 -> 2 -> 3 -> 4 -> 1 과 같이 순회를 하는데
	   1, 2, 3, 4 의 순서로 간다고 했을 때 2 -> 3 -> 4 -> 1 로 가도 그 과정은 같다
	   왜냐하면 1 2 3 4 와 2 3 4 1 둘 다 싸이클이 같기 때문이다.
	   이 점을 이용하면 시작점을 한곳으로 고정하고 모든 순열을 확인하여도 상관이 없다는
	   점을 알 수 있다.

	   do{}while 의 주석 처리된 if문이나 next_permutation을 처리할 때 begin() + 1 을 해주면 된다.

	   이렇게 되면 N! / N 으로 O(N * (N-1)!) = O(N!) 이 된다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int w[11][11];
int num[11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];

	for (int i = 0; i < n; i++)
		num[i] = i + 1;

	int minSum = 1e9;
	do {
		// if(num[0] != 1) break;
		int sum = 0;
		bool chk = true;

		for (int i = 0; i < n - 1; i++) {
			if (w[num[i]][num[i + 1]] == 0) {
				chk = false;
				break;
			}
			sum += w[num[i]][num[i + 1]];
		}

		if (w[num[n - 1]][num[0]] != 0) sum += w[num[n - 1]][num[0]];
		else chk = false;

		if (chk && minSum > sum) minSum = sum;
	} while (next_permutation(num + 1, num + n));

	cout << minSum;
}