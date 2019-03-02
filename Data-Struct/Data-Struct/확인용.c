#include<stdio.h>
#include<stdlib.h>

//연결 리스트
typedef struct node {
	int data;
	struct node * link;
}Node;

void InsertNode(Node ** head, int data);
void DisplayNode(Node * head);
Node * SearchNode(Node * head, int data);
void AddRearNode(Node * head, int sData, int data);
void AddFrontNode(Node ** head, int sData, int data);
void DeleteNode(Node ** head, int data);
void SortInsertNode(Node ** head, int data);
Node * GetNodeFromRear(Node * head, int n);

int main() {
	Node * head = NULL;
	Node * searchNode;
	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);

	DisplayNode(head);

	searchNode = SearchNode(head, 30);
	if (searchNode == NULL)
		printf("값을 찾을 수 없습니다.\n");
	else
		printf("%d 검색 완료\n", searchNode->data);

	AddRearNode(head, 10, 15);
	DisplayNode(head);

	AddFrontNode(&head, 30, 25);
	DisplayNode(head);

	DeleteNode(&head, 10);
	DisplayNode(head);

	SortInsertNode(&head, 17);
	DisplayNode(head);
	SortInsertNode(&head, 27);
	DisplayNode(head);

	searchNode = GetNodeFromRear(head, 2);
	if (searchNode == NULL)
		printf("값을 찾을 수 없습니다.\n");
	else
		printf("%d 검색 완료\n", searchNode->data);

}

//*head가 NULL인 경우 *head의 값을 변경해 주어야 하기 때문에 이중 포인터로 매개변수 설정
void InsertNode(Node ** head, int data) {
	for (; *head != NULL; head = &(*head)->link);
	*head = (Node *)malloc(sizeof(Node));
	(*head)->data = data;
	(*head)->link = NULL;
}

//head의 값 변경 필요 없으므로 매개변수를 그냥 포인터로 설정
void DisplayNode(Node * head) {
	for (; head != NULL; head = head->link)
		printf("%d ", head->data);
	printf("\n");
}
//head의 값 변경 필요 없으므로 매개변수를 그냥 포인터로 설정
Node * SearchNode(Node * head, int data) {
	for (; head != NULL; head = head->link)
		if (head->data == data) return head;
	return NULL;
}

void AddRearNode(Node * head, int sData, int data) {
	Node * tmp;
	for (; head != NULL; head = head->link) {
		if (head->data == sData) {
			tmp = (Node *)malloc(sizeof(Node));
			tmp->data = data;
			tmp->link = head->link;
			head->link = tmp;
			return;
		}
	}
}
//*head의 값 변경 필요
void AddFrontNode(Node ** head, int sData, int data) {
	Node * tmp;
	for (; *head != NULL; head = &(*head)->link) {
		if ((*head)->data == sData) {
			tmp = (Node *)malloc(sizeof(Node));
			tmp->data = data;
			tmp->link = *head;
			*head = tmp;
			return;
		}
	}
}

//*head 변경 가능성 있음
void DeleteNode(Node ** head, int data) {
	Node * tmp;
	for (; *head != NULL; head = &(*head)->link) {
		if ((*head)->data == data) {
			tmp = (*head)->link;
			free(*head);
			*head = tmp;
			return;
		}
	}
}

void SortInsertNode(Node ** head, int data) {
	Node * tmp;
	for (; *head != NULL && (*head)->data < data; head = &(*head)->link);
	tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->link = *head;
	*head = tmp;
}

Node * GetNodeFromRear(Node * head, int n) {
	int cnt = 0, i;
	Node * tmp = head;

	for (; tmp != NULL; tmp = tmp->link, cnt++);
	if (cnt < n) return NULL;

	for (i = 0; cnt - n != i; head = head->link, i++);
	return head;
}