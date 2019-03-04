#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//2. 이중 연결 리스트의 처음과 끝을 서로 이으면 이중 원형 연결 리스트를 만들 수 있음

typedef struct node {
	int data;
	struct node * lLink;
	struct node * rLink;
}Node;

void InsertNode(Node ** head, int data) {
	Node * tmp = *head;
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	if (*head == NULL) {
		newNode->lLink = newNode;
		newNode->rLink = newNode;
		*head = newNode;
	}
	else {
		for (; tmp->rLink != *head; tmp = tmp->rLink);
		newNode->rLink = *head;
		newNode->lLink = (*head)->lLink;
		tmp->rLink = newNode;
		(*head)->lLink = newNode;
	}
}

void ForwardDisplay(Node *head) {
	for (; head != NULL; head = head->rLink) {
		printf("%d ", head->data);
		Sleep(200);
	}
}

void ReverseDisplay(Node *head) {
	for (; head != NULL; head = head->lLink) {
		printf("%d ", head->data);
		Sleep(200);
	}
}

int main() {

	Node * head = NULL;

	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);
	InsertNode(&head, 40);
	InsertNode(&head, 50);

	//ForwardDisplay(head);
	ReverseDisplay(head);
	return 0;
}