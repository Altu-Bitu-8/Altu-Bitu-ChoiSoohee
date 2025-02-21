#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ���� ���ϴ� �Լ� 
int numberSum(string& s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			sum += s[i] - '0';
		}
	}
	return sum;
}

bool compare(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	int sumA = numberSum(a);
	int sumB = numberSum(b);
	if (sumA != sumB) {
		return sumA < sumB;
	}

	return a < b;
}

int main() {
	// �Է� 
	int n;
	cin >> n;
	vector<string> guitar(n);
	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	// ���� 
	sort(guitar.begin(), guitar.end(), compare);

	// ��� 
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}
	
	return 0;
}