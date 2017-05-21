#include<iostream>

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

void inorder(node *root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
	return;
}

void mirror(node *root) {
	if(root == NULL) return;
	mirror(root->left);
	mirror(root->right);
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	return;
}

int size(node *root) {
	if(root == NULL) {
		return 0;
	}
	return (size(root->left) + 1 + size(root->right));
}

int main() {
	node *root = init();
	inorder(root);
	cout << endl;
	mirror(root);
	inorder(root);
	cout << endl;
	//cout << "size of the tree : " << size(root);
	cout << endl;
}