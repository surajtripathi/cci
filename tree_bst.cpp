#include <iostream>

using namespace std;

struct node {
	int data;
	node *left, *right;
};

class BST {
	node *root;

	node* newNode(int val);
	void inorder_helper(node *n);
	int size_helper(node *n);
	int max_depth_helper(node *n);
	void destroy_tree(node *n);

	public:
		BST() {
			root = NULL;
		}
		~BST() {
			cout << "destructor is called";
			destroy_tree();
		}
		void insert(int val);
		void inorder();
		int size();
		int max_depth();
		void destroy_tree();
		//node* search(int val);
};

int main() {
	BST bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(70);
	bst.insert(15);
	bst.insert(40);
	bst.insert(60);
	bst.insert(80);
	bst.insert(100);
	bst.insert(110);

	bst.inorder();
	cout << "size of the tree : " << bst.size() << "\n";
	cout << "max depth of tree : " << bst.max_depth() << "\n";
	return 0;
}

void BST::insert(int val) {
	if(root == NULL) {
		root = newNode(val);
	} else {
		node *n = root;
		while(n != NULL) {
			if(val > n->data) {
				if(n->right == NULL) {
					n->right = newNode(val);
					n = NULL;
				} else {
					n = n->right;
				}
			} else {
				if(n->left == NULL) {
					n->left = newNode(val);
					n = NULL;
				} else {
					n = n->left;
				}
			}
		}
	}
}

void BST::inorder() {
	node *n = root;
	inorder_helper(n);
	cout << "\n";
	return;
}

node* BST::newNode(int val) {
	node *n = new node;
	n->data = val;
	n->left = n->right = NULL;

	return n;
}

void BST::inorder_helper(node *n) {
	if(n == NULL) return;
	inorder_helper(n->left);
	cout << n->data << " ";
	inorder_helper(n->right);
	return;
}

int BST::size() {
	node *n = root;
	return size_helper(n);
}

int BST::size_helper(node *n) {
	if(n == NULL) return 0;
	return (1 + size_helper(n->left) + size_helper(n->right));
}

int BST::max_depth() {
	node *n = root;
	return max_depth_helper(n);
}

int BST::max_depth_helper(node *n) {
	if(n == NULL) return 0;
	int left_tree_max_depth = max_depth_helper(n->left);
	int right_tree_max_depth = max_depth_helper(n->right);
	return (1 + (left_tree_max_depth > right_tree_max_depth ? left_tree_max_depth : right_tree_max_depth));
}