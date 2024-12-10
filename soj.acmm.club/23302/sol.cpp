#include <bits/stdc++.h>
using namespace std;

const string t = "SYSU";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0;
	for(int i = 0; i < n; ++i) ans += (s[i] != t[i % 4]);

	cout << ans << '\n';

	return 0;
}
