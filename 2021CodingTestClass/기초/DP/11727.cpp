/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 2 X n 타일링 2 - 11727
풀이 : 2 X n 타일링 문제와 다른 점은 
       채울 수 있는 타일로 2 X 2 가 생겼다는 점 하나이다.

	   앞의 문제와 유사하게 2 X n 크기의 직사각형을
	   2 X (n-?) 를 2 X 1, 1 X 2, 2 X 2를 붙이는 경우를 생각하면 된다.
	   2 X 2가 생겼지만, 1 X 2를 2개 붙인 경우와 똑같다.

	   그렇기 때문에 점화식은 다음과 같다
	   D[N] = 2 * D[N-2] + D[N-1]

	   정답은 나머지로 넣어주는것을 잊지 말자
*/
#include<iostream>

using namespace std;

int n;
int d[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	d[1] = 1; d[2] = 3;
	for (int i = 3; i <= n; i++)
		d[i] = ((2 * d[i - 2]) + d[i - 1]) % 10007;
	cout << d[n];
}