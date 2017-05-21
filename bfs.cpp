#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
	vector<int> v;
	v.push_back(1);
	cout << v[0] << endl;

	vector<int> v1(5, -1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	cout << v1[0] << " "  << v1[4] << endl;

	vector<string> v2(5, "yello");
	v2.pop_back();
	v2.pop_back();
	cout << v2[0] << v2[1] << v2[2] << v2[3] << v2[4]  << v2[5] << endl;
	cout << "size " << v2.size() << endl;

	vector<string> v3(v2);
	cout << v3[0] << v3[1] << v3[2] << v3[3] << v3[4]  << v3[5] << endl;

	cout << (v2[0] > v3[0]) << endl;
	cout << "size " << v3.size() << endl;

	return 0;
}