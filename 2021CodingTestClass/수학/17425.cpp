/*
작성자 : 이상수
일시 : 2021.02.15
제목 : 약수의 합 - 17425
풀이 : 약수의 합 2 문제와 같은 문제이지만 테스트 케이스가 주어져서 
       테스트 케이스의 수만큼 시간 복잡도가 늘어나게 된다.

	   이 때문에 약수의 합 2 문제와 똑같이 풀게되면 시간 초과가 나게 된다.

	   이 문제에서는 f(n)을 모두 구해두고(20 ~ 25 줄)
	   그 뒤에 g(n)을 누적 합으로 구하는(28 ~ 31 줄) 방식을 사용한다.

	   일종의 메모라이제이션 방식인데 
	   f(n)을 구할 때
	   1 ~ n 까지의 모든 수들은 1을 약수로 가지기 때문에
	   vector를 초기화 할 때 1로 초기화 하여 반복문의 시작이 2이다.
	   i*j의 값에 i를 추가하는 이유는
	   2의 배수라고 하면 2, 4, 6, 8, ... 이며 이 값들이 n일때
	   모두 2를 약수로 가지기 때문에 +2 를 해주면 된다.

	   이렇듯 반복문의 조건식에 변화를 주어 O(nlgn) 으로 풀이가 가능하다.

	   그 뒤에 누적합을 더해주고 그 값으로 각 테스트 케이스에 대해 출력해준다.
	   
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<long long> arr(1000001, 1);
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 1; j * i <= 1000000; j++) {
			arr[i*j] += i;
		}
	}

	vector<long long> sum(1000001, 0);
	for (int i = 1; i <= 1000000; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}
}