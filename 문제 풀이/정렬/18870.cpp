/*
작성자 : 이상수
일시 : 2021.04.09
제목 : 좌표 압축 - 18870
풀이 : 정렬을 사용하고 추가적으로 생각이 필요한 문제
       어떤 수열이 주어질 때 특정 수 보다 작은 수가 수열 내에 몇개 있는지 찾는 문제이다.
	   접근 방식은 다음과 같다.

	   1. 벡터에 숫자, 인덱스 로 입력 받는다.
	   2. 벡터를 오름차순으로 정렬한다.
	   3. 정렬된 벡터를 가지고 처리하여 다른 벡터에 저장한다. (처리 방식은 아래 따로 설명)
	   4. 처음 입력받은 인덱스를 가지고 해당하는 위치에 값들을 넣는다.

	   처리 방식
	   숫자 2 4 -10 4 -9 가 있다고 할 때 위 과정을 따라가면
	   1. (2, 0), (4, 1), (-10, 2), (4, 3), (-9, 4)
	   2. (-10, 2), (-9, 4), (2, 0), (4, 1), (4, 3)
	   3. 처음 숫자는 자신보다 작은 수가 없기 때문에 0이 된다.
	     3-1. 앞의 수와 같다면 앞의 저장 값을 가져온다.
	     3-2. 앞의 수와 다르다면 cnt값을 1 증가하고 그 값을 저장한다.
	   4. 2번의 인덱스 값을 가지고 3에서 정리한 값들을 위치에 맞게 저장한다.

	   이렇게 처리하면 처리가 완료된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back({ num, i });
	}
	sort(arr.begin(), arr.end());
	vector<int> tmp(n);
	int cnt = 0;
	tmp[0] = cnt;
	for (int i = 1; i < n; i++) {
		if (arr[i].first == arr[i - 1].first) 
			tmp[i] = tmp[i - 1];
		else {
			cnt++;
			tmp[i] = cnt;
		}
		
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) 
		ans[arr[i].second] = tmp[i];
	
	for (int i : ans)
		cout << i << ' ';
}