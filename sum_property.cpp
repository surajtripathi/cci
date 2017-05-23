#include <iostream>
#include <list>

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

/*              1
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

1 2 3 7 6 5 4 8 9 10 11 12 13 14 15 
92 38 54 29 25 21 17 8 9 10 11 12 13 14 15 
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

int spiral_traversal(node *tree) {
	// stack<node *> stac;
	// queue<node *> que;
	list<node *> stack1;
	list<node *> stack2;
	int insert_reverse = true;

	stack1.push_back(tree);

	/* Expected result
		1 2 3 7 6 5 4 8 9 10 11 12 13 14 15
	*/
	while(!stack1.empty() || !stack2.empty()) {
		if(insert_reverse) {
			if(!stack1.empty()) {
				node *temp = stack1.back();
				cout << temp->val << " ";
				stack1.pop_back();
				if(temp->right != NULL) stack2.push_back(temp->right);
				if(temp->left != NULL) stack2.push_back(temp->left);
			} else {
				insert_reverse = false;
			}
		} else {
			if(!stack2.empty()) {
				node *temp = stack2.back();
				cout << temp->val << " ";
				stack2.pop_back();
				if(temp->left != NULL) stack1.push_back(temp->left);
				if(temp->right != NULL) stack1.push_back(temp->right);
			} else {
				insert_reverse = true;
			}
		}
	}
	cout << endl;
	//cout << "1 2 3 7 6 5 4 8 9 10 11 12 13 14 15\n";
	return 0;
}

void increment_child(node *tree, int diff) {
	if(tree->left != NULL) {
		tree->left->val += diff;
		increment_child(tree->left, diff);
	} else if(tree->right != NULL) {
		tree->right->val += diff;
		increment_child(tree->right, diff);
	}
	return;
}

void doesSumPropertyHold(node *tree) {
	if((tree == NULL) || (tree->left == NULL && tree->right == NULL)) return;

	doesSumPropertyHold(tree->left);
	doesSumPropertyHold(tree->right);
	int left_val = 0, right_val = 0, diff = 0;

	if(tree->left != NULL) left_val = tree->left->val;
	if(tree->right != NULL) right_val = tree->right->val;

	diff = left_val + right_val - tree->val;

	if(diff > 0) {
		tree->val += diff;
	}

	if(diff < 0) {
		increment_child(tree, -diff);
	}
	return;
}
int main() {
	node *tree = init();
	spiral_traversal(tree);
	doesSumPropertyHold(tree);
	spiral_traversal(tree);
	return 0;
}