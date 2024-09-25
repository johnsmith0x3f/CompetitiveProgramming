#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

namespace SuffixArray {
	const int N = 300005;
	int n, w, sa[N], rk[N], ht[N], temp[N];
	string s;

	inline bool comp(const int &i, const int &j) {
		if(rk[i] != rk[j]) return rk[i] < rk[j];
		return (i+w <= n && j+w <= n) ? rk[i+w] < rk[j+w] : i > j;
	}

	inline void build() {
		n = s.length();

		for(int i = 0; i < n; ++i) sa[i] = i, rk[i] = s[i], ht[i] = temp[i] = 0;

		for(w = 1; w < n; w <<= 1) {
			sort(sa, sa+n, comp);
			for(int i = 1; i < n; ++i) temp[i] = temp[i-1] + comp(sa[i-1], sa[i]);
			for(int i = 0; i < n; ++i) rk[sa[i]] = temp[i];

			if(temp[n-1] == n-1) break;
		}

		int k = 0;
		for(int i = 0; i < n; ++i) {
			if(rk[i] == 0) continue;
			while(s[i+k] == s[sa[rk[i]-1]+k]) ++k;
			ht[rk[i]] = k;
			if(k) --k;
		}
	}
}

using namespace SuffixArray;

int main() {
	cin >> s;

	build();

	for(int i = 0; i < n; ++i) printf("%d%c", sa[i], " \n"[i == n-1]);
	for(int i = 0; i < n; ++i) printf("%d%c", ht[i], " \n"[i == n-1]);
	return 0;
}

