/*
작성자 : 이상수
일시 : 2021.02.10
제목 : 수들의 합 2 - 2003
풀이 : 투포인터를 사용하는 간단한 문제
	   투포인터의 개념을 공부하기 좋은 문제이다.

	   투포인터를 적용 가능한 문제는 구간합을 구하거나 비슷한 문제일 때 가능하다.

	   핵심을 알아두자.
*/
#include <iostream>

using namespace std;

int n, m;
int num[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int cnt = 0, sum = 0;
	int s = 0, e = 0;
	while (1) {
		if (sum >= m) sum -= num[s++]; // 더한 값이 구하고자 하는 값보다 크다면 start를 빼주고 1 증가
		else if (e == n) break; // end가 n과 같아지면 끝까지 간것이기 때문에 종료
							    // s를 n까지 증가시킨 다음 종료해도 된다.
		else sum += num[e++]; // 위 2가지에 해당하지 않는 구하는 값보다 작고 e가 n이 아니라면 e를 증가
		if (sum == m) cnt++; // 답이라면 count값 증가
	}
	cout << cnt;

}


/*
투포인터 알고리즘 핵심
int cnt = 0, sum = 0;
	int s = 0, e = 0;
	while (1) {
		if (sum >= m) sum -= num[s++];
		else if (e == n) break;
		else sum += num[e++];
		if (sum == m) cnt++;
	}
*/