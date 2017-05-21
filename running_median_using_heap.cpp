#include <iostream>
#include <iomanip>

using namespace std;

class Heap {
	protected:
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
				for(int i = 0; i<size ; i++) cout << items[i] << " ";
				cout << endl;
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

		int getSize() {
			return size;
		}

		virtual void heapifyDown() { };
		virtual void heapifyUp() { };
};

class MinHeap: public Heap {
	public:
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
};

class MaxHeap: public Heap {
	public:
		void heapifyDown() {
			int index = 0;
			while(hasLeftChild(index)) {
				int smallerChildIndex = items[getLeftChildIndex(index)];
				if(hasRightChild(index) && leftChild(index) < rightChild(index)) {
					smallerChildIndex = getRightChildIndex(index);
				}
				if(items[index] < items[smallerChildIndex]) {
					swap(index, smallerChildIndex);
				} else {
					break;
				}
				index = smallerChildIndex;
			}
		}

		void heapifyUp() {
			int index = size - 1;
			while(hasParent(index) && parent(index) < items[index]) {
				swap(getParentIndex(index), index);
				index = getParentIndex(index);
			}
		}
};

int heapSizeDiff(MinHeap &heap_one, MaxHeap &heap_two) {
	int heap_one_size = heap_one.getSize();
	int heap_two_size = heap_two.getSize();
	if(heap_one_size == heap_two_size) return 0;
	return heap_one_size > heap_two_size ? 1 : -1;
}

float average(int a, int b) {
	return (a + b)/2.0;
}
float getMedian(float m, int current_number, MinHeap &min_h, MaxHeap &max_h) {
	int val = heapSizeDiff(min_h, max_h);
	switch(val) {
		case 0:
			if(m < current_number) {
				min_h.add(current_number);
				return min_h.peek();
			} else {
				max_h.add(current_number);
				return max_h.peek();
			}
			break;
		case 1:
			if(m < current_number) {
				max_h.add(min_h.poll());
				min_h.add(current_number);
			} else {
				max_h.add(current_number);
			}
			return average(min_h.peek(), max_h.peek());
			break;
		case -1:
			if(m < current_number) {
				min_h.add(current_number);
			} else {
				min_h.add(max_h.poll());
				max_h.add(current_number);
			}
			return average(min_h.peek(), max_h.peek());
			break;
	}
}

int main() {
	int n;
	int current_number;
	float m = 0;

	MinHeap min_heap;
	MaxHeap max_heap;
	
	cin >> n;
	cout << fixed;
	cout << setprecision(1);
	for(int i = 0; i < n; i++) {
		cin >> current_number;
		m = getMedian(m, current_number, min_heap, max_heap);
		cout << m << endl;
	}
	
	return 0;
}