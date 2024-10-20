#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int a, b;
		cin >> a >> b;
		cout << (a >= b ? a : max(a + a - b, 0)) << "\n";
	}
	return 0;
}
