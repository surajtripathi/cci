#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void inorder(Node *head);
void preorder(Node *head);
void postorder(Node *head);

int main() {
	Node *head = (new Node);
	head->data = 1;
	head->left = (new Node);
	head->right = (new Node);
	head->left->data = 2;
	head->right->data = 3;
	head->left->left = (new Node);
	head->left->left->data = 4;
	head->left->right = (new Node);
	head->left->right->data = 5;
	head->right->left = (new Node);
	head->right->left->data = 6;
	head->right->right = (new Node);
	head->right->right->data = 7;
	
	inorder(head);
	cout << "\n";
	preorder(head);
	cout << "\n";
	postorder(head);
	return 0;
}

void inorder(Node *head) {
	if(head == NULL) return;
	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
	return;
}

void preorder(Node *head) {
	if(head==NULL) return;
	cout << head->data << " ";
	preorder(head->left);
	preorder(head->right);
}

void postorder(Node *head) {
	if(head == NULL) return;
	postorder(head->left);
	postorder(head->right);
	cout << head->data << " ";
}
