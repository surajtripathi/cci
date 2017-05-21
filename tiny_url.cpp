#include<iostream>
#include<unordered_map>
#include<ctime>
#include<string>
using namespace std;

int id = 1000000000;
string get_short_url(string url);

int main() {
	unordered_map<string, string> tiny_map;
	tiny_map["hello"] = "hi";
	cout << tiny_map["hello"] << endl;
	tiny_map["a"] = "helllo";
	tiny_map["b"] = "kello";
	if(tiny_map.find("b") != tiny_map.end()) {
		cout << "b found and its value is " << tiny_map.find("b")->second <<endl;
	}
	char a = 'a';
	while(a<='z') {
	//	cout << (int)a++ << endl;
		a++;
	}
	char z = '0';
	while(z <= '9') {
	//	cout << (int)z++ << endl;
		z++;
	}
//	time_t t = time(0);
	//cout << "ctime " << t << endl;
	get_short_url("hello");
	get_short_url("hi");
	return 0;	
}

string get_short_url(string url) {
	string short_url = "";
	int temp = id++;
	while(temp > 0) {
		if(temp%62 <= 9) {
			short_url += (char)('0' + temp%62);
		} else if(temp%62 <= (9 + 26)) {
			short_url += (char)('a' + (temp%62 - 9));
		} else {
			short_url += (char)('A' + (temp%62 - 9 - 26));
		}
		temp /= 62;	
	}
	cout << "url generated : " << short_url << endl;
	return short_url;
}
