#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct node {
	int data;
	struct node *Rlink;
	struct node *Llink;


}Node;

void InsertNode(Node **head, int data) {
	Node *tmp =*head;
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	if (*head == NULL) {
		NewNode->Llink = NewNode;
		NewNode->Rlink = NewNode;
		*head = NewNode;
	}
	else {
		for (; tmp->Rlink != *head; tmp = tmp->Rlink);
		NewNode->Rlink = *head;
		NewNode->Llink = (*head)->Llink;
		tmp->Rlink = NewNode;
		(*head)->Llink = NewNode;

	}
}


void ForwardDisplayNode(Node*head) {
	for (; head != NULL; head = head->Rlink){
		printf("%d ", head->data);
		Sleep(200);
	}
	
}

void ReverseDisplayNode(Node*head) {
	for (; head != NULL; head = head->Llink){
		printf("%d ", head->data);
		Sleep(200);
	}
	
}




void main() {
	Node *head = NULL;
	
	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);
	InsertNode(&head, 40);


	//ForwardDisplayNode(head);
	ReverseDisplayNode(head);


}