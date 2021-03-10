#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// a = 현재 순열 / n = 순열의 길이
// return true = 다음 순열이 있다.
// return false = 다음 순열이 없다.
// 함수가 bool 타입인 이유 = 함수가 false일 때까지 계속해서 함수를 호출하면 된다.
// 다음 순열이 없다 = 마지막 순열이다 = 내림차순이다. (i가 0이 되었는데도 값이 없다)
bool next_permutation_implement(int *a, int n) {
	// 순열의 뒤에서부터 값을 찾아서 내려감
	int i = n - 1;

	// i가 0보다는 크고 비내림차순(>=)을 만족하는 동안 반복하면 i를 감소
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;

	// i가 0이라면 모든 수가 비오름차순이기 때문에 마지막 순열이라는 말이다.
	if (i <= 0) return false;

	// A[i-1]보다 크면서 가장 오른쪽에 있는 j 찾기
	int j = n - 1;

	// A[i-1] 보다 큰 수(작거나 같지 않다)중 가장 작은 수 이므로 (<=)
	// A[j]가 A[i-1]보다 작거나 같은 동안에 j 감소 (순서 = A[0], A[1], .. A[i-1], .. , A[j], ..)
	while (a[j] <= a[i - 1]) j -= 1;

	// 두 수 SWAP
	swap(a[i - 1], a[j]);

	// A[i]부터 뒤집기
	// 1 2 3 4 를 뒤집는다 -> 1 - 4 교환 , 2 - 3 교환 하면 된다.
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// next_permutation 함수 사용
	// 위에서 구현한 함수와 동일한 메커니즘이다.
	// 모든 순열을 구하고 싶다면 while문을 사용하면 된다.
	// 만약 vector가 아닌 int a[5] 였다면 (a, a+5)로 사용하면 된다.
	if (next_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else {
		cout << "-1";
	}
}

// 다음 순열 구하는 방법
/*
	다음 순열 = 어떠한 수로 시작하는 마지막 순열
			  = 어떠한 수를 제외하면 비오름차순으로 정렬되어있음

	1. 순열의 뒤에서부터 A[i-1] < A[i]인 가장 큰 i를 찾는다.
	
	2. A[i-1] < A[j]인 가장 큰 j를 찾는다 (i <= j : i ~ size() - 1 까지 중에서)
	 ㄴ 비오름차순이기 때문에 조건을 만족하는 가장 오른쪽 값을 찾으면 됨

	3. A[i-1] 과 A[j] SWAP

	4. A[i] ~ A[size() - 1] 까지 순열 뒤집기
	 ㄴ 뒤집을 때 1 2 3 4 와 같은 순열이 있다면 
		1 - 4, 2 - 3 을 SWAP 해주면 됨

	5. 완성



	이전 순열 = 다음 순열 구하는 방법의 부등호를 바꾸는 것과 같다.

	모든 순열 = do{ ... } while(next_permutation()) 으로 처리
	 ㄴ do ~ while 인 이유 = 가장 처음 가지고 있는 순열을 처리해야 하기 때문
		(처음 순열이 마지막 순열이여도 이 또한 순열이기 때문이다.)
*/