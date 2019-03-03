#include <stdio.h>


typedef struct node {
	int data;
	struct node *Rlink;
	struct node *Llink;


}Node;

void InsertHeadNode(Node **head,Node **tail, int data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	
		tmp->data = data;
		tmp->Rlink = *head;
		tmp->Llink = NULL;
		if (*tail == NULL)*tail = tmp;
		else(*head)->Llink = tmp;
		*head = tmp;
	
}

void InsertTailNode(Node **head, Node **tail,int data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->Rlink = NULL;
	tmp->Llink = *tail;
	if (*head == NULL)*head = tmp;
	else(*tail)->Rlink = tmp;
	*tail = tmp;

}

void ForwardDisplayNode(Node*head) {
	for (; head != NULL; head = head->Rlink)
		printf("%d ", head->data);
	printf("\n");

}

void ReverseDisplayNode(Node*tail) {
	for (; tail != NULL; tail = tail->Llink)
		printf("%d ", tail->data);
	printf("\n");

}


Node *ForwardSearch(Node *head, int data) {
	for (; head != NULL; head = head->Rlink)
		if (head->data == data)return head;
		return NULL;
	
}

Node *ReverseSearch(Node *tail, int data) {
	for (; tail != NULL; tail = tail->Llink)
		if (tail->data == data)return tail;
		return NULL;

}

void ForwardSortInsert(Node **head, Node **tail, int data) {

	Node *tmp;
	for (; *head != NULL && (*head)->data < data; head = &(*head)->Rlink);
	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->Rlink = *head;
	if (*head == NULL) {
		tmp->Llink = *tail;
		*tail = tmp;
	}
	else {
		tmp->Llink = (*head)->Llink;
		(*head)->Llink = tmp;
	}
	*head = tmp;


}

void ForwardDeleteNode(Node **head, Node **tail, int data) {
	Node *tmp;
	for (; head != NULL; head = &(*head)->Rlink) {
		if ((*head)->data == data) {
			tmp = *head;
			*head = tmp->Rlink;
			if (tmp->Rlink == NULL)*tail = tmp->Llink;
			else tmp->Rlink->Llink = tmp->Llink;
			free(tmp);
			return;
		}

	}


}



void main() {
	Node *head=NULL;
	Node *tail = NULL;
	Node *searchNode;
	//InitNode(&head);

	InsertHeadNode(&head, &tail, 10);
	InsertHeadNode(&head, &tail, 20);
	InsertHeadNode(&head, &tail, 30);
	InsertHeadNode(&head, &tail, 40);



	InsertTailNode(&head, &tail, 1);
	InsertTailNode(&head, &tail, 2);
	InsertTailNode(&head, &tail, 3);
	InsertTailNode(&head, &tail, 4);

	ForwardDisplayNode(head);
	ReverseDisplayNode(tail);

	searchNode = ForwardSearch(head, 20);
	if (searchNode == NULL)
		printf("값을 찾을 수 없습니다.\n");
	else
		printf("%d 값 검색 완료\n", searchNode->data);
	searchNode = ReverseSearch(tail, 3);
	if (searchNode == NULL)
		printf("값을 찾을 수 없습니다.\n");
	else
		printf("%d 값 검색 완료\n", searchNode->data);

	ForwardSortInsert(&head, &tail, 1);
	ForwardDisplayNode(head);
	ReverseDisplayNode(tail);

	ForwardSortInsert(&head, &tail, 105);
	ForwardDisplayNode(head);
	ReverseDisplayNode(tail);

	printf("30삭제\n");
	ForwardDeleteNode(&head, &tail, 30);
	ForwardDisplayNode(head);
	ReverseDisplayNode(tail);

}