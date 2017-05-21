#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
class DailyTemp {
	int temp;

	public:
		DailyTemp() { temp = 0; }
		DailyTemp(int x) { temp = x; }

		DailyTemp &operator=(int x) { temp = x; return *this; }

		double getTemp() { return temp; }
};

int main() {
	vector<DailyTemp> v(1);
	v[0] = DailyTemp(60 + rand()%30);
	cout << rand() << endl;
	cout << v[0].getTemp() << endl;

	v[0] = (int)v[0].getTemp() * 100;

	cout << rand() << endl;
	cout << v[0].getTemp() << endl;
	return 0;
}