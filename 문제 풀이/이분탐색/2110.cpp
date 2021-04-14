/*
작성자 : 이상수
일시 : 2021.04.14
제목 : 공유기 설치 - 2110
풀이 : 이분탐색을 사용하여 푸는 문제인데 조금의 생각을 다르게 해야 하는 문제
       이분 탐색문제를 오늘로 3개정도 풀었는데, 이분 탐색 문제에서 가장 중요한 것은
	   while문을 시작하고 target과 비교할 대상을 구하는 부분이 가장 중요하다고 생각한다.

	   이 문제에서 해매게 된 부분이 위에서 말한 중요하다고 생각한 부분이다.
	   총 c개의 공유기를 설치하기 위해 어떻게 하면 될까? 라는 고민에
	   이분탐색을 c번 진행하는건가? 라는 생각이 들었지만 
	   이는 매우 잘못된 생각이였고 이를 해결하는 방법은 다음과 같다.

	   1. 정렬을 통해 집들의 좌표를 정렬한다.
	   2. 시작 = 1, 끝 = 끝 - 시작의 거리 로 둔다. ★
	   3. 두 지점의 중간을 값으로 두고 해당 거리를 인접 거리의 최대로 잡았을 때
	      주어진 좌표에 최소 c개의 공유기를 둘 수 있는지 확인한다. ★
	   4. 둘 수 있다면 거리를 더 늘려보고
	   5. 둘 수 없다면 거리를 더 좁혀가며 이분탐색을 진행한다.

	   2번과 3번이 중요하다.
	   2번 -> 지점, 거리, ... 의 값이 주어진다고 하여도 시작값은 1인 경우가 많다
			(현재까지 푼 문제중 -> 시작 값을 arr[0]으로 주어 틀린적이 많다.)
	   3번 -> 위에서 말한 target과 비교가 필요한 값을 찾는게 중요하다는 것
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	long long st = 1, en = arr[n - 1] - arr[0];
	while (st <= en) {
		long long mid = (st + en) / 2;
		int cnt = 1;
		long long now = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] - now >= mid) {
				cnt++;
				now = arr[i];
			}
		}

		if (cnt < c) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << en;
}