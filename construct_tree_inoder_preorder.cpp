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

node* construct_tree_1(string &in, string &pre, int start, int end) {
	static int pos = 0;
	if(start > end) {
		return NULL;
	}
	int i, j, center_index = -1;
	char current_val = pre[pos++];
	node *current_node = new node(current_val, NULL, NULL);

	for (i = 0; i < in.length(); i++) {
		if(in[i] == current_val)
			center_index = i;
	}
	
	current_node->left = construct_tree_1(in, pre, start, center_index - 1);
	current_node->right = construct_tree_1(in, pre, center_index + 1, end);
	return current_node;
}


void inorder_traversal(node *head) {
	if(head == NULL) 
		return;
	inorder_traversal(head->left);
	cout << (head->val) << " ";
	inorder_traversal(head->right);
	return;
}

int main() {
	string inorder = "DBEAFC";
	string preorder = "ABDECF";

	node *root = NULL;
	if(inorder.length() > 0 && preorder.length() > 0 && inorder.length() == preorder.length()) {
		// root = new node('\0', NULL, NULL);
		root = construct_tree_1(inorder, preorder, 0, inorder.length() - 1);
	}

	inorder_traversal(root);
	return 0;
}