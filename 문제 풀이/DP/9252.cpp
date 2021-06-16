/*
작성자 : 이광민
일시 : 2021.06.08
제목 : 9252 - LCS 2
풀이 : LCS의 문자열이 무엇인지 구하는 LCS 문제에서 역추적이 들어간 문제
       LCS 부분은 9251-LCS 에서 자세하게 했으니 넘어가고 

	   역추적에 대해 설명하자면

	   브루트포스, BFS, DP 모두 역추적이란 "어떤 값이 왜 바뀌었는지를 저장"한다.


	   이 문제에서 내가 푼 방식은 역추적이 아니라 해당 값들을 저장하고 가져오는 방식을 사용하였고, 그 방식은 다음과 같다.
	   string 배열을 생성하여 DP를 구할 때 똑같이 이 전의 문자열이 무엇이였는지 가지고 오는 방식을 사용한다.

	   즉, 같을때와 같지 않을때를 비교하는데,
	   같은 경우에만 문자열의 길이가 늘어나고
	   같지 않은 경우에는 문자열의 길이에 변화가 없기 때문에 이 전의 값을 그대로 가져오면 된다.

	   같은 경우 -> string[n][m] = string[n-1][m-1] + a[n-1] (a[n-1]을 가져오는 이유 -> string의 n-1은 n-1번째 라는 것이고 a[n-1]은 n번째 값이 저장된 곳이 n-1 인덱스이기 때문이다)
	   같지 않은 경우 -> d[n-1][m]과 d[n][m-1]중 어떤 값을 가져오냐에 따라 
	   string[n][m] = string[n-1][m] OR string[n][m-1]

	   이 문제를 역추적 방식으로 풀려면
	   2차원 int 배열 v를 생성한다.
	   v에 
	   - a[i]와 b[i]가 같은 경우 ---> 1
	   - a[i]와 b[i]가 같지 않은 경우 ---> 2, 3 을 저장한다   (2와 3은 어떤 값이 더 큰지 비교하여)

	   위에서 말 했듯이 문자열의 길이가 늘어나는 경우는 두 문자가 같은 경우 뿐이므로
	   ans = "", n = a.length(), m = b.length()로 두고
	   v[n][m]에서 시작하여
	   - 1이면 a[n]을 ans에 저장하고 n과 m을 1씩 감소
	   - 2면 n을 1 감소
	   - 3이면 m을 1감소
	   위와 같이 처리하여 이 값은 역순으로 저장되어 있기 때문에
	   reverse 함수를 사용하여 문자열을 돌려준다.
	   (문자는 인덱스값, v의 값은 순서의 값 -> 즉, 문자를 추가할 때에는 n번째 값 ==> n-1 인덱스이다. (주의))


	   역추적 방식이 문자열 배열을 사용하는것 보다 훨씬 빠르다.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int d[1001][1001];
//string ans[1001][1001];
int v[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
				//ans[i][j] = ans[i - 1][j - 1] + a[i - 1];
				v[i][j] = 1;
			}
			else {
				if (d[i][j - 1] < d[i - 1][j]) {
					d[i][j] = d[i - 1][j];
					//ans[i][j] = ans[i - 1][j];
					v[i][j] = 2;
				}
				else {
					d[i][j] = d[i][j - 1];
					//ans[i][j] = ans[i][j - 1];
					v[i][j] = 3;
				}
			}
		}
	}

	string tmp = "";
	int n = a.length();
	int m = b.length();
	while (n > 0 && m > 0) {
		if (v[n][m] == 1) {
			tmp += a[n - 1];
			n--; m--;
		}
		else if (v[n][m] == 2) {
			n--;
		}
		else {
			m--;
		}
	}
	reverse(tmp.begin(), tmp.end());
	cout << d[a.length()][b.length()] << '\n';
	//cout << ans[a.length()][b.length()];
	cout << tmp;
}