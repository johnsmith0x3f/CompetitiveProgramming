#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> l(n), r(n);
	for(int i = 0; i < n; ++i) cin >> l[i] >> r[i];

	vector<int> id(n), ll = l, rr = r;
	iota(begin(id), end(id), 0);

	sort(begin(id), end(id), [&](const int &i, const int &j) {
		if(l[i] != l[j]) return l[i] < l[j];
		return r[i] > r[j];
	});

	set<int> sl;
	for(int i = 0; i < n; ++i) {
		auto it = sl.lower_bound(+r[id[i]]);
		if(it != sl.end()) rr[id[i]] = +(*it);
		
		sl.insert(+r[id[i]]);
	}

	sort(begin(id), end(id), [&](const int &i, const int &j) {
		if(r[i] != r[j]) return r[i] > r[j];
		return l[i] < l[j];
	});

	set<int> sr;
	for(int i = 0; i < n; ++i) {
		auto it = sr.lower_bound(-l[id[i]]);
		if(it != sr.end()) ll[id[i]] = -(*it);

		sr.insert(-l[id[i]]);
	}

	for(int i = 0; i + 1 < n; ++i) {
		if(l[id[i]] == l[id[i + 1]] && r[id[i]] == r[id[i + 1]]) {
			ll[id[i]] = ll[id[i + 1]] = l[id[i]];
			rr[id[i]] = rr[id[i + 1]] = r[id[i]];
		}
	}

	for(int i = 0; i < n; ++i) cout << rr[i] - r[i] + l[i] - ll[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
