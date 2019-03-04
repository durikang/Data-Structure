#include <stdio.h>
#define SIZE 50

typedef struct stack {
	int StackArea[SIZE];
	int top;

}Stack;

void InitStack(Stack *st) {
	st->top = -1;

}
void Push(Stack *st, int data) {
	if (st->top >= SIZE-1)
		return;
	st->top++;
	st->StackArea[st->top] = data;
}

void Pop(Stack *st) {
	if (st->top < 0)
		return -1;
	return st->StackArea[st->top--];

}

void Display(Stack st) {

	for (int i = st.top; i >=0; i--) {
		printf("%5d ", st.StackArea[i]);
	}printf("\n");
	
}



void main() {
	Stack st; 
	InitStack(&st);
	Push(&st, 10);
	Push(&st, 20);
	Push(&st, 30);

	Display(st);
	Pop(&st);//30 Pop
	Display(st);//20 10 출력
	Pop(&st);//20 30 Pop
	Display(st);//10 출력

}