#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i) cout << (i == n / 2);
		cout << "\n";
	}
	return 0;
}
