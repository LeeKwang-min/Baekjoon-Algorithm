/*
작성자 : 이상수
일시 : 2021.04.08
제목 : 개똥벌레 - 3020
풀이 : 누적합을 사용하는 문제라고 하는데... 처음에 정말 갈피를 못잡았다.
       누적합을 어떻게하면 문제에 적용이 가능할까 라는 생각이 들었고
	   그에 대해 고민을 하다보니 한가지 틀에 박혀서 생각하고 있었다.

	   우선 접근 방식은 다음과 같다.
	   1. 종유석과 석순은 순차적으로 반복되며 주어지기 때문에 두 값을 따로 배열로
	   만들어서 받아낸다.
	   2. 종유석이나 석순의 길이가 n이라고 할 때, 해당 종/석은 길이가 n이상인 모든 
	   장소에 영향을 끼친다.
	   3. 최종적으로 높이가 h일 때 걸리는 장애물의 개수를 구하면 된다.

	   1번의 접근은 배열을 두개 따로 만들어 값을 받아오면 된다.

	   2번의 접근은 여기서 누적합이 사용되는데, 
	   arr[n] = 높이 n일 때 걸리는 장애물의 개수 라고 한다면
	   arr[n] = arr[n + 1] 이 된다.
	   (자신의 높이 이상인 모든 장애물에 영향을 받기 때문에)
	   이 처럼 누적합을 사용하여 걸리는 것들의 개수를 받아오면 된다.

	   3번의 접근은 2번에서 구한 누적 합에서
	   총 높이가 L이고 현재 높이가 h일 때,
			1) 걸리는 아래서 올라오는 장애물의 개수와
			2) 걸리는 위에서 내려오는 장애물의 개수 합과 같다.
	   걸리는 장애물의 총 개수는 sum[h] = bottom[h] + top[L - h + 1]

	   이 중 가장 작은 값을 구하고 개수를 구하여 출력 해주면 된다.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, h;
long long arr_bottom[500001];
long long arr_top[500001];
long long sum[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> h;
	n = n / 2;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		arr_bottom[num1]++;
		arr_top[num2]++;
	}

	for (int i = h - 1; i >= 0; i--) {
		arr_bottom[i] += arr_bottom[i + 1];
		arr_top[i] += arr_top[i + 1];
	}
	
	int ans = 987654321;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		sum[i] = arr_bottom[i] + arr_top[h - i + 1];
		if (ans > sum[i])
			ans = sum[i];
	}

	for (int i = 1; i <= h; i++) {
		if (ans == sum[i])
			cnt++;
	}

	cout << ans << ' ' << cnt;
}