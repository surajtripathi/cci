#include <iostream>
#include <string>

using namespace std;

struct node {
	char val;
	node *left, *right;
	node(char v, node *l, node *r) {
		this->val = v;
		this->left = l;
		this->right = r;
	}
};

void construct_tree(string &in, string &pre, node *current_node, int start, int end) {
	int i, j, center_index = -1;

	for(i = 0; i < pre.length(); i++) {
		for(j = start; j < end; j++) {
			if(in[i] == pre[j]) {
				center_index = j;
				break;
			}
		}
		if(center_index != -1) break;
	}
	current_node->val = in[center_index];

	if(start < center_index) {
		current_node->left = new node('\0', NULL, NULL);
		construct_tree(in, pre, current_node->left, start, center_index);
	}

	if((center_index + 1) < end) {
		current_node->right = new node('\0', NULL, NULL);
		construct_tree(in, pre, current_node->right, center_index + 1, end);
	}
	return;
}

void inorder_tra(node *head) {
	if(head == NULL) 
		return;
	inorder_tra(head->left);
	cout << (head->val) << " ";
	inorder_tra(head->right);
	return;
}

int main() {
	string inorder = "DBEAFC";
	string preorder = "ABDECF";

	node *root = NULL;
	if(inorder.length() > 0 && preorder.length() > 0 && inorder.length() == preorder.length()) {
		root = new node('\0', NULL, NULL);
		construct_tree(inorder, preorder, root, 0, inorder.length());
	}

	inorder_tra(root);
	return 0;
}