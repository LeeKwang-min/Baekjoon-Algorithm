/*
작성자 : 이상수
일시 : 2021.02.24
제목 : 2 X n 타일링 - 11726
풀이 : 점화식 = D[N] = 2 X N 직사각형을 채우는 방법의 수
       위 점화식으로 두고 생각하면

	   가장 작은 단위인
	   2 X 1 = 1 (가로 직사각형 하나만 가능)
	   2 X 2 = 2 (가로 + 가로, 세로 + 세로 가능)

	   이 다음부터는 
	   2 X 3 부터 생각해보면
	   2 X 2 크기에 2 X 1 하나를 붙인 경우 와
	   2 X 1 크기에 1 X 2 두개를 붙여 2 X 2를 붙인 경우로 나눠 볼 수 있다.

	   2 X N 또한 마찬가지 이며 이를 이용하여 점화식을 완료하면
	   D[N] = D[N-2] + D[N-1] 이 된다.
*/
#include<iostream>

using namespace std;

int n;
int d[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	d[1] = 1; d[2] = 2;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 2] + d[i - 1]) % 10007;
	cout << d[n];
}