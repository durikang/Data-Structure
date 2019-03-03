#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct node {
	int data;
	struct node *link;

}Node;


void InsertNode(Node **head, int data) {
	Node *tmp = *head;
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	if (*head==NULL) {
		NewNode->link = NewNode;
		*head = NewNode;
	}
	else {
		for (; tmp->link != *head; tmp = tmp->link);
		NewNode->link = *head;
		tmp->link = NewNode;
	}
	
}
int DisplayNode(Node *head) {
	for (; head != NULL; head = head->link)
	{
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

	DisplayNode(head);



}