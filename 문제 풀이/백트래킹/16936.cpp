/*
작성자 : 이광민
일시 : 2021.06.22
제목 : 16936 - 나3곱2
풀이 : 주어진 숫자들의 수열은 정상적인 수열의 재배열이기 때문에
       모든 수들은 서로 3으로 나누어 떨어지거나 2로 곱해져서 나온 수이다.

	   처음에는 next_permutation을 통해 모든 수열을 확인하려고 했으나 N이 최대 100이기 때문에 시간초과가 생겼다.

	   이를 해결하기 위해 수학적으로 계산하면 다음과 같다고 한다.

	   주어진 수열을 소인수분해 하여 나타내면
	   이 수들은 3^n * 2^m * ... 과 같이 나타나게 된다.
	   이 때 구하고자 하는 정상적인 수열을 나타내기 위해서는
	   나누기 3 = 3의 n이 줄어드는 방향
	   곱하기 2 = 2의 m이 증가하는 방향 으로 처리하면 된다.

	   즉, 3의 제곱수가 같다면 값들이 증가하는 방향으로 처리하고
	   3의 제곱수가 다르다면 3의 제곱수가 감소하는 방향으로 처리하면 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
long long arr[101];
vector<pair<long long, long long>> v;

bool chk(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
		long long mod = 0;
		while (num % 3 == 0) {
			mod++;
			num /= 3;
		}
		v.push_back({mod, arr[i]});
	}

	sort(v.begin(), v.end(), chk);
	for (int i = 0; i < v.size(); i++) 
		cout << v[i].second << ' ';
	
	return 0;
}