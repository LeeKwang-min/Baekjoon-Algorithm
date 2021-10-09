/*
작성자 : 이상수
일시 : 2021.01.30
제목 : 절댓값 힙 - 11286
풀이 : 일반적으로 우선순위 큐를 선언해서 처리하는 건 똑같지만,
       greater나 less가 아니라 개인이 선언한 비교를 바탕으로 진행되어야 하기 때문에
	   따로 선언을 해주어야 한다.

	   일반 sort등의 함수와는 달리 
	   우선순위 큐의 비교 부분에는 구조체가 들어가야 한다.
	   그 선언 방식은 아래 cmp와 같으며
	   operator() (매개 변수) 와 같이 선언해야 한다.
	   이 점 유의하고 기억 해두자.
제한사항 :
*/
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		int c, d;
		c = a;
		d = b;
		if (a < 0) c = a * (-1);
		if (b < 0) d = b * (-1);
		
		if (c == d) {
			return a > b;
		}

		return c > d;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, cmp> pq;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(a);
		}
	}
}


/*
	우선순위 큐 비교문 선언 방법
	struct cmp{
		bool operator() (int a, int b){
			return a < b;
		}
	};

	와 같다
	cmp 부분은 사용자 지정 이름으로 자유이며

	operator()의 경우 구조체가 가지는 연산과 같은 의미이다.

	operator() (매개변수) 임을 기억하자.
*/