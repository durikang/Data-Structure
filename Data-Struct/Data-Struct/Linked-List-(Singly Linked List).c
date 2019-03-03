#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *link;

}Node;


void InsertNode(Node **head, int data) {
	for (; *head != NULL; head = &(*head)->link);
	*head = (Node*)malloc(sizeof(Node));
	(*head)->data = data;
	(*head)->link = NULL;

}
int DisplayNode(Node *head) {
	for (; head != NULL; head = head->link)
	{
		printf("%d ", head->data);

	}printf("\n");

}

Node *SearchNode(Node*head, int data) {

	for (; head != NULL; head = head->link) {
		if (head->data == data)return head;


	}
	return NULL;

}

void AddRearNode(Node *head, int sData, int newdata) {
	Node *tmp;
	for (; head != NULL; head = head->link) {
		if (head->data == sData) {
			tmp = (Node*)malloc(sizeof(Node));
			tmp->data = newdata;
			tmp->link = head->link;
			head->link = tmp;
			return;
		
		}

	}

}

void AddFrontNode(Node **head, int sData, int newdata) {
	Node *tmp;
	for (; *head != NULL; head = &(*head)->link) {
		if ((*head)->data == sData) {
			tmp = (Node*)malloc(sizeof(Node));
			tmp->data = newdata;
			tmp->link = *head;
			*head = tmp;
			return;

		}

	}

}
//*head의 변경 가능성이 있음.
void DeleteNode(Node **head, int data) {
	Node* tmp;
	for (; *head != NULL; &(*head)->link) {
		if ((*head)->data == data) {
			tmp = (*head)->link;
			free(*head);
			*head = tmp;
			return;

		}

	}
}

void SortInsertNode(Node ** head, int data) {
	Node *tmp;
	for (; *head != NULL && (*head)->data < data; head = &(*head)->link);
	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->link = *head;
	*head = tmp;


}





void main() {
	Node *head = NULL;
	Node *searchNode;
	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);
	InsertNode(&head, 40);
	DisplayNode(head);

	searchNode = SearchNode(head, 30);

	if (searchNode == NULL) {
		printf("값을 찾을 수 없습니다.\n");
	}
	else {
		printf("%d 검색 완료\n", searchNode->data);
	}
	AddRearNode(head, 20, 7);
	DisplayNode(head);
	
	//오류 1. 20에 데이터를 삭제 할 경우 출력이 안됨.
	//sortInsertNode가 실행이 안됨.
	AddFrontNode(&head, 10, 7);
	DisplayNode(head);
	
	DeleteNode(&head, 20);
	DisplayNode(head);
	
	
	SortInsertNode(&head, 32);
	DisplayNode(head);


}