#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

const int N = 5e6 + 5;
int c[N];

void update(int x) {
	while(x < N) ++c[x], x += x & -x;
}

int query(int x) {
	int ret = 0;
	while(x) ret += c[x], x -= x & -x;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> sum(n + 1);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') sum[i + 1] = sum[i] + 1;
		if(s[i] == '1') sum[i + 1] = sum[i] - 3;
	}

	i64 ans = 0;
	for(int i = 1; i <= n; ++i) {
		// int temp = query(sum[i] + n * 3 + 1);
		// cout << temp << endl;
		ans += query(sum[i] + 1e6 + 1) - query(sum[i] + 1e6) + query(sum[i] + 1e6 - 2);
		update(sum[i - 1] + 1e6);
	}

	cout << ans << '\n';

	return 0;
}
/*
 * (n0 + 1) // 3 > n1 || (n0 + 1) / 3 == n1
*/
