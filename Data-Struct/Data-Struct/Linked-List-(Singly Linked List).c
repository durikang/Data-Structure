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
//*head�� ���� ���ɼ��� ����.
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
		printf("���� ã�� �� �����ϴ�.\n");
	}
	else {
		printf("%d �˻� �Ϸ�\n", searchNode->data);
	}
	AddRearNode(head, 20, 7);
	DisplayNode(head);
	
	//���� 1. 20�� �����͸� ���� �� ��� ����� �ȵ�.
	//sortInsertNode�� ������ �ȵ�.
	AddFrontNode(&head, 10, 7);
	DisplayNode(head);
	
	DeleteNode(&head, 20);
	DisplayNode(head);
	
	
	SortInsertNode(&head, 32);
	DisplayNode(head);


}