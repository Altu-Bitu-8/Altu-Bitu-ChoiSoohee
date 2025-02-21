#include <iostream>
#include <set> 
using namespace std;

int main() {
	string s;
	cin >> s;

	set<string> sub;

	for (int i = 0; i < s.length(); i++) {
		for (int j = 1; j <= s.length() - i; j++) {
			sub.insert(s.substr(i, j));
		}
	}

	cout << sub.size() << endl;
	return 0;
}