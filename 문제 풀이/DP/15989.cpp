/*
작성자 : 이광민
일시 : 2021.05.31
제목 : 15989 - 1,2,3 더하기 4
풀이 : 동전 1, 2 문제와 매우 유사한 문제이다.
       동전 문제를 풀지 않았다면 많이 해맸을 문제

	   어떤 가지수를 사용하여 특정 값 혹은 상황을 만들 때 해당 값이 중복이 되면 안되는 (동일한 구성) 문제의 경우
	   이 풀이법이 사용되는것 같다.

	   이 문제는 1, 2, 3을 이용하여 특정 수 n을 만드는 문제이다.
	   1만 사용하여 n을 만드는 방법을 구하고
	   2를 포함하여 n을 만드는 방법을 구하고
	   3을 포함하여 n을 만드는 방법을 차례대로 구하면 되는 문제이다.

	   10을 만든다고 가정하며
	   1로만 구성된 경우
	   1+1+1+1+...+1 로서 1만 사용하여 만드는 방법 1가지

	   2를 섞을 경우 작은 수부터 차례대로 구하면 된다. 
	   -> 1로만 이루어진 8에 2 더하기 -> 8은 1로만 이루어진 6에 2더하기 -> 6은 1로만 이루어진 4에 2더하기 -> ... 

	   3도 2와 마찬가지로 작은 수부터 차례대로 구하면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int t;
int num[3] = { 1, 2, 3 };
int d[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	d[0] = 1;
	for (int i = 0; i < 3; i++) 
		for (int j = num[i]; j <= 10000; j++) 
			d[j] += d[j - num[i]];
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}