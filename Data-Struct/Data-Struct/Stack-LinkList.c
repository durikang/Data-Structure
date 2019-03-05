#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
	int data;
	struct stack*link;
}Stack;

void InitStack(Stack **top) {
	*top = NULL;

}

void push(Stack **top, int data) {
	Stack *tmp = *top;
	*top= (Stack*)malloc(sizeof(Stack));
	(*top)->data = data;
	(*top)->link = tmp;

}
Stack Pop(Stack **top) {
	Stack tmp = { NULL };
	if (*top != NULL) {
		tmp = **top;
		free(*top);
		*top = tmp.link;

	}return tmp;
}



void main() {
	Stack *top;
	InitStack(&top);
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("pop : %d\n",Pop(&top).data);

}