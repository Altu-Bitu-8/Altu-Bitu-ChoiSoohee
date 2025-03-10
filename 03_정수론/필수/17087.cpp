#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int N, S, A, D;
	cin >> N >> S;

	cin >> A;
	D = abs(S - A);

	for (int i = 1; i < N; i++) {
		cin >> A;
		D = gcd(D, abs(S - A));
	}

	cout << D << "\n";
}