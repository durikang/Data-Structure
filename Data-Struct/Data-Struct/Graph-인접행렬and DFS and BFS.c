#include <stdio.h>
#include <stdlib.h>


typedef struct graph {
	int vertexCount;
	int *vertex;
	int **matrix;
	int *visited;
}Graph;
typedef struct stack {
	int data;
	struct stack *link;
}Stack;
typedef struct queue {
	int data;
	struct stack *link;
}Queue;

void Enqueue(Queue **front, Queue **rear, int data) {
	Queue*tmp = (Queue*)malloc(sizeof(Queue));
	tmp->data = data;
	tmp->link = NULL;
	if (*front == NULL)*front = tmp;
	else
		(*rear)->link = tmp;
	*rear = tmp;
}

Queue Dequeue(Queue **front, Queue**rear) {
	Queue tmp = { NULL };
	if (*front == NULL)
		return tmp;
	tmp = **front;
	free(*front);
	*front = tmp.link;
	if (*front == NULL) {
		*rear = NULL;
	}
	return tmp;
}

void InitQueue(Queue**front, Queue**rear) {
	*front = NULL;
	*rear = NULL;
}

int IsEmptyQ(Queue**front, Queue**rear) {
	if (front == NULL && rear == NULL)return 1;
	else return 0;
}


int InitStack(Stack **top) {
	*top = NULL;
}

void Push(Stack **top, int data) {
	Stack* tmp = *top;
	*top = (Stack*)malloc(sizeof(Stack));
	(*top)->data = data;
	(*top)->link = tmp;

}

Stack Pop(Stack **top) {
	Stack tmp = { NULL };
	if (*top != NULL) {
		tmp = **top;
		free(*top);
		*top = tmp.link;
	}

	return tmp;
}

int IsEmpty(Stack*top) {
	if (top == NULL)return 1;
	else return 0;
}

enum {
	병점=1,
	수원,
	강남,
	화성,
	봉담,
	오산

};


Graph *MakeGraph(int vertexCount) {
	Graph *g;
	g= (Graph*)malloc(sizeof(Graph));
	g->vertexCount = vertexCount;
	g->vertex = (int*)malloc(sizeof(int)*g->vertexCount);
	g->visited = (int*)malloc(sizeof(int)*g->vertexCount);
	g->matrix = (int**)malloc(sizeof(int)*g->vertexCount);
	for (int i = 0; i < vertexCount; i++) {
		g->vertex[i] = 0;
		g->visited[i] = 0;
		g->matrix[i] = (int*)malloc(sizeof(int)*g->vertexCount);
		for (int j = 0; j < g->vertexCount; j++) {
			g->matrix[i][j] = 0;

		}

	}
	return g;
}
void AddVertex(Graph* g, int vertex) {
	for (int i = 0; i < g->vertexCount&& g->vertex[i] !=vertex; i++) {
		if (g->vertex[i] == 0) {
			g->vertex[i] = vertex;
			return 0;
		}

	}
	return -1;
}


void AddEdge(Graph*g, int startvertex, int endvertex) {
	int i, j;
	AddVertex(g, startvertex);
	AddVertex(g, endvertex);

	for (i = 0; i < g->vertexCount&&g->vertex[i] != startvertex; i++);
	for (j = 0; j < g->vertexCount&&g->vertex[j] != endvertex; j++);
	g->matrix[i][j] = 1;
	g->matrix[j][i] = 1;

}


void DisplayGraph(Graph*g) {
	printf("\t");
	for (int i = 0; i < g->vertexCount; i++) {
		
		PrintVertex(g->vertex[i]);
	}
	printf("\n");
	for (int i = 0; i < g->vertexCount; i++) {
		PrintVertex(g->vertex[i]);
		for (int j = 0; j < g->vertexCount; j++) {
			printf("%5d", g->matrix[i][j]);

		}printf("\n");
	}
}




int PrintVertex(int vertex) {
	switch (vertex)
	{
	case 1: printf("병점 "); break;
	case 2: printf("수원 "); break;
	case 3: printf("강남 "); break;
	case 4: printf("화성 "); break;
	case 5: printf("봉담 "); break;
	case 6: printf("오산 "); break;
	}

}
/////////////재귀/////////////////////
/*
void DFS(Graph* g, int StartVertex) {
	g->visited[StartVertex - 1] = 1;
	PrintVertex(StartVertex);

	for (int i = 0; i < g->vertexCount; i++) {
		if (g->matrix[StartVertex - 1][i] == 1 && g->visited[i] == 0) {
			DFS(g, i + 1);
		}
	}

}
*/
/////////////스택/////////////////////
 void DFS(Graph * g, int vertex) {
	int i;
	Stack * top;
	InitStack(&top);

	g->visited[vertex - 1] = 1;
	PrintVertex(vertex);
	do {
		for (i = 0; i < g->vertexCount; i++) {
			if (g->matrix[vertex - 1][i] == 1 && g->visited[i] == 0) {
				Push(&top, vertex);
				g->visited[i] = 1;
				PrintVertex(i + 1);
				vertex = i + 1;
				break;
			}
		}
		if (i == g->vertexCount) vertex = Pop(&top).data;

	} while (!IsEmpty(top));
	


}

 void BFS(Graph*g, int StartVertex) {
	 Queue *front;
	 Queue *rear;
	 InitQueue(&front, &rear);

	 int i;

	 PrintVertex(StartVertex);
	 g->visited[StartVertex - 1] = 1;
	 Enqueue(&front, &rear, StartVertex);

	 do {

		 StartVertex = Dequeue(&front, &rear).data;
		 for (i = 0; i < g->vertexCount; i++) {
			 if (g->matrix[StartVertex - 1][i] == 1 && g->visited[i] == 0) {

				 g->visited[i] = 1;
				 PrintVertex(i + 1);
				 Enqueue(&front, &rear, i+1);
			 }


		 }
	 } while (!IsEmptyQ(front, rear));
	 memset(g->visited, 0, sizeof(int)*g->vertexCount);
 }



void main() {
	Graph *g;
	g = MakeGraph(6);

	AddVertex(g, 1);
	AddVertex(g, 2);
	AddVertex(g, 3);
	AddVertex(g, 4);
	AddVertex(g, 5);
	AddVertex(g, 6);
	
	DisplayGraph(g);
	printf("\n");

	AddEdge(g, 1, 2);
	AddEdge(g, 1, 4);
	AddEdge(g, 2, 5);
	AddEdge(g, 2, 3);
	AddEdge(g, 3, 6);
	AddEdge(g, 4, 5);
	
	DisplayGraph(g);

	//DFS(g, 1);
	printf("\n");
	BFS(g, 1);
	

}