/*
작성자 : 이광민
일시 : 2021.06.03
제목 : 12886 - 돌 그룹
풀이 : 최대 1000까지 올라가는 값들을 모두 배열로 나타내는 경우 A[1000][1000][1000] = 10억의 시간 복잡도, 4GB메모리 가 걸리기 때문에 불가능하다.
       
	   그렇기 때문에 3가지 모두를 배열로 나타내지 않고 
	   A, B, C의 합은 언제나 일정하다는 특징을 사용하여 2가지의 돌만 나타내도록 한다 (A, B만)

	   최소한의 횟수를 구하는것이 아니라 가능한지 불가능한지만 알아내면 되는 문제이기 때문에
	   BFS와 DFS 둘 다 풀이가 가능하다.
	   이 풀이는 DFS를 사용한 풀이이다.

	   함수에 들어오는 x와 y를 a와 b의 돌 개수라고 생각하고
	   arr배열에 x, y, z(sum-x-y)를 저장한다.
	   그 다음 각 경우에 대해 비교하며
	   x < y // x < z // y < z // y < x // z < x // z < y 가 되는지 확인한다 
	   (x x, y y, z z인 경우는 그냥 넘어가니 예외로 두자)
	   각 경우에 대해 그 값의 변화를 막기 위해 별도의 brr 배열을 두어 계산하도록 하고
	   그 값들을 다음으로 넘긴다. (x, y, z에서 -> x와 y에 그 값들이 변한다고 하여도 z에는 변화가 없고 다른 경우도 마찬가지이기 때문에 넘기는 값은 brr[0], brr[1]만 넘겨주면 된다)
	   이렇게 값들을 확인하며 chk의 값을 변화 시키고
	   chk[sum/3][sum/3]이 참이라는 것은 a, b, c 모두 sum/3이 된다는 말이기 때문에 결과는 참이된다.

	   a, b, c돌의 개수 합이 3의 배수가 아니라면 이는 무조건 불가능한 경우다 (딱 맞아 떨어지지 않기 때문)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;
int sum;
bool chk[1501][1501];

void go(int x, int y) {
	if (chk[x][y]) return;
	chk[x][y] = true;
	int arr[3] = { x, y, sum - x - y };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i] < arr[j]) {
				int brr[3] = { x, y, sum - x - y };
				brr[i] += arr[i];
				brr[j] -= arr[i];
				go(brr[0], brr[1]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	go(a, b);
	if (chk[sum / 3][sum / 3])
		cout << 1;
	else
		cout << 0;
}
