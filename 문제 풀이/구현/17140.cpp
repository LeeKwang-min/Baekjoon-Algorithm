/*
작성자 : 이광민
일시 : 2021.06.07
제목 : 17140 - 이차원 배열과 연산
풀이 : 몇가지 문제를 해결하지 못해서 결국 해답을 보고 풀었다.
       
	   해결하지 못한 것
	   1. arr의 시작 인덱스는 1, 내가 후처리를 위한 벡터 저장 데이터의 인덱스는 0부터 시작
	   2. 기존 배열의 재할당
	   3. 행과 열의 최대 크기 구하기 (해결은 하였으나 비효율적)

	   왜 해결하지 못했나
	   1. 이 경우 쉽게 주어지는 r과 c를 1씩 감소시키고 처리했으면 간단한건데 그러지 못했다.
	   2. '재할당'이라는 말에 고정관념적으로 무조건 기존 배열을 사용하여 바꾸어야 한다는 생각이 강했다.
	   3. 새로운 반복문을 통해 그 과정을 처리했는데 매번 그 과정이 필요하고 복잡했다.

	   해결한 방법 (해답 코드를 통해 해결)
	   1. 위에서 말한것 처럼 처음부터 감소시키고 시작하면 간단하다.
	   2. 재할당의 경우 기존의 값을 바꾸는 부분과 그렇지 않은 부분이 존재한다.
	      나의 경우 변경하지 않는 부분의 처리를 무조건 배열에서 지워야 한다는 고정관념이 있었는데, 이 지운다는 것을 너무 어렵게 생각했다.
		  '지운다 => 기본 값으로 바꾼다' 라는 팁을 통해 해결하였다.
	   3. 이 또한 처리를 간단하게 하기 위해 구현과정에서 바로바로 최대 값을 찾아버리는 방식이 있어 사용하였다.

	   자세한 코드 설명은 아래 코드의 주석으로 달아두었다.

	   고정관념에서 벗어나고 새로운 시선을 필요로 하자.
	   (너무 안 풀리면 잠시 딴생각하고 다시 보던가 하자)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int arr[101][101];
int n = 3, m = 3;

void r_func() {
	int mm = m; // 행의 갯수가 바뀔 수 있기 때문에 새 변수를 할당한다.
	for (int i = 0; i < n; i++) {
		// 각 수가 몇번 나오는지 체크하기 위해 사용하는 배열
		// map을 사용하면 보기 좋게 처리가 가능하다.
		// map<int, int> d ---> d[arr[i][j]]++;
		int cnt[101];
		// 배열 초기화
		for (int j = 1; j <= 100; j++)
			cnt[j] = 0;

		// 값들 확인하며 0이 아니라면(값이 있다면) 카운트 증가
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) continue;
			cnt[arr[i][j]]++;
		}

		// (등장 횟수, 수)로 저장되어 있는 벡터
		// 순서를 위와 같이 하면 한번의 라이브러리 정렬 함수로 문제에서 요구하는 정렬이 수행된다.
		vector<pair<int, int>> v;

		// 만약 map을 사용한다면
		// for(auto &p : d){ p.first, p.second; } 로 처리하면 된다.
		for (int j = 1; j <= 100; j++) {
			if (cnt[j] != 0) {
				v.push_back({ cnt[j], j });
			}
		}
		sort(v.begin(), v.end());

		// 크기가 100을 넘을 경우 앞부분의 100개를 제외하고 모두 버려야 하기 때문에 
		// pair로 되어있는 값의 특성으로 최대 50까지 범위를 구하도록 한다.
		int l = min((int)v.size(), 50);
		for (int j = 0; j < l; j++) {
			arr[i][j * 2] = v[j].second; // 0 2 4 6 8 10 ...
			arr[i][j * 2 + 1] = v[j].first; // 1 3 5 7 9 11 ...
		}

		// 남은 공간은 모두 0으로 채워준다
		// 기본적으로 다시 할당하는것이 맞지만, 재할당이 더 오래 걸리고 복잡하기 때문에 0으로 채워 넣어준다.
		// 위에서 만약 100이 넘어 50이 된다면 실행되지 않는다.
		for (int j = l * 2; j < 100; j++)
			arr[i][j] = 0;

		// 새로운 행의 갯수를 다시 구해준다.
		// 이 부분을 잘 이해하지 못했었다.

		// v.size() * 2 는 행에 저장될 수의 개수를 뜻한다.
		// mm은 현재 행의 개수(수의 개수)이다.
		// '현재 행의 개수'보다 '새롭게 저장될 행의 개수'가 더 크다면 (다시 말해 크기가 증가되어야 한다면)
		// 현재 행의 개수를 늘려준다
		// 이를 끝까지 진행하면 가장 큰 개수를 가지는 행이 자동으로 mm에 저장되고 아래에서 m의 값을 바꿔주어 계속해서 탐색이 되도록한다.
		if (mm < (int)v.size() * 2)
			mm = (int)v.size() * 2;
	}
	m = mm;
}

// r_func와 같다. 
// (행, 열의 기준이 바뀌지만 반복문에서 i와 j의 위치를 바꾸어 본 코드와 크게 다를것 없이 처리가 가능하다)
void c_func() {
	int nn = n;
	for (int j = 0; j < m; j++) {
		int cnt[101];
		for (int i = 1; i <= 100; i++)
			cnt[i] = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 0) continue;
			cnt[arr[i][j]]++;
		}

		vector<pair<int, int>> v;
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] != 0) {
				v.push_back({ cnt[i], i });
			}
		}
		sort(v.begin(), v.end());
		int l = min((int)v.size(), 50);
		for (int i = 0; i < l; i++) {
			arr[i * 2][j] = v[i].second;
			arr[i * 2 + 1][j] = v[i].first;
		}

		for (int i = l * 2; i < 100; i++)
			arr[i][j] = 0;

		if (nn < (int)v.size() * 2) 
			nn = (int)v.size() * 2;
	}
	n = nn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> k;
	r -= 1;
	c -= 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	if (arr[r][c] == k) {
		cout << 0;
		return 0;
	}

	for (int t = 1; t <= 100; t++) {
		if (n >= m) r_func();
		else c_func();
		if (arr[r][c] == k) {
			cout << t;
			return 0;
		}
	}

	cout << -1;
	return 0;
}