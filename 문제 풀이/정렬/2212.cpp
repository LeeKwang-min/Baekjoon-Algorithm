/*
작성자 : 이상수
일시 : 2021.04.10
제목 : 센서 - 2212
풀이 : 정렬을 통한 문제라는걸 알고 들어갔는데도 해결하지 못해서 구글링을 통해 힌트를
       찾아보고 해결했다.

	   어느정도의 접근은 비슷하게 하였으나 결정적인 부분을 찾지 못했다.

	   해결 순서는 다음과 같다.
	   1. 센서들을 오름차순 정렬한다.
	   2. 센서들간의 거리 차이를 계산한다.
	   3. 거리 차이를 내림차순 정렬한다.
	   4. 3번의 값에서 앞쪽부터 k-1개를 제외하고 모두 더한다.

	   이게 정답이 된다. 이렇게 되는 이유는
	   총 n개에서 서로간의 거리 차이를 구한 다음
	   해당 값들을 더하면 모든 센서들의 구간이 된다.
	   Ex) 1 3 6 6 7 9 -> 2 3 0 1 2 -> 모두 더하면 1 - 9 로 8이 된다.

	   여기서 기지국이 k개 있다는 말은 위 과정에서 k-1개를 제외하면
	   k개로 나뉜 구간으로 바뀌게 된다.
	   Ex) 1 3 6 6 7 9 -> 2 3 0 1 2 -> 3 2 2 1 0 (k = 2) -> 2 2 1 0을 모두 더하면
		   [1, 3], [6, 9] 로 나뉘게 된다.
		   (k = 3) -> 2 1 0 -> [1, 3], [6, 6], [7, 9] 로 나뉜게 된다.

		   이처럼 k-1개를 제외하면 되는 간단한 문제가 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	vector<int> ans(n - 1);
	for (int i = 1; i < n; i++)
		ans[i - 1] = arr[i] - arr[i - 1];

	sort(ans.begin(), ans.end(), greater<>());
	int sum = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (i < k - 1) continue;
		sum += ans[i];
	}
	cout << sum;
}