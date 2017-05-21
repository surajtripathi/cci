#include <iostream>
#include <string>

std::string buffer;
using namespace std;

int main() {
	cout << "Lisp version 1.0.0" <<endl;
	cout << "press ctrl+c to exit" << endl;
	while(1) {
		cout << "lisp>> ";
		//cin >> buffer;

		getline(cin, buffer);
		cout << "you entered " << buffer << endl;
	}
	return 0;
}
