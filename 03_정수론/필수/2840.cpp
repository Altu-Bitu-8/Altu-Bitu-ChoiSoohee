#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<char> wheel(N, '?'); // 바퀴 초기화 
	set<char> used; // 중복 체크 
	int current = 0;

	for (int i = 0; i < K; i++) {
		int S;
		char C;
		cin >> S >> C;
		current = (current - S % N + N) % N;

		if (wheel[current] != '?' && wheel[current] != C) {
			cout << "!\n";
			return 0;
		}

		if (used.count(C) && wheel[current] != C) {
			cout << "!\n";
			return 0;
		}

		wheel[current] = C;
		used.insert(C);
	}

	for (int i = 0; i < N; i++) {
		cout << wheel[(current + i) % N];
	}
	cout << "\n";
	return 0;
}