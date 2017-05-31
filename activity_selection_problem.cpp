#include <iostream>

using namespace std;

int main() {
	int start[] = {3, 1, 0, 5, 5, 8};
	int end[] = {4, 2, 6, 7, 9, 9};
	int i, j;
	int  n = 6;
	for (i = 0; i < n; i++) {
		for(j = i; j < (n - 1); j++) {
			if(end[j] < end[j+1]) {
				//do nothing
			} else if(end[j] > end[j+1]) {
				int temp_start = start[j];
				start[j] = start[j+1];
				start[j+1] = temp_start;
				int temp_end = end[j];
				end[j] = end[j+1];
				end[j+1] = temp_end;
			} else if(start[j] < start[j+1]) {
				int temp_start = start[j];
				start[j] = start[j+1];
				start[j+1] = temp_start;
				int temp_end = end[j];
				end[j] = end[j+1];
				end[j+1] = temp_end;
			} else {
				//do nothing
			}
		}
	}
	cout << "start: ";
	for(i = 0; i < n; i++) {
		cout << start[i] << " ";
	}
	cout << "\nend: ";
	for (i = 0; i < n; i++) {
		cout << end[i] << " ";
	}
	cout << endl;
	int count = 1;
	int e = end[0];
	for(i = 0; i < n - 1; i++) {
		if(e < start[i+1]) {
			count++;
			e = end[i + 1];
		}
	}
	cout << "total task : " << count << endl;
	return 0;
}
