#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

const int N = 5e6 + 5;
int c[N];

struct FenwickTree {
	std::vector<int> tree;

	FenwickTree(int s) {
		tree.resize(s + 1, 0);
	}

	void update(int i, int v) {
		while(i < tree.size()) {
			tree[i] += v;
			i += i & -i;
		}
	}

	int query(int i) {
		int sum = 0;
		while(i > 0) {
			sum += tree[i];
			i -= i & -i;
		}
		return sum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> sum(n + 1); sum[0] = n * 3;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') sum[i + 1] = sum[i] + 1;
		if(s[i] == '1') sum[i + 1] = sum[i] - 3;
	}

	i64 ans = 0;
	FenwickTree t(n * 4 + 1);

	for(int i = 1; i <= n; ++i) {
		ans += t.query(sum[i] + 1) - t.query(sum[i]) + t.query(sum[i] - 2);
		t.update(sum[i - 1], 1);
	}

	cout << ans << '\n';

	return 0;
}
