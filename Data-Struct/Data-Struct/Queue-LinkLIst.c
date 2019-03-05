#include <stdio.h>
#include <stdlib.h>


typedef struct queue {
	int data;
	struct queue*link;

}Queue;

int IsEmpty(Queue *cq) {
	if (cq==NULL)return 1;
	else return 0;

}

void Enqueue(Queue **front,Queue **rear, int data) {
	Queue *tmp =(Queue*)malloc(sizeof(Queue));
	tmp->data = data;
	tmp->link = NULL;
	
	if(*rear == NULL) {
		*front = tmp;
		*rear = tmp;
		return;
	}
	(*front)->link = tmp;
	(*front)= tmp;
	
}


int Dequeue(Queue **rear) {
	Queue *tmp = *rear;
	int data;

	if (IsEmpty(*rear)) {
		printf("Full!\n");
		return -1;
	}

	data = tmp->data;
	*rear = tmp->link;

	free(tmp);
	return data;


}

void main() {
	Queue *front;
	Queue *rear;
	front = NULL;
	rear = NULL;
	Enqueue(&front,&rear, 10);
	Enqueue(&front, &rear, 20);
	Enqueue(&front, &rear, 30);
	Enqueue(&front, &rear, 40);

	
	printf("%d\n",Dequeue(&rear));
	printf("%d\n",Dequeue(&rear));
	printf("%d\n",Dequeue(&rear));
	printf("%d\n",Dequeue(&rear));


}