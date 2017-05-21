#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class MinHeap {
	private:
		int capacity = 100;
		int size = 0;
		
		int items[100];
	
		int getLeftChildIndex(int parent_index) { return (2*parent_index + 1); }
		int getRightChildIndex(int parent_index) { return (2*parent_index + 1); }
		int getParentIndex(int child_index) { return (child_index -1)/2; }

		int hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
		int hasRightChild(int index) { return getRightChildIndex(index) < size; }
		int hasParent(int index) { return getParentIndex(index) >= 0; }
	
		int leftChild(int index) { return items[getLeftChildIndex(index)]; }
		int rightChild(int index) { return items[getRightChildIndex(index)]; }
		int parent(int index) { return items[getParentIndex(index)]; }

		void heapifyDown() {
			int index = 0;
			while(hasLeftChild(index)) {
				int smallerChildIndex = items[getLeftChildIndex(index)];
				if(hasRightChild(index) && leftChild(index) > rightChild(index)) {
					smallerChildIndex = getRightChildIndex(index);
				}
				if(items[index] > items[smallerChildIndex]) {
					swap(index, smallerChildIndex);
				} else {
					break;
				}
				index = smallerChildIndex;
			}
		}

		void heapifyUp() {
			int index = size - 1;
			while(hasParent(index) && parent(index) > items[index]) {
				swap(getParentIndex(index), index);
				index = getParentIndex(index);
			}
		}

		void swap(int index_one, int index_two) {
			int temp = items[index_one];
			items[index_one] = items[index_two];
			items[index_two] = temp;
		}

		void ensureCapacity() {
			if(size == capacity) {
				//create bigger array and copy
			}
		}
	
	public:
		int peek(){
			if(size >= 0) {
				return items[0];
			}
			return -1;
		}
		int poll() {
			if(size == 0) return -1;
			int item = items[0];
			items[0] = items[size - 1];
			size--;
			heapifyDown();
			return item;
		}

		void add(int item) {
			ensureCapacity();
			items[size] = item;
			size++;
			heapifyUp();
		}
	
};

int main(){
	// int n;
	// cin >> n;
	// vector<int> a(n);
	// for(int a_i = 0;a_i < n;a_i++){
	// 	cin >> a[a_i];
	// }
	MinHeap min_heap;
	min_heap.add(17);
	cout << min_heap.peek() << endl;;
	min_heap.add(15);
	cout << min_heap.peek() << endl;
	min_heap.add(20);
	cout << min_heap.peek() << endl;
	min_heap.add(10);
	cout << min_heap.peek() << endl;
	return 0;
}