/*
작성자 : 이상수
일시 : 2021.04.23
제목 : 트리 순회 - 1991
풀이 : 전위(pre), 중위(in), 후위(post) 순회(order)를 구현하는 문제
       트리 순회를 익히고 나서 바로 풀어본 문제이다.
	   문제를 처음 배울 때 직접 입력을 넣어주고 처리하는 방식을 사용했는데
	   헷갈리는 부분이 많았다.

	   해맨 부분
	   1. 배울 때에는 typedef struct를 사용하였으나 풀이에서는 그냥 struct로 사용
	   2. 동적할당 이야기가 많이 나와서 헷갈렸다.
	   3. 입력을 어떻게 받아야 하는지 몰랐다.

	   해결 방식
	   1. C에서 사용하던 typedef 방식이 C++로 넘어오면서 그냥 사용으로도 가능하게
	      바뀌었다고 한다. 하지만, C와의 호환을 위해서는 전자 처리가 올바르다.
		  (코딩 테스트에서는 빠른 처리를 우선적으로 보자)
	   2. 나의 풀이는 구조체 배열을 통해 최대 크기를 받아와서 처리하였으나,
	      크기에 맞는 메모리 낭비가 없는 처리르 위해서는 동적할당이 올바르다.
		  ( node *tree - 선언한 구조체 포인터(배열) 생성)
		  ( tree = (node)malloc(sizeof(node) * n) - 크기 n에 맞는 배열 생성 )
	   3. 배열의 쓰임 -> tree[i] => i노드의 값과 좌측 우측
*/
#include<iostream>

using namespace std;

struct node {
	char data;
	node* leftChild;
	node* rightChild;
};

struct node tree[28];

void preorder(node* ptr) {
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(node* ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

void postorder(node* ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		tree[i].data = i;
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
	}

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].data = a;
		if (b != '.') tree[a - 'A'].leftChild = &tree[b - 'A'];
		if (c != '.') tree[a - 'A'].rightChild = &tree[c - 'A'];
	}

	preorder(&tree[0]);
	cout << '\n';
	inorder(&tree[0]);
	cout << '\n';
	postorder(&tree[0]);
}