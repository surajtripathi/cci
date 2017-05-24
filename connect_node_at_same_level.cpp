#include <iostream>
#include <queue>

using namespace std;

struct node {
	int val;
	node *left, *right, *next;
	node(int val, node *l, node *r) {
		this->val = val;
		this->left = l;
		this->right = r;
		this->next = NULL;
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
        2-->N           3-->N
       / \             / \
      /   \           /   \
     /     \         /     \
    4-->N   5-->N   6-->N   7-->N
   / \     / \     / \     / \
  /   \   /   \   /   \   /   \
 8     9 10   11 12   13 14   15
*/
node* init() {
	node *node15 = new node(15, NULL, NULL);
	node *node14 = new node(14, NULL, NULL);

	node *node13 = new node(13, NULL, node15);
	node *node12 = new node(12, node14, NULL);

	node *node11 = new node(11, NULL, node13);
	node *node10 = new node(10, node12, NULL);

	node *node9 = new node(9, NULL, node11);
	node *node8 = new node(8, node10, NULL);

	node *node7 = new node(7, NULL, node9);
	node *node6 = new node(6, NULL, NULL);
	node *node5 = new node(5, NULL, NULL);
	node *node4 = new node(4, node8, NULL);
	
	node *node3 = new node(3, node6, node7);
	node *node2 = new node(2, node4, node5);

	node *node1 = new node(1, node2, node3);

	return node1;
}

node* endOfLevelNode() {
	return NULL;
}

void withExtraSpace() {
	node *tree = init();
	queue<node *> Q;
	node *current_node, *next_node;
	Q.push(tree);
	Q.push(endOfLevelNode());
	while(!Q.empty()) {
		current_node = Q.front();
		Q.pop();
		if(current_node != NULL) {
			next_node = Q.front();
			current_node->next = next_node;
			if(current_node->left != NULL) Q.push(current_node->left);
			if(current_node->right != NULL) Q.push(current_node->right);
		} else if(!Q.empty()) {
			Q.push(endOfLevelNode());
		}
	}
	node *temp = tree;
	while(temp != NULL) {
		node *level = temp;
		while(level != NULL) {
			cout << level->val << " ";
			level = level->next;
		}
		temp = temp->left;
		cout << endl;
	}
	cout << endl;
}

void withoutExtraSpace() {
	node *tree = init();
	node *left_most_node = tree;
	while(left_most_node != NULL) {
		node *current_node = left_most_node;
		node *logical_left = NULL;
		node *logical_right = NULL;
		left_most_node = NULL;
		while(current_node != NULL) {
			if(current_node->left != NULL) {
				if(logical_left == NULL) {
					logical_left = current_node->left;
					left_most_node = logical_left;
				} else {
					logical_right = current_node->left;
					logical_left->next = logical_right;
					logical_left = logical_right;
					logical_right = NULL;
				}
			}
			if(current_node->right != NULL) {
				if(logical_left == NULL) {
					logical_left = current_node->right;
					left_most_node = logical_left;
				} else {
					logical_right = current_node->right;
					logical_left->next = logical_right;
					logical_left = logical_right;
					logical_right = NULL;
				}
			}
			current_node = current_node->next;
		}
	}

	node *temp = tree;
	while(temp != NULL) {
		node *level = temp;
		while(level != NULL) {
			cout << level->val << " ";
			level = level->next;
		}
		temp = temp->left;
		cout << endl;
	}
	cout << endl;
}

int main() {
	withExtraSpace();
	withoutExtraSpace();
}
