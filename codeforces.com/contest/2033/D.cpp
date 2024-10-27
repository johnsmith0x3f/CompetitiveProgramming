#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) cin >> a[i];

		i64 sum = 0;
		vector<int> f(n + 1, 0);
		map<i64, int> las; las[0] = 0;
		for(int i = 1; i <= n; ++i) {
			sum += a[i], f[i] = f[i - 1];
			if(las.find(sum) != las.end()) f[i] = max(f[i], f[las[sum]] + 1);
			las[sum] = i;
		}

		cout << f[n] << "\n";
	}

	return 0;
}
