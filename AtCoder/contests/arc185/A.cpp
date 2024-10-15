#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tt;
	cin >> tt;
	while(tt--) {
		int n, m;
		cin >> n >> m;

		int x = 1ll * n * (n + 1) % m;
		cout << (x < 1 || x > n ? "Alice" : "Bob" ) << "\n";
	}
}
