#include <stdio.h>
#define SIZE 5

typedef struct queue {
	int queueArea[SIZE];
	int front;
	int rear;

}Queue;

void InitQueue(Queue *cq) {
	cq->front = 0;
	cq->rear = 0;
}

int IsEmpty(Queue *cq) {
	if (cq->front == cq->rear)return 1;
	else return 0;

}
int NextPosIdx(int pos) {
	if (pos == SIZE - 1)return 0;
	else return pos + 1;

}

void Enqueue(Queue *cq, int data) {
	if (cq->front == NextPosIdx(cq->rear)) {
		printf("오버 플로우\n");
		return;
	}


	cq->rear = NextPosIdx(cq->rear);
	cq->queueArea[cq->rear] = data;
	
}

int Dequeue(Queue *cq) {
	if (IsEmpty(cq)) {
		printf("언더 플로우\n");
		return -1;
	}
	cq->front = NextPosIdx(cq->front+1);
	return cq->queueArea[cq->front];

}



int main() {
	Queue cq;
	InitQueue(&cq);

	Enqueue(&cq, 10);
	Enqueue(&cq, 20);
	Enqueue(&cq, 30);
	Enqueue(&cq, 40);
	Enqueue(&cq, 50);

	printf("%d \n", Dequeue(&cq));
	printf("%d \n", Dequeue(&cq));
	printf("%d \n", Dequeue(&cq));
	printf("%d \n", Dequeue(&cq));
	printf("%d \n", Dequeue(&cq));

}