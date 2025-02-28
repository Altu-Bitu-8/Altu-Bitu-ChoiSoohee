#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool compare(string s) {
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		char c = s.at(i);

		if (c == '(' || c == '[') {
			st.push(c);
		}
		else if (c == ')') {
			if (st.empty() || st.top() != '(') return false;
			st.pop();
		}
		else if (c == ']') {
			if (st.empty() || st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	string s;

	while (true) {
		getline(cin, s);

		if (s == ".") break;

		if (compare(s)) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}