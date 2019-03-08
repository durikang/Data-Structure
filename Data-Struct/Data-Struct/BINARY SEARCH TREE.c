#include <stdio.h>
#include <stdlib.h>



typedef struct tree {
	struct tree*left;
	int data;
	struct tree*right;
}Tree;

void InsertNode(Tree **root, int data) {

	if (*root == NULL) {
		*root = (Tree*)malloc(sizeof(Tree));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;

	}
	else if ((*root)->data <= data)InsertNode(&(*root)->right,data);
	else if ((*root)->data > data)InsertNode(&(*root)->left, data);

}

void DeleteNode(Tree **root, int data) {
	Tree *tmp =NULL;
	if (*root != NULL) {
		if ((*root)->data == data) {
			if ((*root)->left && (*root)->right) {
				for (tmp = (*root)->right; tmp->left != NULL; tmp = tmp->left);
				(*root)->data = tmp->data;
				DeleteNode(&(*root)->right, tmp->data);
				return;

			}
			else if ((*root)->left)
				tmp = (*root)->left;
			else if ((*root)->right)
				tmp = (*root)->right;
			free(*root);
			*root = tmp;

		}
		else if ((*root)->data > data) {
			DeleteNode(&(*root)->left, data);
		}
		else if ((*root)->data <= data) {
			DeleteNode(&(*root)->right, data);
		}


	}
	

}

void PreOrder(Tree *root) {//ÀüÀ§ Å½»ö
	if (root != NULL) {
		printf("%5d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);

	}
}
void InOrder(Tree *root) {//ÁßÀ§ Å½»ö
	if (root != NULL) {
		PreOrder(root->left);
		printf("%5d", root->data);
		PreOrder(root->right);

	}
}
void PostOrder(Tree *root) {//ÈÄÀ§ Å½»ö
	if (root != NULL) {
		PreOrder(root->left);
		printf("%5d", root->data);
		PreOrder(root->right);

	}
}

void main() {
	Tree *root = NULL;
	
	InsertNode(&root, 10);
	InsertNode(&root, 5);
	InsertNode(&root, 20);
	InsertNode(&root, 15);

	DeleteNode(&root, 10);


}
