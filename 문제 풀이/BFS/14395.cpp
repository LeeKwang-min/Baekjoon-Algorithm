/*
작성자 : 이광민
일시 : 2021.06.16
제목 : 14395 - 4연산
풀이 : 이 문제는 최대 10억까지 가기 때문에 만약 일차원 배열을 선언할 경우 그 공간이 너무나도 많이 요구된다.
       이런 문제를 풀때 map이나 set을 사용하면 된다. (중복을 피하기 때문에 set도 좋다)
	   map과 set은 key를 기준으로 처리가 되기 때문에
	   공간을 특정하거나 모두 정하기 힘든 경우에는 이를 사용하면 된다.

	   각 경우를 표현하자면
	   q<ll, string> -> 현재 값과 해당 값까지 오는데 필요한 연산들이 저장된 큐
	   m<ll, int> -> 일반 bfs의 chk 역할을 하는 map

	   bfs 탐색을 하면서 
	   m[i]가 0이거나 (탐색 한적이 없다면) i가 MAX값(10억) 보다 작다면 탐색을 진행한다. 
	   (i는 *, +, -, /를 처리한 값들)
	   
	   이 값들을 처리하면서 찾고자 하는 값이 나온다면 바로 출력해주고 종료
	   만약 반복문이 종료될 때까지 값을 찾지 못한다면 -1을 출력해준다.

	   연산자 우선순위를 지켜야 하기 때문에 
	   * + - / 순서대로 큐에 넣어준다.
*/
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

long long s, t;
long long INF = 1000000000;
queue<pair<long long, string>> q;
unordered_map<long long, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	m[s] = 1;
	q.push({ s, "" });
	while (!q.empty()) {
		long long num = q.front().first; // long long... -> int로 둬서 계속 틀린 부분
		string s = q.front().second;
		q.pop();
		if (num == t) {
			cout << s;
			return 0;
		}
		if (m[num * num] == 0 && num * num <= INF) {
			m[num * num] = 1;
			q.push({ num * num, s + '*' });
		}
		if (m[num + num] == 0 && num + num <= INF) {
			m[num + num] = 1;
			q.push({ num + num, s + '+' });
		}
		if (m[num - num] == 0 && num - num <= INF) {
			m[num - num] = 1;
			q.push({ num - num, s + '-' });
		}
		if (num != 0 && m[num / num] == 0 && num / num <= INF) {
			m[num / num] = 1;
			q.push({ num / num, s + '/' });
		}
	}

	cout << -1;
}