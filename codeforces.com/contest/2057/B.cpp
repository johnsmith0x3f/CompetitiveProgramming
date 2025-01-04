#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(begin(a), end(a));

	vector<int> nums;
	for(int i = 0, j = 1; i < n; i = j++) {
		while(j < n && a[j] == a[i]) ++j;
		nums.emplace_back(j - i);
	}
	sort(begin(nums), end(nums));

	if(k < nums[0]) {
		cout << nums.size() << '\n';
		return;
	}
	for(int i = 0; i < nums.size(); ++i) {
		if(k < nums[i]) {
			cout << nums.size() - i << '\n';
			return;
		}
		k -= nums[i];
	}
	cout << 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
