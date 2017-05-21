#include<iostream>

using namespace std;

struct node {
	int data;
	node *left, *right;
	node(int val, node *left, node *right) {
		cout << " data init " << val << endl;
		this->data = val;
		this->left = left;
		this->right = right;
	}
};

struct queue {
	node *item;
	queue *next;
	queue(node *n) {
		this->item = n;
		this->next = NULL;

	}
};

class Que {
	queue *head;
	queue *tail;
	
	public:
	Que(node *root) {
		cout << "hello" << endl;
		head =  new queue(root);
		tail = head;
	}
	void push(node *item) {
		if(head != NULL ) {
			head->next = new queue(item);
			head = head->next;
		} else {
			head = new queue(item);
			tail = head;
		}
	}
	queue* pop() {
		queue *temp = tail;
		if(tail == NULL)
			return NULL;
		// cout << "tail " << tail << " item " <<endl; 
		node *t = tail->item;
		tail = tail->next;
		if(tail == NULL) {
			head = NULL; 
		}
		return temp;
	}
};

int main() {
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
	
	node *null_node = NULL;
	Que Q(root);
	Q.push(null_node);
	cout << "inseted an item\n";
	queue *current = Q.pop();
	cout << "print level : \n";
	while(current != NULL) {
		if(current->item != NULL) {
			cout << current->item->data << " ";
			if(current->item->left != NULL) {
				Q.push(current->item->left);
			}
			if(current->item->right != NULL) {
				Q.push(current->item->right);
			}
			current = Q.pop();
		} else {
			cout << "\n";
			current = Q.pop();
			if(current != NULL)
				Q.push(null_node);
			//current = Q.pop();
		}
		//current = Q.pop();
	}
	cout << endl;
}
