/*
작성자 : 이상수
일시 : 2021.02.18
제목 : N과 M (2) - 15650
풀이 : 기존 N과 M (1) 코드에서 함수의 인자로 전달하는 값이
	   하나가 늘었고 그 값의 역할은 
	   1 ~ N 반복이던것이 
	   이전 선택값 + 1 ~ N 까지로 바뀌었다.
	   이 값을 통해 반복문을 실행하며 그 값들을 가져온다.

	   실제로는 이 코드에서는 사용 여부를 확인하는 chk배열과 조건문 부분이 필요없다.
	   왜냐하면 실제로 값을 검사하는 부분이 이전 값의 다음 값부터 검사하기 때문이다.
*/
#include<iostream>

using namespace std;

int n, m;
int arr[9];
bool chk[9];

// 경우로 풀이한 브루트 포스
void bf_other(int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		arr[k] = i;
		bf_other(k + 1, i + 1);
		chk[i] = false;
	}
}

// 선택으로 풀이한 브루트 포스
void bf_select(int num, int select) { // index = 현재 수, select = 선택한 수의 개수
	if (select == m) { // 선택이 끝났다면 (m개를 골랐다면) 출력
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	if (num > n) return; // 선택을 마치지 못했는데 수가 n을 넘어갔다면 더이상 수가 없다는 뜻이므로 종료
	arr[select] = num; // 수 선택
	bf_select(num + 1, select + 1); // 숫자 + 1(다음 수), 선택 갯수 + 1
	arr[select] = 0; // 수 선택 X
	bf_select(num + 1, select); // 숫자 + 1, 선택 갯수 유지
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf_other(0, 1);
}