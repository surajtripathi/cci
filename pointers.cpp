#include <iostream>
#include <string>

using namespace std;

int check(char *a, char *b, int (*comp)(const char *, const char *)) {
	if(!(*comp)(a, b))
		return 1;
	return 0;
}

int main() {
	char s1[80], s2[80];
	int (*p)(const char*, const char*);
	p = strcmp;
	gets(s1);
	gets(s2);

	cout << check(s1, s2 ,p) << " " << (atoi("12345") == 12345) << endl;
	return 0;
}