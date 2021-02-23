/*
작성자 : 이상수
일시 : 2021.02.23
제목 : 로또 - 6603
풀이 : 이 문제는 재귀와 순열을 이용하여 풀이가 가능한 브루트 포스 문제이다.
       우선 말할것은 순열보다는 재귀가 더 좋은 방법이라고 한다.

	   아래 주석 코드는 재귀를 이용하여 푼 코드이고
	   본문의 코드는 순열을 이용하여 푼 코드이다.

	   순열을 이용하여 푸는 방법은 
	   N개의 수가 주어질 때 6개를 선택하여야 하기 때문에
	   N개 중 6개에 선택했다는 표시를 남기고
	   N - 6개에 선택하지 않았다는 표시를 남겨서 사용한다.

	   선택한 숫자는 1
	   선택하지 않은 숫자는 0을 준다.

	   0과 1로 이루어진 벡터나 배열을 순열을 돌며 처리하고
	   1인 부분만 확인하여 따로 값을 넣어준다.
	   값을 넣고 사전순 출력을 위해 정렬을 해주고 출력해주면 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		
		vector<int> num(n); // 숫자
		for (int i = 0; i < n; i++)
			cin >> num[i];

		vector<int> a; // 고름 = 1 고르지 않음 = 0
		for (int i = 0; i < n - 6; i++)
			a.push_back(0);

		for (int i = 0; i < 6; i++)
			a.push_back(1); 

		vector<vector<int>> answer;
		do {
			vector<int> ans; // 고른 수가 담길 벡터
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) ans.push_back(num[i]);
			}
			answer.push_back(ans);
		} while (next_permutation(a.begin(), a.end()));
		sort(answer.begin(), answer.end());
		for (auto v : answer) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}

/*
#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[14];
int num[14];

void go(int k, int st) {
	if (k == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < n; i++) {
		arr[k] = num[i];
		go(k + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0) break;

		fill(arr, arr + 14, 0);
		fill(num, num + 14, 0);
		for (int i = 0; i < n; i++)
			cin >> num[i];

		go(0, 0);
		cout << '\n';
	}
}
*/

// 이 부분은 처음 순열을 반복하고자 할 때 매 순열마다 출력해주는 방식을 선택했는데,
// 이 코드를 사용하면 선택된 숫자만 가지고 정렬을 진행 후 출력하기 때문에 문제가 된다.
// 예를 들어 말하자면 1 2 3 4 5 6 7 의 숫자가 있을 때
// 2 3 4 5 6 7 이 먼저 나오고
// 1 2 3 4 5 6 이 나올 가능성이 있다는 말이다.
/*
		do {
			vector<int> ans; // 고른 수가 담길 벡터
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) ans.push_back(num[i]);
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
			cout << '\n';
			answer.push_back(ans);
		} while (next_permutation(a.begin(), a.end()));
*/