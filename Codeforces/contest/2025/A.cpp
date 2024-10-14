#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while(q--) {
		string s, t;
		cin >> s >> t;

		int i = 0;
		while(i < int(min(s.size(), t.size())) && s[i] == t[i]) ++i;
		cout << int(s.size() + t.size()) - max(i - 1, 0) << "\n";
	}

	return 0;
}
