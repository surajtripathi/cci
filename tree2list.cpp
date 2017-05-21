#include <iostream>

using namespace std;

struct node {
	int val;
	node *left, *right;
	node(int v, node *l, node *r) {
		this->val = v;
		this->left = l;
		this->right = r;
	}
};
/*
                1
               / \
              /   \
             /     \
            /       \
           /         \
          /           \
         /             \
        2               3
       / \             / \
      /   \           /   \
     /     \         /     \
    4       5       6       7
   / \     / \     / \     / \
  /   \   /   \   /   \   /   \
 8     9 10   11 12   13 14   15

*/
node* init() {
	node *node15 = new node(15, NULL, NULL);
	node *node14 = new node(14, NULL, NULL);
	node *node13 = new node(13, NULL, NULL);
	node *node12 = new node(12, NULL, NULL);
	node *node11 = new node(11, NULL, NULL);
	node *node10 = new node(10, NULL, NULL);
	node *node9 = new node(9, NULL, NULL);
	node *node8 = new node(8, NULL, NULL);
	node *node7 = new node(7, node14, node15);
	node *node6 = new node(6, node12, node13);
	node *node5 = new node(5, node10, node11);
	node *node4 = new node(4, node8, node9);
	node *node3 = new node(3, node6, node7);
	node *node2 = new node(2, node4, node5);
	node *node1 = new node(1, node2, node3);

	return node1;
}

node* tree2list(node *root) {
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL) return root;
	
	node *left = tree2list(root->left);
	node *right = tree2list(root->right);
	
	while(left->right != NULL) left = left->right;
	while(right->left != NULL) right = right->left;
	
	left->right = root;
	root->left = left;
	right->left = root;
	root->right = right;
	return root;
}

int main() {
	node *root = init();
	node *list = tree2list(root);
	node *head = list;
	node *tail = list;

	while(head->left != NULL) head = head->left;
	while(tail->right != NULL) tail = tail->right;

	head->left = tail;
	tail->right = head;

	node *it = head;
	do {
		cout << it->val << " ";
		it = it->right;
	} while(it != head);
	cout << endl;
}