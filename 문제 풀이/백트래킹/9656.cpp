/*
작성자 : 이광민
일시 : 2021.06.30
제목 : 9656 - 돌 게임 2
풀이 :  N이 짝수라면 무조건 상근이가 이기고
	   홀수라면 무조건 창영이가 이기는 문제이다.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n % 2 == 0) cout << "SK";
	else cout << "CY";
}