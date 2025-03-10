#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	string result = "";
	int carry = 0;

	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int A = (i >= 0) ? a[i] - '0' : 0;
		int B = (j >= 0) ? b[j] - '0' : 0;

		int sum = A + B + carry;
		carry = sum / 10;
		result = char((sum % 10) + '0') + result;

		i--;
		j--;
	}
	cout << result << '\n';

	return 0;
}