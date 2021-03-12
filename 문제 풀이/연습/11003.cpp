/*
작성자 : 이상수
일시 : 2021.03.13
제목 : 최소값 찾기 - 11003
풀이 : 덱을 사용하여 푸는 슬라이딩 윈도우 문제이다.
       최소값을 찾기 위해
	   덱에 저장하는 값은
	   실제 값, 인덱스 의 pair 구조이다.

	   1 5 6
	   0 1 2 이 들어와 이있다면
	   다음 인덱스인 3이 들어올 때 2가지로 나뉜다.

	   만약 6보다 큰 값이 들어오면
	   가장 앞의 1을 pop 해주고 다음 값을 넣어주면 된다.

	   만약 5와 6보다 작은 값이 들어온다면
	   우선 가장 앞의 인덱스 0인 1값을 pop 해주고
	   2가 들어왔다고 가정을 한다면
	   앞으로 2가 빠져나가기 전이나 2보다 작은 값이 들어오지 않는다면
	   가장 작은 값은 2가 되기 때문에
	   덱에서 2보다 큰 값들을 제거해준다. 즉
	   최종적으로
	   2
	   3 이 남게 된다.

	   이 후에 진행하며 3이 i - L 즉 주어진 범위를 넘어섰다면 빼내고
	   2보다 작은 값이 들어오면 해당 값을 지워준다.

	   이렇게 처리했을 때 항상 남는 값은 덱의 가장 앞이 가장 작은 값이다.
*/
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	deque<pair<int, int>> dq;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		if (!dq.empty() && dq.front().second <= i - l)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > x)
			dq.pop_back();

		dq.push_back({ x, i });
		ans[i] = dq.front().first;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}