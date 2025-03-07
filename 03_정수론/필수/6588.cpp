#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;

// 소수를 미리 계산 
void find(vector<bool>& prime) {
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

// 골드바흐의 추측 검증 
void check(int n, vector<bool>& prime) {
	for (int a = 3; a <= n / 2; a += 2) {
		int b = n - a;
		if (prime[a] && prime[b]) {
			cout << n << " = " << a << " + " << b << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<bool> prime(MAX + 1, true);
	find(prime);
	int n;
	while (cin >> n && n != 0) {
		check(n, prime);
	}
}