#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, q;
		cin >> n >> q;

		vector<int> p(n + 1);
		for(int i = 1; i <= n; ++i) cin >> p[i];

		int mx = 0;
		set<int> ss;
		for(int i = 1; i <= n; ++i) {
			mx = max(mx, p[i]);
			if(mx == i) ss.insert(i);
		}

		string s;
		cin >> s;
		s = "~" + s;

		set<int> tt;
		for(int i = 1; i < n; ++i) {
			if(s[i] == 'L' && s[i + 1] == 'R') {
				if(ss.find(i) != ss.end()) ss.erase(i);
				else tt.insert(i);
			}
		}

		while(q--) {
			int k;
			cin >> k;

			if(s[k - 1] == 'L' && s[k] == 'R') {
				if(tt.find(k - 1) != tt.end()) tt.erase(k - 1);
				else ss.insert(k - 1);
			}
			if(s[k] == 'L' && s[k + 1] == 'R') {
				if(tt.find(k) != tt.end()) tt.erase(k);
				else ss.insert(k);
			}

			s[k] = (s[k] == 'L' ? 'R' : 'L');

			if(s[k - 1] == 'L' && s[k] == 'R') {
				if(ss.find(k - 1) != ss.end()) ss.erase(k - 1);
				else tt.insert(k - 1);
			}
			if(s[k] == 'L' && s[k + 1] == 'R') {
				if(ss.find(k) != ss.end()) ss.erase(k);
				else tt.insert(k);
			}

			puts(tt.empty() ? "YES" : "NO");
		}
	}
}
