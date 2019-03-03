#include <stdio.h>


int InsertNode(int *data, int size, int newdata) {

	for (int i = 0; i<size; i++) {
		if (data[i] == NULL) {
			data[i] = newdata;
			return 0;
		}
		
	}
	return -1;
}

int DeleteNode(int *data, int size, int delete) {
	int i, j;
	for (int i = 0; i < size&&data[i] !=NULL; i++) {
		if (data[i] == delete) {
			for (j = i; j < size - 1; j++) {
				data[j] = data[j + 1];

			}
			data[j] = NULL;
			return 1;
		
		}



	}
	return -1;

}


void Display(int *data, int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}printf("\n");
	return 0;
}

int AddNode(int *data, int size, int sData, int newData) {
	//배열의 크기는 정해져 있음으로 조건식에서 데이터의 크기를 넘기면 안되는 것을 넣어 줘야 함.
	int i, j;

	for (i = 0; i < size&&i<data[size-1] ==NULL; i++) {
		if (data[i] == sData) {
			for (j = size - 1; j > i + 1; j--) {
				data[j] = data[j - 1];
			}
			data[j] = newData;
			return 1;
		}
	}
	return -1;

}


void main() {
	int data[5] = { NULL };
	int size = sizeof(data) / sizeof(int);
	
	InsertNode(data, size, 10);
	InsertNode(data, size, 20);
	InsertNode(data, size, 30);
	InsertNode(data, size, 40);
	InsertNode(data, size, 50);

	Display(data, size);

	DeleteNode(data, size, 10);
	
	Display(data, size);




}