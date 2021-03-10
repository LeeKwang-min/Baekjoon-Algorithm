/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 부분수열의 합 2 - 1208
풀이 : MITM 문제 (Meet In The Middle)
       절반 크기의 비슷한 문제를 두 번 해결한 결과를 통해 본 문제를 해결하는 문제

	   이 문제에서 주어지는 최대 n은 40으로 부분수열을 모두 구해서 그 결과를 
	   확인하기에는 주어진 시간이 그만큼 많지 않다.

	   그렇기 때문에 주어진 수열을 반으로 나누어 반틈 반틈의 각각 나올 수 있는
	   수열의 합을 나타내어준다.
	   이 합 벡터를 통해 구하고자 하는 값이 나올 수 있는지 확인하도록한다.

	   first = 0 ~ n/2 까지의 수열로 나올 수 있는 합들
	   second = n/2 ~ n 까지의 수열로 나올 수 있는 합들

	   이 두 값을 가지고 
	   first는 오름차순
	   second는 내림차순 정렬을 해주고
	   투 포인터 알고리즘을 사용한다.

	   first의 요소와 second의 요소의 합이 s라면
	   이 때 first에서 구한 부분 수열과 second에서 구한 부분수열을 합치면
	   합이 s를 만족하는 부분 수열이 되기 때문에
	   ans를 추가해주면 된다.

	   여기서, 만약 구한 요소와 같은 값을 가지는 것들이 있다면 한번에 처리해주고
	   그 값은 c1, c2를 통해 구한 다음 두 값을 곱하여 총 갯수를 구해준다.

	   만약 두 합이 s보다 작다면 first의 선택자를 증가시키고  (값 증가)
	   두 합이 s보다 크다면 second의 선택자를 증가시키면 된다 (값 감소)

	   만약 구해야하는 s가 0이라면 우리가 구한 값이
	   공집합도 포함되어 있기 때문에 -1을 하여 공집합끼리의 합을 제외해주어야 한다.
	   (문제에서 크기가 양수인 부분집합을 구하라고 하였기 때문)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// N => n-m | m 으로 나눈다.
	int m = n / 2;
	n = n - m;

	// 2^n 크기의 배열을 모두 0으로 채운다.
	// 길이가 n인 수열로 만들 수 있는 모든 부분집합의 개수 = 2^n
	vector<int> first(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				first[i] += a[j];
		}
	}

	vector<int> second(1 << m);
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			if (i & (1 << j))
				second[i] += a[j + n]; // m = 뒷부분
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	n = (1 << n);
	m = (1 << m);

	int st = 0, en = 0;
	long long ans = 0;
	while (st < n && en < m) {
		if (first[st] + second[en] == s) {
			long long c1 = 1;
			long long c2 = 1;
			st++; en++;
			while (st < n && first[st] == first[st - 1]) {
				c1++;
				st++;
			}
			while (en < m && second[en] == second[en - 1]) {
				c2++;
				en++;
			}
			ans += c1 * c2;
		}
		else if (first[st] + second[en] < s) {
			st++;
		}
		else {
			en++;
		}
	}
	if (s == 0) ans -= 1;
	cout << ans;
}