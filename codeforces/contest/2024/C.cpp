#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<pii> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

		sort(a.begin(), a.end(), [&](const pii &x, const pii &y) {
			if(min(x.first, x.second) != min(y.first, y.second)) return min(x.first, x.second) < min(y.first, y.second);
			return max(x.first, x.second) < max(y.first, y.second);
		});

		for(int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << " \n"[i == n - 1];
	}
	return 0;
}
