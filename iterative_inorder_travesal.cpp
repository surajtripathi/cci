#include<iostream>
#include<stack>

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

node* init() {
	node *left_11 = new node(8, NULL, NULL);
	node *right_11 = new node(9, NULL, NULL);
	node *left_12 = new node(10, NULL, NULL);
	node *right_12 = new node(11, NULL, NULL);
	node *left_21 = new node(12, NULL, NULL);
	node *right_21 = new node(13, NULL, NULL);
	node *left_22 = new node(14, NULL, NULL);
	node *right_22 = new node(15, NULL, NULL);
	node *left_1 = new node(4, left_11, right_11);
	node *left_2 = new node(6, left_21, right_21);
	node *right_1 = new node(5, left_12, right_12);
	node *right_2 = new node(7, left_22, right_22);
	node *left = new node(2, left_1, right_1);
	node *right = new node(3, left_2, right_2);
	node *root = new node(1, left, right);
	return root;
}

int main() {
	node *tree = init();
	stack<node*> stac;

	node *current = tree;
	stac.push(current);
	node *temp = NULL;
	current = current->left;
	while(!stac.empty() || current != NULL) {
		while(current != NULL) {
			stac.push(current);
			current = current->left;
		}
		current = stac.top();
		cout << current->val << " ";
		stac.pop();
		current = current->right;
	}
	cout << "\n";
}
