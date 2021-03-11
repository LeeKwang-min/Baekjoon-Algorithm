/*
작성자 : 이상수
일시 : 2021.03.10
제목 : 두 배열의 합 - 2143
풀이 : 한쪽과 다른 한쪽을 조건에 맞게 구하여 더한 값이 정답인 것을 고르는 문제이기 때문에
       이 문제는 MITM 문제이다.

	   연속된 배열의 합이기 때문에 누적합을 사용하여 N^2 안에
	   연속된 배열들의 합을 구하여 first와 second에 넣어주고

	   그 값을 MITM을 통해 조건을 만족하는 값을 구해주면 된다.1`
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m;
	cin >> t;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int nsize = 0;
	int msize = 0;

	vector<int> first;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += a[j];
			first.push_back(tmp);
		}
	}

	vector<int> second;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		for (int j = i; j < m; j++) {
			tmp += b[j];
			second.push_back(tmp);
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<int>());

	int st = 0, en = 0;
	long long ans = 0;
	while (st < first.size() && en < second.size()) {
		if (first[st] + second[en] == t) {
			long long c1 = 1;
			long long c2 = 1;
			st++; en++;
			while (st < first.size() && first[st] == first[st - 1]) {
				c1++;
				st++;
			}
			while (en < second.size() && second[en] == second[en - 1]) {
				c2++;
				en++;
			}
			ans += c1 * c2;
		}
		else if (first[st] + second[en] < t) {
			st++;
		}
		else {
			en++;
		}
	}

	cout << ans;
}